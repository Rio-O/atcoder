#include <iostream>
#include <vector>

using namespace std;

int main(){
    int H;
    int W;

    cin >> H >> W;

    std::vector<vector<int>> input_matrix;
    for(int i = 0; i < H; i++){
        input_matrix.push_back({});
        for(int j = 0; j < W; j++){
            int a;
            cin >> a;
            input_matrix[i].push_back(a);
        }
    }

    //行ごとの合計を出すパート
    std::vector<int> low_sum;
    for(int i = 0; i < H; i++){
        low_sum.push_back(0);
        for(int j = 0; j < W; j++){
            low_sum[i] += input_matrix[i][j];
        }
    }

    //列ごとの合計を出すパート
    std::vector<int> column_sum;
    for(int j = 0; j < W; j++){
        column_sum.push_back(0);
        for(int i = 0; i < H; i++){
            column_sum[j] += input_matrix[i][j];
        }
    }

    //出力行列を作るパート
    std::vector<vector<int>> output_matrix;
    for(int i = 0; i < H; i++){
        output_matrix.push_back({});
        for(int j = 0; j < W; j++){
            output_matrix[i].push_back(low_sum[i] + column_sum[j] - input_matrix[i][j]);
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            std::cout << output_matrix[i][j] << " ";
        }
        std::cout << std::endl; 
    }

}