void Dijkstra(const vector<vector<pair<int, int>>>& adj, int source, vector<long long>& dist) {
    int n = adj.size();
    dist.assign(n, LLONG_MAX);

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> min_heap;

    dist[source] = 0;
    min_heap.push({0, source});

    while (!min_heap.empty()) {
        auto [d, u] = min_heap.top();
        min_heap.pop();

        if (d > dist[u]) continue;

        for (auto &[v, w] : adj[u]) {
            if (d + w < dist[v]) {
                dist[v] = d + w;
                min_heap.push({dist[v], v});
            }
        }
    }
}