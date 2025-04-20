#include <iostream>
#include <iomanip>
#define n 14
using namespace std;

struct data
{
    int no;
    int A;
    int B;
    int C;
};

bool compare(data a, data b, char first, char second, char third)
{
    if(first == 'A')
    {
        if(a.A != b.A) return a.A > b.A;
    }
    else if (first == 'B')
    {
        if(a.B != b.B) return a.B > b.B;
    }
    else
    {
        if(a.C != b.C) return a.C > b.C;
    }
    
    if (second == 'A')
    {
        if(a.A != b.A) return a.A > b.A;
    }
    else if (second == 'B')
    {
        if(a.B != b.B) return a.B > b.B;
    }
    else
    {
        if(a.C != b.C) return a.C > b.C;
    }

    if (third == 'A')
    {
        if(a.A != b.A) return a.A > b.A;
    }
    else if (third == 'B')
    {
        if(a.B != b.B) return a.B > b.B;
    }
    else
    {
        if(a.C != b.C) return a.C > b.C;
    }

    return false; // ถ้าสามตัวเหมือนกัน ไม่ให้มันสลับ
}

void swap(int *a, int *b)
{
    int *temp;
    temp = a;
    a = b;
    b = temp;
}

void bubble_sort(data arr[], char first, char second, char third)
{
    int i, j;
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(compare(arr[j], arr[j + 1], first, second, third))
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main()
{
    data table[n] = 
    {
        {1, 1, 1, 4},
        {2, 3, 1, 1},
        {3, 4, 4, 4},
        {4, 2, 4, 4},
        {5, 3, 5, 3},
        {6, 4, 3, 3},
        {7, 1, 3, 3},
        {8, 2, 4, 3},
        {9, 3, 3, 5},
        {10, 1, 5, 3},
        {11, 1, 1, 4},
        {12, 4, 1, 1},
        {13, 5, 2, 3},
        {14, 3, 5, 2}
    };
    char head[3] = {'A', 'B', 'C'};
    char input[3];
    char temp;

    cout << "Select column Sorting ex. [A->B->C] : ";
    cin >> input[0] >> temp >> temp >> input[1] >> temp >> temp >> input[2];

    for(int i = 0; i < 3; i++)
        cout << input[i] << endl;

    cout << "  No\tA\tB\tC" << endl << "---------------------------" << endl;
    for(int i = 0; i < 14; i++)
    cout << "| " << table[i].no << "\t" << table[i].A << "\t" << table[i].B << "\t" << table[i].C << " |" <<endl;
    cout << "---------------------------" << endl << endl;
    
    bubble_sort(table, input[0], input[1], input[2]);
    cout << "  No\tA\tB\tC" << endl << "---------------------------" << endl;
    for(int i = 0; i < 14; i++)
        cout << "| " << table[i].no << "\t" << table[i].A << "\t" << table[i].B << "\t" << table[i].C << " |" <<endl;
    cout << "---------------------------" << endl;
    
    return 0;
}