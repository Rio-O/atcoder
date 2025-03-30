#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> check(int N, int Y){
    //10000*i + 5000*j + 1000*(N-i-j)
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N - i; j++){
            if(10000*i + 5000*j + 1000*(N-i-j) == Y){
                return {i, j, N-i-j};
            }
        }
    }
    return {-1, -1, -1};
}

int main(){
    int N, Y;
    cin >> N >> Y;

    tuple<int, int, int> t = check(N, Y);

    cout << to_string(get<0>(t)) << " " << to_string(get<1>(t)) << " " << to_string(get<2>(t));

}