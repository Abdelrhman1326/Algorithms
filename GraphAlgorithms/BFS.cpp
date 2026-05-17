#include <bits/stdc++.h>
using namespace std;

void bfsIterative(const vector<vector<int>>& dep, int u) {
    queue<int> q;
    vector<bool> vis(dep.size(), false);

    q.push(u);
    vis[u] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << '\n';

        for (auto child : dep[curr]) {
            if (!vis[child]) {
                vis[child] = true;
                q.push(child);
            }
        }
    }
}