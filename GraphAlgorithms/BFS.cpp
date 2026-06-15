void bfs(const vector<vector<int>>& adj, int u) {
    queue<int> q;
    vector<bool> vis(adj.size(), false);

    q.push(u);
    vis[u] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << '\n';

        for (auto child : adj[curr]) {
            if (!vis[child]) {
                vis[child] = true;
                q.push(child);
            }
        }
    }
}