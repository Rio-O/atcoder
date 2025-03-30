#include <bits/stdc++.h>
using namespace std;

int main(){
    int s;
    cin >> s;
    int sum = 0;
    if(s >= 100){
        sum++;
        s -= 100;
    }
    if(s >= 10){
        sum++;
        s -= 10;
    }
    if(s >= 1){
        sum++;
    }
    cout << sum << endl;
}