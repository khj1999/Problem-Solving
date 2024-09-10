#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, w, l;
    queue<int> q;
    vector<pair<int, int>> bridge;
    cin >> n >> w >> l;
    
    for (int i = 0; i < n; i++) {
        int tmp; 
        cin >> tmp;
        q.push(tmp);
    }

    int ans = 0;

    // 무게 체크
    auto check = [](const vector<pair<int, int>> v) {
        int sum = 0;
        for (const auto element : v) {
            sum += element.first;
        }
        return sum;
    };

    // 반복마다 시간 감소
    auto calc = [](vector<pair<int, int>>& v) {
        for (auto& element : v) {
            element.second--;
        }
    };

    while (!q.empty() || !bridge.empty()) {
        ans++;
        calc(bridge);

        // 지나간 트럭은 다리에서 제거
        bridge.erase(remove_if(bridge.begin(), bridge.end(), [](pair<int, int> n) {
            return n.second == 0;
        }), bridge.end());

        // 다리에 트럭 추가
        if (!q.empty() && (bridge.size() < w) && (check(bridge) + q.front() <= l)) {
            bridge.push_back({q.front(), w});
            q.pop();
        }
    }

    cout << ans;
    return 0;
}
