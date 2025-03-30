#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<pair<int, int>>> G;
long long ans = LLONG_MAX;
vector<bool> visited;

void dfs(int v, long long xor_val) {
    visited[v] = true;  // 訪問済みにする

    // もし今いる頂点が N-1 なら答えを更新
    if (v == N - 1) {
        ans = min(ans, xor_val);
    }

    for (auto [u, w] : G[v]) {
        if (!visited[u]) {
            dfs(u, xor_val ^ w);
        }
    }
    
    visited[v] = false;  // 訪問済みを解除
}

int main() {
    cin >> N >> M;
    G.resize(N);
    visited.resize(N, false);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;  // 0-indexed にする
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    dfs(0, 0);
    cout << ans << endl;

    return 0;
}
