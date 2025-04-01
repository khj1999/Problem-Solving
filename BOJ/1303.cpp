#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int solve(const int M, const int N, char target, vector<vector<char>>& board, vector<vector<int>>& vis){
    int calc = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(board[i][j] != target || vis[i][j] != 0) continue;
            queue<pair<int, int>> q;
            int power_cnt = 1;
            q.push({i, j});
            vis[i][j] = power_cnt;

            while(!q.empty()){
                auto cur = q.front(); q.pop();
                power_cnt++;
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                    if(board[nx][ny] != target || vis[nx][ny] != 0) continue;
                    q.push({nx, ny});
                    vis[nx][ny] = power_cnt;
                }
            }
            power_cnt--;
            calc += (power_cnt * power_cnt);
        }
    }
    return calc;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> M >> N;
    vector<vector<char>> board(N, vector<char> (M));
    vector<vector<int>> vis_B(N, vector<int> (M, 0));
    vector<vector<int>> vis_W(N, vector<int> (M, 0));

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    cout << solve(M, N, 'W', board, vis_W) << ' ';
    cout << solve(M, N, 'B', board, vis_B);
    return 0;
}