#include <bits/stdc++.h>
using namespace std;

int A[300001] = {0};
bool usedF[300001] = {false};
bool usedB[300001] = {false};
int KF[300001] = {0};
int KB[300001] = {0};

int main(){
    int N;
    cin >> N;
    int kindF = 0;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        A[i] = num;
        if(!usedF[num]){
            kindF++;
            usedF[num] = true;
        }
        KF[i] = kindF;
    }

    reverse(A, A + N);
    
    int kindB = 0;
    for(int i = 0; i < N; i++){
        if(!usedB[A[i]]){
            kindB++;
            usedB[A[i]] = true;
        }
        KB[i] = kindB;
    }

    int MAX = 0;
    for(int i = 0; i < N-1; i++){
        MAX = max(MAX, KF[i] + KB[N-2-i]);
    }
    cout << MAX << endl;
}