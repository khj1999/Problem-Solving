#include <iostream>
#include <queue>
#include <cstring>
#define X first
#define Y second

using namespace std;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, ans = 0;
    cin >> n >> m;
    vector<string> board(n);
    for(int i = 0; i < n; i++){
        cin >> board[i];
    }

    auto check = [n, m](int dis[51][51]) -> int {
        int max = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(max < dis[i][j]){
                    max = dis[i][j];
                }
            }
        }
        return max;
    };

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 'W') continue;
            queue<pair<int, int>> q;
            int dis[51][51];
            memset(dis, 0, sizeof(int) * 51 * 51);
            q.push({i, j});
            dis[i][j] = 1;

            while(!q.empty()){
                auto cur = q.front(); q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(board[nx][ny] == 'W' || dis[nx][ny]) continue;
                    q.push({nx, ny});
                    dis[nx][ny] = dis[cur.X][cur.Y] + 1;
                }
            }
            
            int max = check(dis);
            if(ans < max){
                ans = max;
            }
        }
    }

    cout << ans - 1;
    return 0;
}
