#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int ans = 0;

int checkCount(vector<vector<int>>& board, vector<vector<int>>& vis, int n, int m){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 0 && !vis[i][j]) cnt++;
        }
    }
    return cnt;
}

void bfs(vector<vector<int>>& board, int n, int m){
    queue<pair<int, int>> q;
    vector<vector<int>> vis(n, vector<int> (m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 2){
                q.push({i, j});
                vis[i][j] = true;
            }
        }
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == 1 || vis[nx][ny]) continue;
            q.push({nx, ny});
            vis[nx][ny] = true;
        }
    }

    ans = max(ans, checkCount(board, vis, n, m));
}

void solve(vector<vector<int>>& board, int n, int m, int wallCount){
    if(wallCount == 3){
        bfs(board, n, m);
    }
    else{
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 0){
                    board[i][j] = 1;
                    solve(board, n, m, wallCount + 1);
                    board[i][j] = 0;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> board(n, vector<int> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    solve(board, n, m, 0);
    cout << ans;

    return 0;
}