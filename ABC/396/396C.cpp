#include <bits/stdc++.h>
using namespace std;

// enum class State{
//     running,
//     Wminus,
//     Bminus
// };

int main(){
    int N, M;
    cin >> N >> M;
    int B[200000];
    int W[200000];
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        B[i] = temp;
    }
    for(int i = 0; i < M; i++){
        int temp;
        cin >> temp;
        W[i] = temp;
    }
    sort(B, B+N, greater<int>());
    sort(W, W+M, greater<int>());

    int BminusIDX = N;
    int WminusIDX = M;
    for(int i = 0; i < N; i ++){
        if(B[i] < 0){
            BminusIDX = i;
            break;
        }
    }
    for(int i = 0; i < M; i ++){
        if(W[i] < 0){
            WminusIDX = i;
            break;
        }
    }

    int maxsum = 0;

    if(BminusIDX >= WminusIDX){
        for(int i = 0; i < BminusIDX; i++){
            if(i < WminusIDX)  maxsum = maxsum + B[i] + W[i];
            else    maxsum += B[i];
        }
    }else{
        int sum = 0;
        for(int i = 0; i < WminusIDX; i++){
            if(i >= N)  break;
            else    sum = sum + B[i] + W[i];
            if(maxsum < sum) maxsum = sum;
        }
    }

    cout << maxsum  << endl;

    // int sum;
    // int summax;

    // State st = State::running;

    // bool exit = false;

    // for(int i = 0; i < max(M,N) && !exit; i++){
    //     switch(st){
    //         case State::running:
    //             if(B[i] >= 0 && W[i] >= 0){
    //                 sum += B[i] + W[i];
    //                 if(sum > summax)    summax = sum;
    //             }
    //             else if(B[i] >= 0 && W[i] < 0){
    //                 sum += B[i];
    //                 if(sum > summax)    summax = sum;
    //                 st = State::Wminus;
    //             }
    //             else if(B[i] < 0 && W[i] >= 0){
    //                 sum += B[i] + W[i];
    //                 if(sum > summax)    summax = sum;
    //                 st = State::Bminus;
    //             }
    //             else{
    //                 exit = true;
    //             }
    //             break;
    //         case State::Bminus:
    //             if(W[i] >= 0){
    //                 sum += B[i] + W[i];
    //                 if(sum > summax)    summax = sum;
    //             }else{
    //                 exit = true;
    //             }
    //             break;
    //         case State::Wminus:
    //             if(B[i] >= 0){
    //                 sum += B[i];
    //                 if(sum > summax)summax = sum;
    //             }else{
    //                 exit = true;
    //             }
    //             break;
    //     }
    // }

    // cout << summax << endl;

}