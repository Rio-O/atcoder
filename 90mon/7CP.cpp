#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearchAbs(int key, std::vector<int> vec){
    int left = 0;
    int right = (int)vec.size() - 1;
    if(vec[left] > key) return vec[left] - key;
    if(vec[right] < key) return key - vec[right];

    while(left + 1 < right){
        int mid = left + (right - left) / 2;
        if(vec[mid] == key) return mid;
        else if(vec[mid] > key) right = mid;
        else if(vec[mid] < key) left = mid;
    }
    //std::cout << "left " << left << std::endl;
    //std::cout << "right " << right << std::endl;
    //return -1;
    return (key > (vec[left] + vec[right]) / 2)? vec[right] - key : key - vec[left];
}

int main(){
    int N;
    cin >> N;
    vector<int> rating_class;
    for(int i = 0; i < N; i++){
        int rating;
        cin >> rating;
        rating_class.push_back(rating);
    }
    int Q;
    cin >> Q;
    vector<int> rating_player;
    for(int i = 0; i < Q; i++){
        int rating;
        cin >> rating;
        rating_player.push_back(rating);
    }

    //std::cout << "input ok" << std::endl;

    sort(rating_class.begin(), rating_class.end());

    //二分探索パート
    for(int i = 0; i < Q; i++){
        std::cout << binarySearchAbs(rating_player[i], rating_class) << std::endl;
    }
}