#include <bits/stdc++.h>
using namespace std;

int main(){
    float temp;
    cin >> temp;
    if(temp >= 38.0){
        cout << 1;
    }else if(temp >= 37.5){
        cout << 2;
    }else{
        cout << 3;
    }
}