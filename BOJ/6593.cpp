#include <iostream>
#include <queue>
#include <cstring>

#define X second.second
#define Y second.first
#define Z first

using namespace std;
int dx[] = {0,0,0,0,1,-1};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {1,-1,0,0,0,0};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        char board[31][31][31];
        int vis[31][31][31];
        memset(vis, 0, sizeof(int) * 31 * 31 * 31);
        int l, r, c;
        queue<pair<int, pair<int, int>>> q;
        cin >> l >> r >> c;
        if(!l && !r && !c) break;

        pair<int, pair<int, int>> finish;
        for(int i = 0; i < l; i++){
            for(int j = 0; j < r; j++){
                for(int k = 0; k < c; k++){
                    cin >> board[i][j][k];
                    if(board[i][j][k] == 'S'){
                        q.push({i, {j, k}});
                        vis[i][j][k] = 1;
                    }
                    else if(board[i][j][k] == 'E'){
                        finish = {i, {j, k}};
                    }
                }
            }
        }

        while(!q.empty()){
            auto cur = q.front(); q.pop();
            for(int dir = 0; dir < 6; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                int nz = cur.Z + dz[dir];
                if(0 > nx || nx >= c || 0 > ny || ny >= r || 0 > nz || nz >= l) continue;
                if(board[nz][ny][nx] == '#' || vis[nz][ny][nx]) continue;
                q.push({nz, {ny, nx}});
                vis[nz][ny][nx] = vis[cur.Z][cur.Y][cur.X] + 1;
            }
        }

        // for(int i = 0; i < l; i++){
        //     for(int j = 0; j < r; j++){
        //         for(int k = 0; k < c; k++){
        //             cout << vis[i][j][k] << ' ';
        //         }
        //         cout << '\n';
        //     }
        //     cout << "\n\n";
        // }

        if(vis[finish.Z][finish.Y][finish.X]) cout << "Escaped in " << vis[finish.Z][finish.Y][finish.X] - 1 << " minute(s)." << '\n';
        else cout << "Trapped!" << '\n';
    }
    return 0;
}