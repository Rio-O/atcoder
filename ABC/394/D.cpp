#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    stack<char> st;
    bool cont = true;
    for(int i = 0; i < S.length(); i++){
        switch(S[i]){
            case('('):
                st.push(S[i]);
            break;
            case('['):
                st.push(S[i]);
            break;
            case('<'):
                st.push(S[i]);
            break;
            case(')'):
                if(st.size() > 0 && st.top() == '(') st.pop();
                else    cont = false;
            break;
            case(']'):
                if(st.size() > 0 && st.top() == '[') st.pop();
                else    cont = false;
            break;
            case('>'):
                if(st.size() > 0 &&st.top() == '<') st.pop();
                else    cont = false;
            break;
        }
        if(!cont) break;
    }
    if(!cont || st.size() > 0){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}