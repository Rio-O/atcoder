#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int ans = N;
    for(int i = 0; i < N; i++){
        int hands;
        cin >> hands;
        M -= hands;
        if(M < 0){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}