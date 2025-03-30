#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, A, B;
    cin >> N >> A >> B;

    int allsum = 0;
    int num;

    //各数ごとに判定
    for(int i = 1; i<=N; i++){
        num = i;
        int sum = 0;
        while(num >= 1){
            sum += num % 10;
            num -= num % 10;
            num = num / 10;
        }
        if(sum >= A && sum <= B){
            allsum += i;
        }
    }
    cout << allsum;
}