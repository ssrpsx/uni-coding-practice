#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string output;
    string temp;

    map<string, char> m;

    m["1"] = '\0';
    m["2"] = 'a';
    m["22"] = 'b';
    m["222"] = 'c';
    m["3"] = 'd';
    m["33"] = 'e';
    m["333"] = 'f';
    m["4"] = 'g';
    m["44"] = 'h';
    m["444"] = 'i';
    m["5"] = 'j';
    m["55"] = 'k';
    m["555"] = 'l';
    m["6"] = 'm';
    m["66"] = 'n';
    m["666"] = 'o';
    m["7"] = 'p';
    m["77"] = 'q';
    m["777"] = 'r';
    m["7777"] = 's';
    m["8"] = 't';
    m["88"] = 'u';
    m["888"] = 'v';
    m["9"] = 'w';
    m["99"] = 'x';
    m["999"] = 'y';
    m["9999"] = 'z';

    for (int i = s.size() - 1; i >= 0; i--)
    {
        temp += s[i];
        if (i == 0 || (i > 0 && s[i] != s[i - 1]))
        {
            output += m[temp];
            temp = "";
        }
        
        if((i > 0 && s[i] == s[i - 1]) && temp.size() >= 3)
        {
            output += m[temp];
            temp = "";
        }
    }

    reverse(output.begin(), output.end());

    cout << output;
    // for (int i = 2, j = 'a'; i < 11; i++, j += 3)
    // {
    //     m[to_string(i)] = j;
    //     cout << to_string(i) << " | "<< j << " | " << m[to_string(i)] << endl;

    //     if(i == 7)
    //     {
    //         i++;
    //         j++;
    //     }
    // }

    // cout << endl;
    // for(auto it = m.begin(); it != m.end(); it++)
    // {
    //     cout << it->second << endl;
    // }
}