#include <bits/stdc++.h>
#include "Graph/DFS.h"
using namespace std;

int main() {
    DFS<char> dfs;
    map<char, vector<char>> graph;

    graph['A'] = {'B', 'C'};
    graph['B'] = {'D', 'E'};
    graph['C'] = {'F'};
    graph['D'] = {'G'};
    graph['E'] = {'G', 'H'};
    graph['F'] = {'I'};
    graph['G'] = {};
    graph['H'] = {'J'};
    graph['I'] = {};
    graph['J'] = {};

    cout << "DFS traversal (stack): ";
    dfs.get_graph(graph);
    dfs.get_dfs('A');
    return 0;
}