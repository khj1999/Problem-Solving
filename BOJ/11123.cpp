#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int H, W;
        cin >> H >> W;
        vector<vector<char>> board(H, vector<char> (W));
        vector<vector<int>> vis(H, vector<int> (W, 0));
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                cin >> board[i][j];
            }
        }

        queue<pair<int, int>> q;
        int area_cnt = 0;
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                if(board[i][j] != '#' || vis[i][j] != 0) continue;
                q.push({i, j});
                vis[i][j] = area_cnt++;

                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
                        if(board[nx][ny] == '.' || vis[nx][ny] != 0) continue;
                        q.push({nx, ny});
                        vis[nx][ny] = area_cnt;
                    }
                }
            }
        }
        cout << area_cnt << '\n';
    }
    return 0;
}