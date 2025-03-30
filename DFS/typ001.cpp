#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<vector<char>> board;
vector<vector<bool>> visited;
bool is_found = false;
vector<pair<int, int>> offset;

void dfs(pair<int, int> pos){

    if(board[pos.first][pos.second] == '#'){
        return;
    }
    if(board[pos.first][pos.second] == 's' || board[pos.first][pos.second] == '.'){
        visited[pos.first][pos.second] = true;
        for(int i = 0; i < 4; i ++){
            if(pos.first + offset[i].first >= 0 && pos.first + offset[i].first < H 
                    && pos.second + offset[i].second >= 0 && pos.second + offset[i].second < W
                    && !(visited[pos.first + offset[i].first][pos.second + offset[i].second])){
                dfs({pos.first + offset[i].first, pos.second + offset[i].second});
            }
        }
        visited[pos.first][pos.second] = false;
        return;
    }
    if(board[pos.first][pos.second] == 'g'){
        is_found = true;
        return;
    }    

}

int main(){
    offset.emplace_back(-1, 0);
    offset.emplace_back(1, 0);
    offset.emplace_back(0, -1);
    offset.emplace_back(0, 1);

    cin >> H >> W;

    pair<int, int> startpos;
    
    for(int i = 0; i < H; i++){
        board.push_back({});
        visited.push_back({});
        for(int j = 0; j < W; j++){
            char str;
            cin >> str;
            board[i].push_back(str);
            visited[i].push_back(false);
            if(str == 's') startpos = {i, j};
        }
    }

    // for(int i = 0; i < H; i++){
    //     for(int j = 0; j < W; j++){
    //         cout << board[i][j];
    //     }
    //     cout << endl;
    // }

    dfs(startpos);

    if(is_found) cout << "Yes" << endl;
    else cout << "No" << endl;
}