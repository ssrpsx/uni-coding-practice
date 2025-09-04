#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x[3], y[3];
    int a[3], b[3];

    for(int i = 0; i < 3; i++)
    {
        std::cin >> a[i] >> b[i];
    }


    x[1] = a[0] + a[1] - a[2];
    x[0] = a[0]*2 - x[1];
    x[2] = a[2]*2 - x[0];


    y[1] = b[0] + b[1] - b[2];
    y[0] = b[0]*2 - y[1];
    y[2] = b[2]*2 - y[0];

    for(int i= 0; i < 3; i++){
        cout << x[i] << " " << y[i] <<endl;
    }
}