#include <bits/stdc++.h>
using namespace std;

int N_MAX = 100001;
int Q_MAX = 100001;

int main(){
    int LowerArray[2][N_MAX];
    int ValueArray[2][N_MAX];

    LowerArray[0][0] = 0;
    LowerArray[1][0] = 0;
    ValueArray[0][0] = 0;
    ValueArray[1][0] = 0;

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        LowerArray[0][i+1] = LowerArray[0][i] + ValueArray[0][i];
        LowerArray[1][i+1] = LowerArray[1][i] + ValueArray[1][i];
        
        int C;
        int score;
        cin >> C >> score;
        ValueArray[C-1][i+1] = score;
    }

    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int L;
        int R;
        cin >> L >> R;

        int A = LowerArray[0][R] + ValueArray[0][R] - LowerArray[0][L];
        int B = LowerArray[1][R] + ValueArray[1][R] - LowerArray[1][L];

        std::cout << A << " " << B << std::endl;
    }
}