void lexicographicalBfs(vector<vector<int>>& adj, vector<bool>& vis, int src) {
    priority_queue<int, vector<int>, greater<int>> mh;
    mh.push(src);
    vis[src] = true;

    while (!mh.empty()) {
        int u = mh.top();
        mh.pop();

        cout << u << " ";

        for (auto& v : adj[u]) {
            if (!vis[v]) {
                mh.push(v);
                vis[v] = true;
            }
        }
    }
}