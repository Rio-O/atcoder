#include <bits/stdc++.h>
using namespace std;

//MLE回答
// bool read(string S, int pos, int size){
//     if(pos == size){
//         return true;
//     }
//     if(pos + 6 < size && S[pos] == 'd' && S[pos + 1] == 'r' && S[pos + 2] == 'e' && S[pos + 3] == 'a' && S[pos + 4] == 'm'
//                 && S[pos + 5] == 'e' && S[pos + 6] == 'r'){
//         return read(S, pos + 5, size) || read(S, pos + 7, size);
//     }
//     else if(pos + 4 < size && S[pos] == 'd' && S[pos + 1] == 'r' && S[pos + 2] == 'e' && S[pos + 3] == 'a' && S[pos + 4] == 'm'){
//         return read(S, pos + 5, size);
//     }
//     else if(pos + 5 < size && S[pos] == 'e' && S[pos + 1] == 'r' && S[pos + 2] == 'a' && S[pos + 3] == 's' && S[pos + 4] == 'e' && S[pos + 5] == 'r'){
//         return read(S, pos + 5, size) || read(S, pos + 6, size);
//     }
//     else if(pos + 4 < size && S[pos] == 'e' && S[pos + 1] == 'r' && S[pos + 2] == 'a' && S[pos + 3] == 's' && S[pos + 4] == 'e'){
//         return read(S, pos + 5, size);
//     }
//     else{
//         return false;
//     }
// }

// int main(){
//     string S;
//     cin >> S;
//     int size = S.length();
//     cout << ((read(S, 0, size))? "YES" : "NO");
// }


int main(){
    string S;
    cin >> S;
    string divides[4] = {"dream", "dreamer", "erase", "eraser"};

    reverse(S.begin(), S.end());
    for(int i = 0; i < 4; i++) reverse(divides[i].begin(), divides[i].end());
    int pos = 0;
    int size = S.length();
    while(pos < size){
        bool find = false;
        for(int i = 0; i < 4; i++){
            if(S.substr(pos, divides[i].length()) == divides[i]){
                pos +=  divides[i].length();
                find = true;
                break;
            }
        }
        if(!find) break;
        // if(size - pos >= 5 && S.substr(pos, 5) == divides[0]){
        //     pos += 5;
        //     continue;
        // }
        // else if(size - pos >= 7 && S.substr(pos, 7) == divides[1]){
        //     pos += 7;
        //     continue;
        // }
        // else if(size - pos >= 5 && S.substr(pos, 5) == divides[2]){
        //     pos += 5;
        //     continue;
        // }
        // else if(size - pos >= 6 && S.substr(pos, 6) == divides[3]){
        //     pos += 6;
        //     continue;
        // }
        // break;
    }
    if(pos == size) cout << "YES";
    else cout << "NO";
}