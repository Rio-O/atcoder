#include <bits/stdc++.h>
using namespace std;

int N_MAX = 100000;

int main(){
    long A[N_MAX];
    long B[N_MAX];

    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < N; i++){
        cin >> B[i];
    }

    sort(A, A+N);
    sort(B, B+N);

    long defsum = 0;
    for(int i = 0; i < N; i ++){
        long defference = A[i] - B[i];
        defsum += ((defference < 0) ? -defference : defference);
    }
    
    std::cout << defsum << std::endl;
}