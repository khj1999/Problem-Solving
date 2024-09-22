#include <iostream>
#include <vector>

using namespace std;
vector<char> ans;
int n;

void solve(vector<string>& grid, int size, int x, int y){
    char standard = grid[x][y];
    bool check = true;
    for(int i = x; i < x + size; i++){
        for(int j = y; j < y + size; j++){
            if(standard != grid[i][j]){
                check = false;
                break;
            }
        }
    }

    if(check){
        ans.push_back(standard);
    }
    else{
        int newSize = size / 2;
        ans.push_back('(');
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                solve(grid, newSize, x + i * newSize, y + j * newSize);
            }
        }
        ans.push_back(')');
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int size = n;
    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }

    solve(grid, size, 0, 0);
    for(auto tmp : ans){
        cout << tmp;
    }
    return 0;
}