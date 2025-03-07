#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
public:
	vector<int> par;

	void init(int sz) {
		par.resize(sz, -1);
	}
	int root(int pos) {
		if (par[pos] == -1) return pos;
		par[pos] = root(par[pos]);
		return par[pos];
	}
	void unite(int u, int v) {
		u = root(u); v = root(v);
		if (u == v) return;
		par[u] = v;
	}
	bool same(int u, int v) {
		if (root(u) == root(v)) return true;
		return false;
	}
};

// ����
int H, W, Q;

// ���̑��̕ϐ�
UnionFind UF;
bool used[2009][2009];

void query1(int px, int py) {
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	for (int i = 0; i < 4; i++) {
		int sx = px + dx[i], sy = py + dy[i];
		if (used[sx][sy] == false) continue;
		int hash1 = (px - 1) * W + (py - 1);
		int hash2 = (sx - 1) * W + (sy - 1);
		UF.unite(hash1, hash2);
	}
	used[px][py] = true;
}

bool query2(int px, int py, int qx, int qy) {
	if (used[px][py] == false || used[qx][qy] == false) {
		return false;
	}

	int hash1 = (px - 1) * W + (py - 1);
	int hash2 = (qx - 1) * W + (qy - 1);
	if (UF.same(hash1, hash2) == true) return true;
	return false;
}

int main() {
	// Step #1. ����
	cin >> H >> W >> Q;

	// Step #2. Union Find �̏�����
	UF.init(H * W);

	// Step #3. �N�G������
	for (int i = 1; i <= Q; i++) {
		int ty; cin >> ty;
		if (ty == 1) {
			int x, y;
			cin >> x >> y;
			query1(x, y);
		}
		if (ty == 2) {
			int xa, xb, ya, yb;
			cin >> xa >> ya >> xb >> yb;
			bool Answer = query2(xa, ya, xb, yb);
			if (Answer == true) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// bool isRedArray[2000][2000];
// int groupNumArray[2000][2000];
// int nextColor = 1;
// int width;
// int height;
// int qNum;

// //色塗りの時の処理
// void coloring(int r, int c){
//     vector<int> adjColors;
//     if(!isRedArray[r][c]){
//         isRedArray[r][c] = true;
//         if(r > 0){
//             if(isRedArray[r-1][c]){
//                 adjColors.push_back(groupNumArray[r-1][c]);
//             }
//         }
//         if(r < width - 1){
//             if(isRedArray[r+1][c]){
//                 adjColors.push_back(groupNumArray[r+1][c]);
//             }
//         }
//         if(c > 0){
//             if(isRedArray[r][c-1]){
//                 adjColors.push_back(groupNumArray[r][c-1]);
//             }            
//         }
//         if(c < height - 1){
//             if(isRedArray[r][c+1]){
//                 adjColors.push_back(groupNumArray[r][c+1]);
//             }            
//         }

//         groupNumArray[r][c] = nextColor;
        

//         if(adjColors.size() > 0){

//             for(int i = 0; i < width; i++){
//                 for(int j = 0; j < height; j++){
//                     for(int p = 0; p < adjColors.size(); p++){
//                         if(groupNumArray[i][j] == adjColors[p]){
//                             groupNumArray[i][j] = nextColor;
//                         }
//                     }
//                 }

//             }
//         }

//         nextColor++;

//     }
// }

// int main(){

//     // for(int i = 0; i < 2000; i++){
//     //     for(int j = 0; j < 2000; j++){
//     //         isRedArray[i][j] = false;
//     //         groupNumArray[i][j] = 0;
//     //     }
//     // }

//     std::cin >> height >> width >> qNum;

//     int t = 0;
//     int r, c;
//     int ra, ca, rb, cb;
//     for(int i = 0; i < qNum; i++){
//         cin >> t;
//         if(t == 1){
//             cin >> r >> c;
//             r--;
//             c--;
//             coloring(r, c);
//         }else{
//             cin >> ra >> ca >> rb >> cb;
//             ra--;
//             ca--;
//             rb--;
//             cb--;
//             if(isRedArray[ra][ca] && isRedArray[rb][cb] 
//                     && groupNumArray[ra][ca] == groupNumArray[rb][cb]){
//                 cout << "Yes" << endl;
//             }else{
//                 cout << "No" << endl;
//             }
//         }
//     }
// }