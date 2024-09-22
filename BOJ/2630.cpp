#include <iostream>
#include <vector>

using namespace std;

int blueCnt = 0, whiteCnt = 0;

void solve(vector<vector<int>>& v, int size, int x, int y){
    int check = true;
    int standard = v[x][y];

    for(int i = x; i < x + size; i++){
        for(int j = y; j < y + size; j++){
            if(standard != v[i][j]){
                check = false;
                break;
            }
        }
    }

    if(check){
        if(standard) blueCnt++;
        else whiteCnt++;
    }
    else{
        int newSize = size / 2;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                solve(v, newSize, x + i * newSize, y + j * newSize);
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int> (n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }

    solve(v, n, 0, 0);
    cout << whiteCnt << '\n';
    cout << blueCnt << '\n';

    return 0;
}