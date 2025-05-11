#include <bits/stdc++.h>
#include "graph/BFS.h"
using namespace std;


int main() {
    BFS bfs;
    int row, col, startX, startY;
    cout << "Input graph : " << endl;
    cin >> row >> col;

    vector<vector<char>> graph(row, vector<char>(col));
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == 'S') {
                startX = i;
                startY = j;
            }
        }
    }

    bfs.get_graph(graph, startX, startY);
    bfs.ft_bfs();
    return 0;
}