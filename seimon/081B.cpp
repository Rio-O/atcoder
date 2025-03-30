#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int a;
    int minaction = INT_MAX;
    for(int i = 0; i < N; i++){
        cin >> a;
        int action = 0;
        while(true){
            if(a % 2 == 0 && action < minaction){
                action ++;
                a = a / 2;
            }else{
                if(action < minaction){
                    minaction = action;
                }
                break;
            }
        }
    }

    cout << minaction << endl;
}