#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define X first
#define Y second

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    pair<int, int> start;
    vector<vector<int>> board(n, vector<int> (m, 0)), vis(n, vector<int> (m, 0));
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 2) start = {i, j};
        }
    }

    q.push(start);
    vis[start.X][start.Y];

    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] || board[nx][ny] == 0 || board[nx][ny] == 2) continue;

            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] != 0 && !(board[i][j] == 2) && vis[i][j] == 0){
                q.push({i, j});
                vis[i][j] = -1;
                while(!q.empty()){
                    pair<int, int> cur = q.front(); q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(vis[nx][ny] || board[nx][ny] == 0 || board[nx][ny] == 2) continue;

                        vis[nx][ny] = -1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << vis[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}