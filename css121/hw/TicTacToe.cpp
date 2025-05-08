    #include <iostream>
    #include <algorithm>
    #include <set>
    #include <vector>
    using namespace std;

    bool printed = false;
    bool checkWin(int table[9], int player);

    struct TreeNode{
        TreeNode* pre = nullptr;
        TreeNode* next[9] = {nullptr};
        int table[9];

        TreeNode() {
            fill(begin(table), end(table), 0);
        }
    };

    TreeNode* dummyNode(){
        return new TreeNode();
    }

    int tictactoe(TreeNode*& head, int move, int turn,
                int& win, int& loss,
                set<vector<int>>& xWinSet,
                set<vector<int>>& oWinSet)
    {
        if (checkWin(head->table, 1))
        {
            win++;
            xWinSet.insert(vector<int>(head->table, head->table + 9));

            // ผมเอาไว้เช็ค ตาแรกที่Xชนะ จากที่เก็บStateมา
            // if (!printed) 
            // {
            //     cout << "เส้นทางที่ X ชนะครั้งแรก:" << endl;
            //     TreeNode* cur = head;
            //     vector<TreeNode*> path;
        
            //     while (cur)
            //     {
            //         path.push_back(cur);
            //         cur = cur->pre;
            //     }
        
            //     reverse(path.begin(), path.end());
        
            //     for (size_t i = 0; i < path.size(); ++i) 
            //     {
            //         cout << "ตาที่ " << i + 1 << ":" << endl;
            //         for (int j = 0; j < 9; ++j) 
            //         {
            //             if (path[i]->table[j] == 1) cout << 'X';
            //             else if (path[i]->table[j] == 2) cout << 'O';
            //             else cout << '.';
        
            //             if ((j + 1) % 3 == 0) cout << endl;
            //         }
            //         cout << endl;
            //     }
        
            //     printed = true;
            // }

            return 1;
        }
        else if (checkWin(head->table, 2))
        {
            loss++;
            oWinSet.insert(vector<int>(head->table, head->table + 9));
            return 1;
        }
        else if(move >= 8) return 1;

        for (int i = 0; i < 9; i++) 
        {
            if (head->table[i] != 0) continue;

            TreeNode* newNode = new TreeNode();
            copy(begin(head->table), end(head->table), begin(newNode->table));

            newNode->table[i] = turn;
            newNode->pre = head;
            head->next[i] = newNode;

            int nextTurn = (turn == 1) ? 2 : 1;
            tictactoe(head->next[i], move + 1, nextTurn,
                    win, loss,
                    xWinSet, oWinSet);
        }

        return 0;
    }

    void delete_node(TreeNode*& head)
    {
        if (!head) return;

        for (int i = 0; i < 9; i++)
        {
            if (head->next[i]) delete_node(head->next[i]);
        }

        delete head;
        head = nullptr;
    }

    bool checkWin(int table[9], int player)
    {
        int win_patterns[8][3] = {
            {0, 1, 2}, // แนวนอน
            {3, 4, 5},
            {6, 7, 8},
            {0, 3, 6}, // แนวตั้ง
            {1, 4, 7},
            {2, 5, 8},
            {0, 4, 8}, // แนวทแยง
            {2, 4, 6}
        };

        for (int i = 0; i < 8; i++) 
        {
            if (table[win_patterns[i][0]] == player &&
                table[win_patterns[i][1]] == player &&
                table[win_patterns[i][2]] == player)
                {
                    return 1;
                }
        }

        return false;
    }

    void f_print(vector<int>& arr)
    {
        for (int i = 0; i < 9; ++i)
        {
            if (arr[i] == 1)
                cout << 'X';
            else if (arr[i] == 2)
                cout << 'O';
            else
                cout << '.';

            if ((i + 1) % 3 == 0) cout << endl;
        }
    }

    int main()
    {
        TreeNode* node = dummyNode();

        int win = 0, loss = 0;
        set<vector<int>> xWinSet, oWinSet;

        tictactoe(node, 0, 1, win, loss,
                xWinSet, oWinSet);

        cout << "จำนวนเส้นทางทั้งหมด :" << endl;
        cout << "จำนวนรูปแบบที่ X ชนะ (ไม่ซ้ำกัน): " << xWinSet.size() << endl;
        cout << "จำนวนรูปแบบที่ X ชนะ (ซ้ำกัน): " << win << endl;
        cout << "จำนวนรูปแบบที่ O ชนะ (ไม่ซ้ำกัน): " << oWinSet.size() << endl;
        cout << "จำนวนรูปแบบที่ O ชนะ (ซ้ำกัน): " << loss << endl;

        delete_node(node);
        return 0;
    }
