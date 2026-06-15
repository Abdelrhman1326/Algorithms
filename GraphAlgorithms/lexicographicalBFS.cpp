void lexicographicalBfs(vector<vector<int>>& adj, vector<bool>& vis) {
    priority_queue<int, vector<int>, greater<int>> mh;
    mh.push(1);
    vis[1] = true;

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