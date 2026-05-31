void dfs(vector<vector<int>>& adj, int u, vector<bool>& vis) {
    cout << u << ' ';
    vis[u] = true;

    for (auto& c : adj[u]) {
        if (!vis[c]) {
            dfs(adj, c, vis);
        }
    }
}