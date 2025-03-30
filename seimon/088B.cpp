#include <bits/stdc++.h>
using namespace std;


int main(){
    int N;
    cin >> N;
    vector<int> a;
    int l;
    for(int i = 0; i < N; i++){
        cin >> l;
        a.push_back(l);
    }
    sort(a.rbegin(), a.rend());
    int alice = 0;
    int bob = 0;
    for(int i = 0; i < N; i++){
        (i%2 == 0)? alice += a[i] : bob += a[i];
    }
    cout << to_string(alice - bob) << endl;
}