#include <iostream>
#include <string>
#include <climits>
#include <iomanip>

using namespace std;

struct Node{
    string name;
    int score;
    Node *pre;
    Node *next;
};

Node *create_dummyHead()
{
    Node *newNode = new Node{"", 0, nullptr, nullptr};
    return newNode;
}

void f_printf(Node *head) // O(n) ฟังก์ชันนี้ทำการวนลูปผ่านโหนดทั้งหมดใน linked list เพื่อแสดงผลคะแนนของนักเรียน
// โดยไม่ข้ามโหนดไหนเลย ดังนั้นความซับซ้อนในการทำงานจะเป็น O(n)
{
    cout << "===== SCOREBOARD =====" << endl;
    int count = 1;
    Node *temp = head->next;

    while (temp != nullptr)
    {
        cout << count++ << ". ";
        if(count > 10)
            cout << left  << setw(13) << temp->name;
        else
            cout << left  << setw(14) << temp->name;
        cout << right << setw(5)  << temp->score << endl;

        temp = temp->next;
    }
    cout << "=======================" << endl;
}

// O(n) ฟังก์ชันนี้ทำการวนลูปผ่านโหนดทั้งหมดใน linked list เพื่อทำการลบโหนดทั้งหมด
void delete_node(Node *&head)
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

// O(n) ฟังก์ชันนี้ทำการวนลูปผ่านโหนดทั้งหมดใน linked list เพื่อทำการแทรกโหนดใหม่
void insert(Node *&head, Node *&tail, string name, int score, int max_size)
{
    Node *temp = head;
    Node *newNode = new Node{name, score, nullptr, nullptr};

    if(temp->next == nullptr)
    {
        temp->next = newNode;
        newNode->pre = temp;
        tail = newNode;
    }
    else
    {
        while (temp->next != nullptr && temp->next->score > score)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        newNode->pre = temp;
        if(temp->next != nullptr)
        {
            temp->next->pre = newNode;
        }
        temp->next = newNode;

        if(newNode->next == nullptr)
        {
            tail = newNode;
        }
    }

    int count = 0;
    Node *countTemp = head->next;
    while (countTemp != nullptr)
    {
        count++;
        countTemp = countTemp->next;
    }
    
    if(count > max_size)
    {
        Node *deleteNode = tail;
        tail = tail->pre;
        tail->next = nullptr;
        delete deleteNode;
    }
}

int main()
{
    int max_size = 10;
    Node *head = create_dummyHead();
    Node *tail = nullptr;
    
    cout << "Top 10 Rankings" << endl;
    insert(head, tail, "Alice", 95, max_size);
    insert(head, tail, "Bob", 80, max_size);
    insert(head, tail, "Charlie", 85, max_size);
    insert(head, tail, "David", 70, max_size);
    insert(head, tail, "Frank", 75, max_size);
    insert(head, tail, "Grace", 88, max_size);
    insert(head, tail, "Hank", 92, max_size);
    insert(head, tail, "Ivy", 78, max_size);
    insert(head, tail, "Jack", 85, max_size);
    insert(head, tail, "Karen", 89, max_size);
    f_printf(head);
    
    cout << "Added Eve with 90 Score" << endl;
    insert(head, tail, "Eve", 90, max_size);
    f_printf(head);

    delete_node(head);
    return 0;
}