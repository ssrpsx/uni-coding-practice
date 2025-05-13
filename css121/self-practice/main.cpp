#include <bits/stdc++.h>
using namespace std;

int row, col;
vector<vector<char>> str;
vector<int> block(20, -1);
vector<pair<int, int>> position;
set<int> check;

int main() {
    cin >> row >> col;
    str = vector<vector<char>>(row, vector<char>(col));
    position = vector<pair<int, int>>(col, {-1, -1});

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cin >> str[i][j];
            if(str[i][j] == 'O' && !check.count(j)){
                check.insert(j);
                position[j] = {i, j};
            }
        }
    }

    for(int i = 0; i < col; i++) {
        cin >> block[i];
    }
    
    for (int j = 0; j < col; j++) {
        int remain = block[j];
        int bottom = row - 1;

        if (position[j].first != -1) {
            bottom = position[j].first - 1;
        }
        for (int i = bottom; i >= 0 && remain > 0; i--) {
            if (str[i][j] == '.') {
                str[i][j] = '#';
                remain--;
            }
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << str[i][j];
        }
        cout << endl;
    }
    return 0;
}
