void dfs(vector<vector<int>>& dep, int u, vector<bool>& vis) {
    cout << u << ' ';
    vis[u] = true;

    for (auto& c : dep[u]) {
        if (!vis[c]) {
            dfs(dep, c, vis);
        }
    }
}