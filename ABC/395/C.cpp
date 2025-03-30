#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int bucket[1000001];
    int closest = INT_MAX;
    bool find = false;

    //明示的に初期化せよ
    for(int i = 0; i < 1000001; i++){
        bucket[i] = 0;
    }

    for(int i = 1; i <= N; i++){
        int in;
        cin >> in;
        if(!bucket[in] == 0){
            closest = min(closest, i-bucket[in]);
            find = true;
        }
        bucket[in] = i;
    }

    cout << ((find)? closest + 1: -1) << endl;
}