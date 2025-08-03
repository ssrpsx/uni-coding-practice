#include <bits/stdc++.h>

// Input vertex : A - Z
std::pair<std::vector<char>, int> dijkstra(std::vector<std::vector<int>> &edges, int vertex, char start, char end)
{
    std::vector<std::vector<std::pair<int, int>>> adj(vertex);

    int v_start = start - 'A';
    int v_end = end - 'A';

    for (const auto &edge : edges)
    {
        int u = edge[0] - 'A';
        int v = edge[1] - 'A';
        int weight = edge[2];

        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    std::vector<int> dist(vertex, INT_MAX);
    std::vector<int> prev(vertex, -1);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    dist[v_start] = 0;
    pq.push({0, v_start});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if(u == v_end) break;

        for (const auto &a : adj[u])
        {
            int v = a.first;
            int w = a.second;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                prev[v] = u;

                pq.push({dist[v], v});
            }
        }
    }

    std::vector<char> path;
    if(dist[v_end] == INT_MAX) return {};
    
    for(int at = v_end; at != -1; at = prev[at])
        path.push_back(at + 'A');
        
    
    std::reverse(path.begin(), path.end());
    return {path, dist[v_end]};
}