#include <bits/stdc++.h>
using namespace std;

int N;
long long K;

int main(){
    cin >> N >> K;
    long A[1000];

    long long defSum = 0;

    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < N; i++){
        long B;
        cin >> B;
        long defference = B - A[i];
        defSum += (defference < 0) ? -defference : defference;
    }

    if(K >= defSum && (K - defSum) % 2 == 0){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }
}