#include <bits/stdc++.h>
using namespace std;

string operator*(string &str, const int &count)
{
    string result = "";

    for (int i = 0; i < count; i++)
    {
        result += str;
    }

    return result;
}

/*
int main() {
    string a = "abs, ";

    cout << (a * 3) << endl;
}
*/