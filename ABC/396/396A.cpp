#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int a1, a2, a3;
    cin >> a1 >> a2;
    bool find = false;
    for(int i = 3; i <= N; i++){
        cin >> a3;
        if(a1 == a2 && a2 == a3){
            find = true;
            break;
        }
        a1 = a2;
        a2 = a3;
    }
    if(find) cout << "Yes";
    else cout << "No";
}