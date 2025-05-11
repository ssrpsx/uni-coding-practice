#ifndef BFS_H
#define BFS_H

#include <bits/stdc++.h>
using namespace std;

class BFS{
    int rows, cols, startX, startY;

    vector<vector<char>> graph;
    vector<vector<bool>> visited;
    const vector<pair<int, int>> directions = {
        {0, -1},
        {0, 1},
        {-1, 0},
        {1, 0}
    };

    vector<vector<pair<int, int>>> prev;
    vector<vector<char>> newgraph;
    vector<pair<int, int>> path;

    private:
        void bfs(int x, int y) {
            queue<pair<int, int>> q;

            q.push({x, y});
            visited[x][y] = true;

            while (!q.empty())
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(int i = 0; i < directions.size(); i++) {
                    int nx = x + directions[i].first;
                    int ny = y + directions[i].second;

                    if(nx >= 0 && ny >= 0 && nx < rows && ny < cols && !visited[nx][ny] &&
                        (graph[nx][ny] == '.' || graph[nx][ny] == 'E')) {
                            prev[nx][ny] = {x, y};
                            visited[nx][ny] = true;

                            if (graph[nx][ny] == 'E') {
                                cout << "\nFound 'E' at: (" << nx << ", " << ny << ")\n";

                                copygraph(nx, ny);
                                cout << endl;
                                print_graph(2);
                                
                                return;
                            }
                            
                            q.push({nx, ny});
                        }
                }
            }
        }
        void copygraph(int x, int y) {
            newgraph = graph;
            pair<int, int> cur = {x, y};
            
            while(cur != make_pair(-1, -1)) {
                path.push_back(cur);
                cur = prev[cur.first][cur.second];
            }

            reverse(path.begin(), path.end());

            for(int move = 1; move < path.size() - 1; move++) {
                int x = path[move].first;
                int y = path[move].second;

                newgraph[x][y] = 'O';
            }
        }
        void print_graph(int config) {
            if(config == 1) {
                cout << "Old_Graph : " << endl;

                for(int i = 0; i < rows; i++) {
                    for(int j = 0; j < cols; j++) {
                        cout << graph[i][j] << ' ';
                    }
                    cout << endl;
                }
            }
            else {
                cout << "New_Graph : " << endl;

                for(int i = 0; i < rows; i++) {
                    for(int j = 0; j < cols; j++) {
                        cout << newgraph[i][j] << ' ';
                    }
                    cout << endl;
                }
            }
        }
    public:
        void get_graph(vector<vector<char>> &g, int x, int y) {
            graph = g;
            rows = graph.size();
            cols = graph.empty() ? 0 : graph[0].size();

            startX = x;
            startY = y;
            visited = vector<vector<bool>>(rows, vector<bool>(cols, false));
            prev = vector<vector<pair<int, int>>>(rows, vector<pair<int, int>>(cols, {-1, -1}));
        }

        void print_old() {
            print_graph(1);
        }

        void print_new() {
            print_graph(2);
        }

        void ft_bfs() {
            bfs(startX, startY);
        }
};

#endif

// Test Case
// 1)
// 5 5
// S . # . E
// # . # . #
// # . . . #
// # # # . #
// . . . . .

// 2)
// 6 7
// S . . # . . .
// # # . # # # .
// . . . . . # .
// . # # # . # .
// . . . # . . .
// . # . . . # E

// 3)
// 8 8
// S . . # . . . #
// # # . # # . . #
// . . . . . . # #
// . # # # # . # .
// . . . . . . . .
// # . # # # # . #
// # . . . . # . E
// # # # # . # # #

// 4)
// 7 7
// S # . . # . E
// . # . # # . #
// . # . . . . #
// . . . # . # #
// # # . # . . .
// # . . . . # .
// # # # # # # .
