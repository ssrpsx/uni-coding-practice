#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int value;
    int power;
    Node* next;
};

Node *createList() // Big-O(1)
{
    Node *headNode = new Node{0, INT_MIN, nullptr};
    return headNode;
}

void insert(Node *&head, int value, int power) // ดีสุด Big-O(1) กรณีแย่สุดต้องลูปทุกตัว Big-O(N)
{   
    Node *temp = head;
    Node *newNode = new Node{value, power, nullptr};

    while (temp->next != nullptr && temp->next->power > power)
    {
        temp = temp->next;
    }
    if(temp->next != nullptr && temp->next->power == power)
    {
        temp->next->value += value;
        delete newNode;
    }
    else
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void delete_list(Node *&head) // Big-O(N)
{
    Node *temp;
    while(head != nullptr)
    {
        temp = head;
        head = temp->next;
        delete temp;
    }
}

void f_print(Node *head) // Big-O(N)
{
    if(head->next == nullptr)
    {
        cout << "Polynomial is empty" << endl;
        return;
    }
    Node *temp = head->next;
    while (temp != nullptr)
    {
        cout << temp->value;
        if(temp->power != 0)
        {
            cout << "X^" << temp->power;
        }
        temp = temp->next;
        if(temp != nullptr) cout << " + ";
    }
    cout << endl;
}

void method_add(Node *&head1, Node *&head2) //กรณีแย่สุดคือ Big-O(M * N)
{
    Node *temp2 = head2->next;
    
    while (temp2 != nullptr) //Big-O(N)
    {
        Node *temp1 = head1;
        bool found = false;
        while (temp1 != nullptr) //Big-O(M)
        {
            if(temp1->power == temp2->power)
            {
                temp1->value += temp2->value;
                found = true;
                break;
            }
            temp1 = temp1->next;
        }
        if(!found)
        {
            insert(head1, temp2->value, temp2->power); //Big-O(M)
        }
        temp2 = temp2->next;
    }
}

void method_multiply(Node *&head1, Node *head2, Node *head3) //กรณีแย่สุดคือ Big-O(N * M * B)
{
    Node *temp2 = head2->next;
    
    while (temp2 != nullptr) // Big-O(N)
    {
        Node *temp3 = head3->next;
        while (temp3 != nullptr) // Big-O(M)
        {
            int value = temp2->value * temp3->value;
            int power = temp2->power + temp3->power;

            insert(head1, value, power);// Big-O(B)
            temp3 = temp3->next;
        }
        temp2 = temp2->next;
    }
}

int main() {
    Node *p[3]; //polynomial

    for(int i = 0; i < 3; i++)
        p[i] = createList();

    insert(p[0], 2, 5);
    insert(p[0], 4, 3);
    insert(p[0], 3, 2);
    insert(p[0], 5, 0);

    insert(p[1], 5, 0);
    insert(p[1], 3, 2);
    insert(p[1], 3, 1);

    cout << "Polynomial 1 : ";
    f_print(p[0]);
    cout << "Polynomial 2 : ";
    f_print(p[1]);

    method_multiply(p[2], p[1], p[0]);
    cout << "Polynomial using method_multiply(p1, p2) -> p3 : ";
    f_print(p[2]);
    
    method_add(p[0], p[1]);
    cout << "Polynomial using method_add : ";
    f_print(p[0]);
    
    for(int i = 0; i < 3; i++)
        delete_list(p[i]);
        
    return 0;
}