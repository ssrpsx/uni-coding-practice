#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#define n 46

using namespace std;

struct data {
    string name;
    double ne, ni, te, ti, se, si, fe, fi, sum;
    char type[5];
    string nick_name;
    string sex;
};

int main() {
    data user;
    data s[46] = {
        {"Warin Wattanapornprom", 32, 32, 27, 36, 29, 31, 28, 23, 0, "INTP", "Aj.Yong", "Male"},
        {"Kittipat Thondee", 26.8, 31.2, 19, 32, 16, 32, 25, 18, 0, "INTP", "Tonmon", "Male"},
        {"Jeerawat Komsang", 40.8, 36.2, 19, 27, 27, 32, 38, 24, 0, "ENTP", "Ice", "Male"},
        {"Chetniphat Pokin", 37.2, 32.2, 37, 33, 26, 29, 22, 27, 0, "INTP", "savegg", "Male"},
        {"Chanathip Choochuay", 18, 22.4, 20, 26, 21, 26, 26, 20, 0, "ISFJ", "Peemai", "Male"},
        {"Chanut Sunatho", 28, 18, 30, 35, 20, 29, 32, 31, 0, "INTP", "Nut", "Male"},
        {"Natpatsorn Apiwatdechalert", 31, 13.8, 27, 28, 27, 29, 32, 13, 0, "ESFJ", "Pangpond", "Female"},
        {"Taechin Kittikraisak", 20.8, 23, 30, 42, 28, 27, 19, 25, 0, "ISTP", "Fluke", "Male"},
        {"Thanaphon Ananrit", 41, 36, 27, 39, 21, 39, 23, 29, 0, "INTP", "Seng", "Male"},
        {"Thanakorn Karndee", 31.4, 31, 30, 38, 22, 29, 26, 26, 0, "INTP", "Hall", "Male"},
        {"Teeranan Pakdeekhan", 30.2, 25.6, 34, 38, 31, 36, 14, 30, 0, "INTP", "Dew", "Male"},
        {"Naphon Jangjit", 37.8, 28.6, 27, 31, 23, 30, 23, 26, 0, "INTP", "Tle", "Male"},
        {"Natcha Chettanathamchit", 38.2, 33.8, 24, 35, 27, 37, 32, 27, 0, "INTP", "C", "Female"},
        {"Pawarit Toopamaeng", 32.8, 29, 29, 39, 37, 32, 29, 30, 0, "ISTP", "Pun", "Male"},
        {"Pornchanok Dithipeng", 38, 40.8, 32, 37, 20, 34, 34, 25, 0, "INFJ", "First", "Female"},
        {"Pathcharapisit Punyakom", 32.8, 27.6, 18, 26, 24, 27, 29, 17, 0, "ENTP", "M", "Male"},
        {"Wilaiwan Jang-in", 19.2, 33.4, 25, 25, 20, 21, 16, 18, 0, "INTJ", "Pimmy", "Female"},
        {"Visarut Makjinda", 30.4, 27.2, 27, 26, 15, 32, 26, 23, 0, "ISFJ", "Mac", "Male"},
        {"Sarawut Ponsan", 35, 33, 32, 38, 42, 43, 30, 40, 0, "INTP", "Phai", "Male"},
        {"Sutthinun Sarawiroj", 30, 24.8, 29, 35, 39, 36, 25, 27, 0, "ESTJ", "Art", "Male"},
        {"Suphichaya Prangcharoen", 29.8, 26.4, 27, 29, 27, 27, 23, 20, 0, "ENTP", "Acheer", "Female"},
        {"Aphichet Chaiyasat", 34, 31, 23, 31, 24, 30, 25, 31, 0, "INFP", "Bank", "Male"},
        {"Ardharn Noited", 28.8, 29.6, 24, 19, 25, 21, 18, 16, 0, "ENTJ", "Ho", "Male"},
        {"Kanopon Misrisawad", 31.4, 34, 21, 27, 28, 37, 25, 31, 0, "INTP", "March", "Male"},
        {"Krittinan Buathong", 23, 26, 22, 26, 27, 31, 24, 26, 0, "ISFJ", "Frame", "Male"},
        {"Zareep Yusoh", 35, 27.5, 26, 32, 29, 33, 18, 32, 0, "INTP", "Zar", "Male"},
        {"Yada Intra", 40.4, 25.8, 32, 27, 29, 33, 37, 35, 0, "ENFP", "Punch", "Female"},
        {"Daral Muhummud", 37.6, 17, 23, 37, 17, 23, 20, 35, 0, "INTP", "Run", "Male"},
        {"Paphawarin Lap-anant", 22.2, 27.4, 20, 31, 23, 29, 34, 20, 0, "ESFJ", "Bell", "Female"},
        {"Pattamapon Thongplew", 24, 26.4, 28, 29, 26, 31, 24, 25, 0, "ISTJ", "Yoyo", "Female"},
        {"Pongpanot Puankaewhan", 33, 37.2, 32, 36, 32, 39, 34, 32, 0, "ISFJ", "Gus", "Male"},
        {"Pichayatida Suapanklang", 30, 38.8, 26, 35, 25, 20, 22, 25, 0, "INTP", "Vi", "Female"},
        {"Peerapong Chummongkon", 40.6, 38.2, 29, 37, 15, 39, 33, 21, 0, "INTP", "Sunday", "Male"},
        {"Phomphongsa Wiwatprayun", 35.8, 27, 35, 37, 35, 36, 21, 31, 0, "INTP", "Poom", "Male"},
        {"Phuriphat Tantirangsi", 28.2, 22.6, 18, 29, 19, 27, 18, 13, 0, "INTP", "Best", "Male"},
        {"Puwanat Phankearnkut", 28.8, 27, 25, 32, 19, 35, 32, 16, 0, "ISFJ", "Pu", "Male"},
        {"Monpat Thaninthakpong", 19, 32, 27, 27, 16, 22, 21, 24, 0, "INTJ", "Keen", "Male"},
        {"Yossapart Rasri", 46.2, 36.6, 30, 39, 25, 37, 32, 25, 0, "ENTP", "Pea", "Male"},
        {"Worrawat Khongkhlai", 29, 23, 20, 30, 18, 21, 20, 25, 0, "INTP", "Soda", "Male"},
        {"Sarrawit Mitwongsa", 27.6, 33.4, 29, 42, 31, 36, 35, 31, 0, "ISFJ", "Film", "Male"},
        {"Sarit Sridit", 27.4, 31.4, 37, 35, 32, 34, 37, 30, 0, "ESTP", "Fil", "Male"},
        {"Phonlawat Phetsing", 28, 18, 36, 22, 24, 40, 20, 32, 0, "ISTJ", "Neo", "Male"},
        {"Warisara Muangplub", 33.6, 30.4, 33, 34, 24, 30, 25, 27, 0, "INTP", "Mo", "Female"},
        {"Archariya Sa-ngasap", 25.6, 38.4, 21, 32, 17, 37, 38, 27, 0, "INFJ", "Feeling", "Female"},
        {"Chanya Rodsamer", 27, 25, 29, 29, 24, 28, 27, 21, 0, "ESTP", "Meiji", "Female"},
        {"Natchaya Tampong", 32, 22.4, 26, 26, 29, 26, 26, 16, 0, "ENTP", "Ice", "Female"}
    };

    cout << "Input your data : [Name, Ne, Ni, Te, Ti, Se, Si, Fe, Fi]\n";
    cin >> user.name >> user.ne >> user.ni >> user.te >> user.ti
        >> user.se >> user.si >> user.fe >> user.fi;

    double min[5] = {99999};
    int min_index[5] = {0};
    
    int cout_vote[2][4] = {0};
    char type_vote[2][4] = {
        {'I', 'N', 'T', 'J'},
        {'E', 'S', 'F', 'P'}
    };

    for(int i=0; i < n; i++)
    {
        double sum = 0;
        
        // คำนวณระยะห่างระหว่าง user กับ data ที่อินพุตเข้ามา โดยใช้สูตร Euclidean distance
        sum += (pow((user.ne - s[i].ne), 2) + pow((user.ni - s[i].ni), 2) + pow((user.te - s[i].te), 2) + pow((user.ti - s[i].ti), 2)
        + pow((user.se - s[i].se), 2) + pow((user.si - s[i].si), 2) + pow((user.fe - s[i].fe), 2) + pow((user.fi - s[i].fi), 2));

        s[i].sum = sqrt(sum);

        printf("Name : %-40s | %-6s | Distance : %5.5lf\n", (s[i].name + " " + "(" + s[i].nick_name + ")").c_str(), s[i].sex.c_str(), s[i].sum);
        for (int j = 4; j >= 0; j--) {
            if (s[i].sum < min[j]) {
                if (j < 4) {
                    min[j + 1] = min[j];
                    min_index[j + 1] = min_index[j];
                }
                min[j] = s[i].sum;
                min_index[j] = i;
            } 
            else 
            {
                break;
            }
        } // O(4) for ข้างใน O(n) for ข้างนอก = O(4) * O(n) = O(4n) = O(n)           
    }
    cout << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (s[min_index[j]].type[i] == type_vote[0][i])
                cout_vote[0][i]++;
            else
                cout_vote[1][i]++;
        }
    } // นับคะแนนโดย O(4) * O(5) = O(20) = O(1)

    cout << "your type is : ";

    for(int i = 0; i < 4; i++)
    {
        if(cout_vote[0][i] > cout_vote[1][i]) cout << type_vote[0][i];
        else cout << type_vote[1][i];
    }
    return 0;
}