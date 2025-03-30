#include <bits/stdc++.h>
using namespace std;

int N, M, X;
bool visited[200001] = {false};
vector<int> adj_true[200001] = {{}};
vector<int> adj_rev[200001] = {{}};
bool rev_mode = false;
long long MIN = LONG_LONG_MAX;

void dfs(int pos, long long sum){
    if(pos == N){
        MIN = min(MIN, sum);
        return;
    }
    for(int i = 0; i < adj_true[pos].size(); i++){
        if(!visited[adj_true[pos][i]]){
            visited[pos] = true;
            if(rev_mode){
                rev_mode = false;
                dfs(adj_true[pos][i], sum + X + 1);
            }else{
                dfs(adj_true[pos][i], sum + 1);
            }
            visited[pos] = false;
        }
    }
    for(int i = 0; i < adj_rev[pos].size(); i++){
        if(!visited[adj_rev[pos][i]]){
            visited[pos] = true;
            if(rev_mode){
                dfs(adj_rev[pos][i], sum + 1);
            }else{
                rev_mode = true;
                dfs(adj_rev[pos][i], sum + X + 1);
            }
            visited[pos] = false;
        }
    }
}

int main(){
    cin >> N >> M >> X;
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        adj_true[u].push_back(v);
        adj_rev[v].push_back(u);
    }
    //1から探索
    dfs(1, 0);
    cout << MIN << endl;
}