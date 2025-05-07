#include <iostream>
#include <algorithm>
using namespace std;

bool checkWin(int table[9], int player);

struct TreeNode{
    TreeNode* pre = nullptr;
    TreeNode* next[9] = {nullptr};
    int table[9];

    TreeNode(){
        fill(begin(table), end(table), 0);
    }
};

TreeNode* dummyNode()
{
    TreeNode* newNode = new TreeNode();
    return newNode;
}

int tictactoe(TreeNode*& head, int move, int turn, int& win, int& loss, int& draw)
{
    if(checkWin(head->table, 1))
    {
        win++;
        return 1;
    }
    else if(checkWin(head->table, 2))
    {
        loss++;
        return 1;
    }
    else if(move >= 8)
    {
        draw++;
        return 1;
    }

    for(int i = 0; i < 9; i++)
    {
        if (head->table[i] != 0) continue;

        TreeNode* newNode = new TreeNode();
        copy(begin(head->table), end(head->table), begin(newNode->table));

        newNode->table[i] = turn;
        newNode->pre = head;
        head->next[i] = newNode;

        int nextTurn = (turn == 1) ? 2 : 1;
        tictactoe(head->next[i], move + 1, nextTurn, win, loss, draw);
    }

    return 0;
}

void delete_node(TreeNode *&head)
{
    if(!head) return;

    for(int i = 0; i < 9; i++)
    {
        if (head->next[i]) delete_node(head->next[i]);
    }

    delete head;
    head = nullptr;
}

bool checkWin(int table[9], int player)
{
    
    int win_patterns[8][3] = {
        {0, 1, 2}, // แถวบน
        {3, 4, 5}, // แถวกลาง
        {6, 7, 8}, // แถวล่าง    
        {0, 3, 6}, // คอลัมน์ซ้าย
        {1, 4, 7}, // คอลัมน์กลาง
        {2, 5, 8}, // คอลัมน์ขวา
        {0, 4, 8}, // ทแยงซ้ายบนมาขวาล่าง
        {2, 4, 6}  // ทแยงขวาบนมาซ้ายล่าง
    };

    for(int i = 0; i < 8; i++)
    {
        if(table[win_patterns[i][0]] == player &&
        table[win_patterns[i][1]] == player &&
        table[win_patterns[i][2]] == player)
            return true;
    }

    return false;
}

void printBoard(int table[9])
{
    for (int i = 0; i < 9; i++)
    {
        char mark;
        if (table[i] == 1) mark = 'X';
        else if (table[i] == 2) mark = 'O';
        else mark = '.';

        cout << mark;
        if ((i + 1) % 3 == 0)
            cout << endl;
        else
            cout << " | ";
    }
    cout << "---------" << endl;
}

void printAllBoards(TreeNode* node)
{
    if (!node) return;

    printBoard(node->table);

    for (int i = 0; i < 9; i++)
    {
        printAllBoards(node->next[i]);
    }
}


int main()
{
    TreeNode* node = nullptr;
    int num = 0, win = 0, loss = 0, draw = 0;

    node = dummyNode();
    tictactoe(node, num, 1, win, loss, draw);
    cout << "Win : " << win << " | Loss : " << loss << " | Draw : " << draw;

    delete_node(node);
    return 0;
}