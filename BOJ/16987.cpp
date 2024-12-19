#include <iostream>
#include <vector>
using namespace std;

struct EGG {
    int Durability;
    int weight;
};

int n, ans = 0;

void solve(vector<EGG>& eggs, int cur) {
    if (cur == n) {
        int broken = 0;
        for (auto egg : eggs) {
            if (egg.Durability <= 0) broken++;
        }
        ans = max(ans, broken);
        return;
    }

    if (eggs[cur].Durability <= 0) {
        solve(eggs, cur + 1);
        return;
    }

    bool hit = false;
    for (int i = 0; i < n; i++) {
        if (i == cur || eggs[i].Durability <= 0) continue;

        hit = true;
        eggs[cur].Durability -= eggs[i].weight;
        eggs[i].Durability -= eggs[cur].weight;

        solve(eggs, cur + 1);

        eggs[cur].Durability += eggs[i].weight;
        eggs[i].Durability += eggs[cur].weight;
    }

    if (!hit) solve(eggs, cur + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<EGG> eggs(n);

    for (int i = 0; i < n; i++) {
        cin >> eggs[i].Durability >> eggs[i].weight;
    }

    solve(eggs, 0);

    cout << ans << "\n";
    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// struct EGG {
//     int Durability; // 내구도
//     int weight;     // 무게
// };

// int ans = 0; // 최대로 깨진 계란 수

// void solve(vector<EGG>& eggs, int n, int cur, int check) {
//     // 모든 계란을 확인했다면 최대 값 갱신
//     if (cur == n) {
//         ans = max(ans, check);
//         return;
//     }

//     // 현재 계란이 이미 깨졌으면 다음 계란으로 넘어감
//     if (eggs[cur].Durability <= 0) {
//         solve(eggs, n, cur + 1, check);
//         return;
//     }

//     bool anyHit = false; // 현재 계란이 다른 계란을 친 적이 있는지 확인

//     for (int i = 0; i < n; i++) {
//         if (i == cur || eggs[i].Durability <= 0) continue; // 자기 자신이나 깨진 계란 제외

//         // 현재 계란과 다른 계란 충돌
//         eggs[cur].Durability -= eggs[i].weight;
//         eggs[i].Durability -= eggs[cur].weight;

//         int brokenCount = 0; // 충돌로 인해 새로 깨진 계란 수
//         if (eggs[cur].Durability <= 0) brokenCount++;
//         if (eggs[i].Durability <= 0) brokenCount++;

//         solve(eggs, n, cur + 1, check + brokenCount); // 깨진 계란 수 반영

//         // 상태 복구
//         eggs[cur].Durability += eggs[i].weight;
//         eggs[i].Durability += eggs[cur].weight;

//         anyHit = true; // 충돌이 발생했음을 기록
//     }

//     // 어떤 계란도 치지 않았다면 그냥 다음 단계로 넘어감
//     if (!anyHit) {
//         solve(eggs, n, cur + 1, check);
//     }
// }

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int n;
//     cin >> n;
//     vector<EGG> eggs(n);

//     for (int i = 0; i < n; i++) {
//         cin >> eggs[i].Durability >> eggs[i].weight;
//     }

//     solve(eggs, n, 0, 0); // 초기 값: 깨진 계란 수 0
//     cout << ans;
//     return 0;
// }
