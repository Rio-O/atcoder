#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    bool is_black[50][50];
    bool write_black;
    int LU, RD;
    LU = 0;
    RD = N-1;
    for(int i = 0; i < N/2+2; i++){
        if(i%2==0){
            write_black = true;
        }else{
            write_black = false;
        }
        LU = i;
        RD = N - 1 - LU;
        for(int j = LU; j <= RD; j++ ){
            for(int k = LU; k <= RD; k++ ){
                is_black[j][k] = write_black;
            }
        }
    }

    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N; j++){
            cout << ((is_black[i][j])?"#":".");
        }
        cout << endl;
    }
}