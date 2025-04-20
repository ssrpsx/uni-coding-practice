#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;

struct data {
    string name;
    double ne, ni, te, ti, se, si, fe, fi, sum;
};

int main() {
    data s[16] = {
        {"Kuuga", 35.4, 31, 33, 30, 38, 31, 34, 31, 0},
        {"Agito", 26, 31, 33, 30, 26, 33, 30, 24, 0},
        {"Ryuki", 24.4, 30.2, 31, 34, 28, 36, 22, 17, 0},
        {"Balde", 22.2, 25.8, 36, 37, 29, 36, 34, 22, 0},
        {"Hibiki", 43.2, 34, 36, 36, 39, 38, 40, 35, 0},
        {"Kabuto", 32.4, 27, 35, 34, 27, 23, 31, 19, 0},
        {"Den-O", 28.4, 25.6, 33, 35, 32, 30, 24, 26, 0},
        {"Kiva", 30.2, 31.4, 35, 33, 36, 33, 36, 34, 0},
        {"Decade", 19.4, 12, 25, 28, 25, 23, 23, 22, 0},
        {"Fourze", 33.4, 38.6, 29, 29, 26, 37, 24, 25, 0},
        {"Gaim", 30, 29.6, 34, 32, 38, 28, 33, 22, 0},
        {"Ex-Aid", 29, 22.8, 40, 28, 27, 31, 29, 19, 0},
        {"Zi-O", 25.5, 33, 28, 34, 37, 27, 28, 24, 0},
        {"Saber", 29.8, 26.4, 28, 36, 29, 30, 33, 28, 0},
        {"Revice", 18.4, 15, 30, 33, 33, 31, 26, 23, 0}
    };

    string name1, name2, name3;
    double min1 = 99999, min2 = 99999, min3 = 99999;

    cout << "Input your data : [Name, Ne, Ni, Te, Ti, Se, Si, Fe, Fi]\n";
    cin >> s[15].name >> s[15].ne >> s[15].ni >> s[15].te >> s[15].ti >> s[15].se
        >> s[15].si >> s[15].fe >> s[15].fi;
    cout << "\n";
    
    // bigO O(n) ฟังก์ชันนี้ทำการวนลูปผ่านนักเรียนทั้งหมด n คน และคำนวณระยะทาง Euclidean distance โดยใช้สูตร Euclidean distance
    for(int i = 0; i < 15; i++)
    {
        double sum = 0;
        sum += (pow((s[15].ne - s[i].ne), 2) + pow((s[15].ni - s[i].ni), 2) + pow((s[15].te - s[i].te), 2) + pow((s[15].ti - s[i].ti), 2)
        + pow((s[15].se - s[i].se), 2) + pow((s[15].si - s[i].si), 2) + pow((s[15].fe - s[i].fe), 2) + pow((s[15].fi - s[i].fi), 2));
        s[i].sum = sqrt(sum);

        printf("Name : %-10s, Distance : %4.5lf\n", s[i].name.c_str(), s[i].sum);

        if(s[i].sum < min1)
        {
            min3 = min2;
            name3 = name2;
            min2 = min1;
            name2 = name1;
            min1 = s[i].sum;
            name1 = s[i].name;
        }
        else if(s[i].sum < min2)
        {
            min3 = min2;
            name3 = name2;
            min2 = s[i].sum;
            name2 = s[i].name;
        }
        else if (s[i].sum < min3)
        {
            min3 = s[i].sum;
            name3 = s[i].name;
        }
    }
    
    cout << "\nTop 3 closest distances: \n";
    cout << "1st : " << name1 << " | with distance : " << min1 << endl;
    cout << "2nd : " << name2 << " | with distance : " << min2 << endl;
    cout << "3rd : " << name3 << " | with distance : " << min3 << endl;

    return 0;
}