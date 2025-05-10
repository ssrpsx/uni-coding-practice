#ifndef DFS_H
#define DFS_H

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class DFS{
    private:
        map<T, vector<T>> graph;
        set<T> visited;

        void ft_dfs(T start){
            stack<T> s;
            s.push(start);

            while (!s.empty()){
                T node = s.top();
                s.pop();
                
                if(!visited.count(node)){
                    visited.insert(node);
                    cout << node << " ";

                    for(int i = graph[node].size() - 1; i >= 0; i--){
                        T neighbor = graph[node][i];
                        if(!visited.count(neighbor)) {
                            s.push(neighbor);
                        }
                    }
                }
            }
            
        }
    public:
        void get_graph(map<T, vector<T>> &g){
            graph = g;
        }

        void get_dfs(T data){
            ft_dfs(data);
        }
};

#endif