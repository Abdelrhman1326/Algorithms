void dfs(vector<vector<int>>& adj, int u) {
    vector<bool> vis(adj.size(), false);
    stack<int> st;
    st.push(u);
    vis[u] = true;

    while (!st.empty()) {
        int curr = st.top();
        st.pop();

        cout << curr << ' ';

        for (int i = (int)adj[curr].size() - 1; i >= 0; --i) {
            int child = adj[curr][i];
            if (!vis[child]) {
                st.push(child);
                vis[child] = true;
            }
        }
    }
}
