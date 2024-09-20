#include <iostream>
#include <queue>
#include <vector>
#define X first
#define Y second

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for(int sequence = 0; sequence < n; sequence++) {
        int w, h;
        cin >> w >> h;
        
        vector<string> board(h);
        vector<vector<int>> dis(h, vector<int>(w, 0)), fire_vis(h, vector<int>(w, 0));
        
        queue<pair<int, int>> q_fire;
        queue<pair<int, int>> q_human;
        pair<int, int> human;
        
        for (int i = 0; i < h; i++) {
            cin >> board[i];
            for (int j = 0; j < w; j++) {
                if (board[i][j] == '*') {
                    q_fire.push({i, j});
                    fire_vis[i][j] = 1;
                }
                if (board[i][j] == '@') {
                    q_human.push({i, j});
                    dis[i][j] = 1;
                }
            }
        }
        
        bool escape = false;
        
        while (!q_fire.empty()) {
            auto cur = q_fire.front(); q_fire.pop();
            int x = cur.X;
            int y = cur.Y;
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (fire_vis[nx][ny] || board[nx][ny] == '#') continue;
                
                fire_vis[nx][ny] = fire_vis[x][y] + 1;
                q_fire.push({nx, ny});
            }
        }
        
        while (!q_human.empty() && !escape) {
            auto cur = q_human.front(); q_human.pop();
            int x = cur.X;
            int y = cur.Y;

            if (x == 0 || x == h - 1 || y == 0 || y == w - 1) {
                cout << dis[x][y] << '\n';
                escape = true;
                break;
            }
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (dis[nx][ny] || board[nx][ny] == '#' || (fire_vis[nx][ny] != 0 && fire_vis[nx][ny] <= dis[x][y] + 1)) continue;
                
                dis[nx][ny] = dis[x][y] + 1;
                q_human.push({nx, ny});
            }
        }
        
        if (!escape) {
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}