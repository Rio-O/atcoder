#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    
    int W_inrow = 0;
    for(int i = 0; i < S.length(); i++){
        if(S[i] == 'W'){
            W_inrow++;
        }else{
            if(S[i] == 'A' && W_inrow > 0){
                S[i - W_inrow] = 'A';
                for(int j = 0; j < W_inrow; j++){
                    S[i - j] = 'C';
                }
            }
            W_inrow = 0;
        }
    }

    //TLE解凍
    // bool next = true;
    // while(next){
    //     bool find = false;
    //     for(int i = 0; i < S.length() - 1; i++){
    //         if(S[i] == 'W' && S[i+1] == 'A'){
    //             S[i] = 'A';
    //             S[i+1] = 'C';
    //             find = true;
    //             break;
    //         }
    //     }
    //     next = find;
    // }

    cout << S;
}