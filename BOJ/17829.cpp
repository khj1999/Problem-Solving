#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<vector<int>>& v, int size, int x, int y){
    if(size == 2){
        vector<int> tmp;
        for(int i = x; i < x + size; i++){
            for(int j = y; j < y + size; j++){
                tmp.push_back(v[i][j]);
            }
        }
        sort(tmp.begin(), tmp.end());
        return tmp[2];
    }
    else{
        int halfSize = size / 2;
        vector<int> tmp;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                tmp.push_back(solve(v, halfSize, x + i * halfSize, y + j * halfSize));
            }
        }
        sort(tmp.begin(), tmp.end());
        return tmp[2];
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
    cout << solve(v, n, 0, 0);
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// // 주어진 2x2 블록에서 두 번째로 큰 값을 찾는 함수
// int calc(int a, int b, int c, int d) {
//     vector<int> tmp = {a, b, c, d};
//     sort(tmp.begin(), tmp.end());
//     return tmp[2];
// }

// int main() {
//     int n;
//     cin >> n;

//     // NxN 행렬 입력
//     vector<vector<int>> v(n, vector<int>(n));
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             cin >> v[i][j];
//         }
//     }

//     // 2x2 풀링 연산을 반복적으로 수행
//     while (n > 1) {
//         // 새로운 (N/2)x(N/2) 행렬로 변환
//         vector<vector<int>> newV(n / 2, vector<int>(n / 2));
//         for (int i = 0; i < n; i += 2) {
//             for (int j = 0; j < n; j += 2) {
//                 // 현재 2x2 블록에서 두 번째로 큰 값을 찾아서 새로운 행렬에 저장
//                 newV[i / 2][j / 2] = calc(v[i][j], v[i][j+1], v[i+1][j], v[i+1][j+1]);
//             }
//         }
//         // 행렬 크기를 절반으로 줄임
//         v = newV;
//         n /= 2;
//     }

//     // 마지막 남은 값 출력
//     cout << v[0][0] << endl;

//     return 0;
// }
