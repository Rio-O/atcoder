#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    tuple<int, int, int> state = {0, 0, 0};

    bool can = true;

    for(int i = 0; i < N; i++){
        int t, a, b;
        cin >> t >> a >> b;
        int dist = abs(a - get<1>(state)) + abs(b - get<2>(state));
        int time = t - get<0>(state);
        if(dist - time <= 0 && (dist - time)%2 == 0){
            state = {t, a, b};
            continue;
        }else{
            can = false;
            break;
        }
    }
    if(can) cout << "Yes";
    else cout << "No";
}