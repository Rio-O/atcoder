#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int coins[3];
    cin >> N >> coins[0] >> coins[1] >> coins[2];

    sort(coins, coins + 3, greater<int>());

    int max1 = N / coins[0];
    int max2 = N / coins[1];

    for(int i = max1; i >= 0 ; i-- ){
        for(int j = max2; j >= 0; j--){
            int amari = (N - coins[0] * i - coins[1] * j) % coins[2];
            if((N - coins[0] * i - coins[1] * j >= 0) &&  amari == 0){
                int maisuu = (N - coins[0] * i - coins[1] * j) / coins[2];
                std::cout << i + j + maisuu << std::endl;
                return 0;
            }
        }
    }
}