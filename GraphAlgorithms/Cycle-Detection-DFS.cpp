vector<vector<int>> adj;
vector<int> visited; // 0 = unvisited, 1 = visiting, 2 = fully visited
vector<int> order;
bool has_cycle = false;

void dfs(int u) {
    visited[u] = 1;

    for (int v : adj[u]) {
        if (visited[v] == 1) {
            has_cycle = true;
        } else if (visited[v] == 0) {
            dfs(v);
        }
    }

    visited[u] = 2;
    order.push_back(u);
}