#include <bits/stdc++.h>
using namespace std;

int main(){
    int Q;
    cin >> Q;
    stack<int> pile;
    for(int i = 0; i < 100; i++){
        pile.push(0);
    }
    for(int t = 1; t <= Q; t++){
        int type;
        cin >> type;
        if(type == 1){
            int a;
            cin >> a;
            pile.push(a);
        }else{
            cout << pile.top() << endl;
            pile.pop();
        }
    }
}