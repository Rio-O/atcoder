#include <bits/stdc++.h>
using namespace std;

int hato[1000001];
int idx_real[1000001];
int real_idx[1000001];

void swap(int a, int b){
    int temp;
    temp = real_idx[a];
    real_idx[a] = real_idx[b];
    real_idx[b] = temp;
    int c, d;
    c = real_idx[a];
    d = real_idx[b];
    temp = idx_real[c];
    idx_real[c] = idx_real[d];
    idx_real[d] = temp;
}

int main(){
    int N, Q;
    cin >> N >> Q;

    for(int i = 0; i < 1000001; i++){
        hato[i] = i;
        idx_real[i] = i;
        real_idx[i] = i;
    }

    for(int i = 0; i < Q; i++){
        int op;
        cin >> op;
        int a, b;
        switch(op){
            case(1):
                cin >> a >> b;
                hato[a] = real_idx[b];
                break;
            case(2):
                cin >> a >> b;
                swap(a,b);
                break;
            case(3):
                cin >> a;
                cout << idx_real[hato[a]] << endl;
                break;
        }
    }
}