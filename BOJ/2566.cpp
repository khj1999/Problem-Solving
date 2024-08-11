#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int board[10][10];
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> board[i][j];
        }
    }
    int max_x, max_y, max_num = 0;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if (board[i][j] >= max_num){
                max_num = board[i][j];
                max_x = i + 1; max_y = j + 1;
            }
        }
    }

    cout << max_num << '\n';
    cout << max_x << ' ' << max_y << '\n';

    return 0;   
}