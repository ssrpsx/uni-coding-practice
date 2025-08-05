#include <bits/stdc++.h>
using namespace std;

pair<vector<char>, int> bellmanFord(vector<vector<int>> &edges, int vertex, char start, char end)
{
    int v_start = start - 'A';
    int v_end = end - 'A';

    vector<int> dist(vertex, INT_MAX);
    vector<int> prev(vertex, -1);
    dist[v_start] = 0;

    for (int i = 0; i < vertex - 1; ++i)
    {
        for (const auto &e : edges)
        {
            int u = e[0] - 'A';
            int v = e[1] - 'A';
            int wt = e[2];

            if (dist[u] != INT_MAX && dist[v] > dist[u] + wt)
            {
                dist[v] = dist[u] + wt;
                prev[v] = u;
            }
        }
    }

    for (const auto &e : edges)
    {
        int u = e[0] - 'A';
        int v = e[1] - 'A';
        int wt = e[2];

        if (dist[u] != INT_MAX && dist[v] > dist[u] + wt)
        {
            cout << "Negative weight cycle!";
            return {};
        }
    }

    if (dist[v_end] == INT_MAX)
        return {{}, -1};

    vector<char> path;
    for (int at = v_end; at != -1; at = prev[at])
    {
        path.push_back(at + 'A');
    }

    reverse(path.begin(), path.end());

    return {path, dist[v_end]};
}