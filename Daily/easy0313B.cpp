#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C, D, E, F, X;
    cin >> A >> B >> C >> D >> E >> F >> X;
    int takahashi = (X / (A+C)) * A * B + B * min((X % (A+C)), A);
    int aoki = (X/ (D + F)) * D * E + E * min((X%(D + F)), D);
    string ans;
    if(takahashi > aoki){
        ans = "Takahashi";
    }else if(takahashi < aoki){
        ans = "Aoki";
    }else{
        ans = "Draw";
    }
    cout << ans << endl;
}