#include <bits/stdc++.h>
using namespace std;

int A[100000];
std::priority_queue<long> q;

int main(){
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        long in;
        cin >> in;
        A[i] = in;
    }
    for(int i = 0; i < N; i++){
        q.push(A[i]);
    }
    
    for(int i = 0; i < M; i ++){
        long top;
        top = q.top();
        q.pop();
        q.push(top/2);
    }

    long ans = 0;
    for(int i = 0; i < N; i++){
        ans += q.top();
        q.pop();
    }

    cout << ans << endl;
}   