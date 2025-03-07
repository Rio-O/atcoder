#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
    return (a % b)? gcd(b, (a % b)) : b;
}

int main(){
    long long A, B, C;
    cin >> A >> B >> C;
    long long gcdall = gcd( C, gcd(A,B));
    long long cuttimes = 0;

    cuttimes += A / gcdall;
    cuttimes += B / gcdall;
    cuttimes += C / gcdall;
    cuttimes -= 3;
    std::cout << cuttimes << std::endl;
}