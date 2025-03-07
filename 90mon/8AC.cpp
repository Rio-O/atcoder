#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const string T = "atcoder";

// a に b を足して、MOD をとる関数
void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int main(){
    int N;
    string S;
    cin >> N >> S;


   vector<vector<int>> dptable(N+1, vector<int>(T.size()+1, 0));

    dptable[0][0] = 1;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < T.length() + 1; j++){
            add(dptable[i + 1][j], dptable[i][j]);
            if(j < T.length() && S[i] == T[j]){
                add(dptable[i + 1][j + 1], dptable[i][j]);
            }
        }
    }

    std::cout << dptable[N][T.length()] << endl;

}