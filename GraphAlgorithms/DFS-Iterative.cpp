void dfs(vector<vector<int>>& dep, int u) {
    vector<bool> vis(dep.size(), false);
    stack<int> st;
    st.push(u);

    while (!st.empty()) {
        int curr = st.top();
        st.pop();

        if (vis[curr]) continue;
        vis[curr] = true;
        cout << curr << ' ';

        for (int i = dep[curr].size() - 1; i >= 0; --i) {
            int child = dep[curr][i];
            if (!vis[child]) {
                st.push(child);
            }
        }
    }
}