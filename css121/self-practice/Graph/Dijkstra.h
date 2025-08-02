#include <bits/stdc++.h>

std::vector<int> dijkstra(std::vector<std::vector<int>> &edges, int vertex, int start)
{
    std::vector<std::vector<std::pair<int, int>>> adj(vertex);

    for (const auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    std::vector<int> dist(vertex, INT_MAX);
    dist[start] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    pq.push({0, start});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for(auto &a : adj[u])
        {
            int v = a.first;
            int w = a.second;
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}