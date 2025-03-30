#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int last = 0;
    int now;
    bool ok = true;
    for(int i = 0; i < N; i++){
        cin >> now;
        if(last >= now){
            ok = false;
            break;
        }
        last = now;
    }
    cout << ((ok)? "Yes" : "No") << endl;
}