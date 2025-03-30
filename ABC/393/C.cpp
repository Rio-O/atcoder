#include <bits/stdc++.h>
#include <map>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    //bool used[200001][200001] = {false};
    int ans = 0;

    map<pair<int, int>, int> dic;

    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        if(u==v){
            ans++;
            continue;
        }
        if(u>v) swap(u, v);
        dic[{u, v}]++;
    }
    for(const auto& [key, value] : dic){
        ans += value - 1;
    }

    // for(int i = 0; i < M; i++){
    //     int u, v;
    //     cin >> u >> v;
    //     if(used[u][v]) ans++;
    //     used[u][v] = true;
    //     used[v][u] = true;
    // }
    cout << ans << endl;
}