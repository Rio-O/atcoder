#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < s.length()-2; i++){
        for(int j = i+1; j+(j-i) < s.length(); j++){
            if(s[i] == 'A' && s[j] == 'B' && s[j+j-i] == 'C'){
                ans++;
            }
        }
    }
    cout << ans << endl;
}