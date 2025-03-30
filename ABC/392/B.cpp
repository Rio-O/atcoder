#include <bits/stdc++.h>
using namespace std;


int main(){
    bool find[1001];
    for(int i = 0; i < 1002; i++){
        find[i] = false;
    }

    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a;
        cin >> a;
        find[a] = true;
    }
    cout << to_string(N-M) << endl;

    for(int i = 1; i <= N; i++){
        if(!find[i]){
            cout << to_string(i) << " ";
        }
    }
    cout << endl;
}