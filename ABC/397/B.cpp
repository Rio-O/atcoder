#include <bits/stdc++.h>
using namespace std;

int main(){
    string in_str;
    cin >> in_str;
    bool nextIsI = true;
    int action = 0;
    for(int i = 0; i < in_str.length(); i++){
        if(nextIsI){
            if(in_str.at(i) == 'i'){
                nextIsI = false;
            }else{
                action++;
                nextIsI = true;
            }
        }else{
            if(in_str.at(i) == 'i'){
                action++;
                nextIsI = false;
            }else{
                nextIsI = true;
            }
        }
    }

    if((in_str.length() + action)%2 == 1) action++;
    cout << action << endl;
}