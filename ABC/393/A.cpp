#include <bits/stdc++.h>
using namespace std;

int main(){
    int ans;
    string takahashi, aoki;
    cin >> takahashi >> aoki;
    if(takahashi == "sick"){
        if(aoki == "sick"){
            ans = 1;
        }else{
            ans = 2;
        }
    }else{
        if(aoki == "sick"){
            ans = 3;
        }else{
            ans = 4;
        }
    }
    cout << ans << endl;
}