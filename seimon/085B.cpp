#include <bits/stdc++.h>
using namespace std;


int main(){
    int N;
    cin >> N;
    vector<int> d;
    int l;
    for(int i = 0; i < N; i++){
        cin >> l;
        d.push_back(l);
    }
    sort(d.begin(), d.end());
    int now_largest = 0;
    int pile = 0;
    for(int i = 0; i < N; i++){
        if(d[i] > now_largest){
            pile ++;
            now_largest = d[i];
        }
    }
    cout << pile;
}