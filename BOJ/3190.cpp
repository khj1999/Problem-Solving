#include <iostream>
#include <vector>
#include <utility>
#include <deque>
#include <algorithm>

using namespace std;

int dx[] = {0, 1, 0, -1}; // 오른쪽, 아래, 왼쪽, 위
int dy[] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, l;
    cin >> n;
    cin >> k;

    vector<vector<int>> board(n + 1, vector<int>(n + 1, 0)); // 1-indexed board
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        board[x][y] = 1; // 사과가 있는 위치
    }

    cin >> l;
    vector<pair<int, char>> directions; // 방향 전환 정보
    for (int i = 0; i < l; i++) {
        int sec;
        char order;
        cin >> sec >> order;
        directions.push_back({sec, order});
    }

    deque<pair<int, int>> snake; // 뱀의 위치 (x, y)
    snake.push_front({1, 1}); // 초기 위치
    int dir = 0; // 초기 방향 (오른쪽)
    int time = 0; // 경과 시간
    int index = 0; // 방향 전환 인덱스

    while (true) {
        time++;

        // 뱀의 머리 위치 계산
        int head_x = snake.front().first + dx[dir];
        int head_y = snake.front().second + dy[dir];

        // 벽이나 자기 몸에 부딪히면 게임 종료
        if (head_x < 1 || head_x > n || head_y < 1 || head_y > n || 
            find(snake.begin(), snake.end(), make_pair(head_x, head_y)) != snake.end()) {
            break;
        }

        // 뱀의 머리를 이동
        snake.push_front({head_x, head_y});

        // 사과가 있는지 확인
        if (board[head_x][head_y] == 1) {
            board[head_x][head_y] = 0; // 사과 먹음
        } else {
            // 사과가 없으면 꼬리 위치를 제거
            snake.pop_back();
        }

        // 방향 전환 처리
        if (index < l && directions[index].first == time) {
            if (directions[index].second == 'L') {
                dir = (dir + 3) % 4; // 왼쪽으로 90도 회전
            } else {
                dir = (dir + 1) % 4; // 오른쪽으로 90도 회전
            }
            index++;
        }
    }

    cout << time << '\n'; // 게임 종료 시간 출력

    return 0;
}