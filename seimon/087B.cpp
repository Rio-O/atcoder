#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    int patterns = 0;
    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
            if((x - 500*i - 100*j) % 50 == 0 && (x - 500*i - 100*j) / 50 <= c && (x - 500*i - 100*j) / 50 >= 0){
                patterns ++;
            }
        }
    }
    cout << patterns;
}