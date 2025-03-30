#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<string> bucket[51];
    for(int i = 0; i<N; i++){
        string s;
        cin >> s;
        bucket[s.length()].push_back(s);
    }
    for(int i = 1; i <= 50; i++){
        for(int j = 0; j < bucket[i].size(); j++){
            cout << bucket[i][j];
        }
    }
    cout << endl;
}