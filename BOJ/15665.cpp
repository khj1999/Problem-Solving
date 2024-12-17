#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> result;
map<vector<int>, bool> check;

void solve(vector<int>& v, int n, int cnt, int cur) {
    if (cnt == n) {
        if (check.find(result) == check.end()) {
            for (int iter : result) {
                cout << iter << " ";
            }
            cout << '\n';
            check[result] = true;
        }
        return;
    }
    for (int i = cur; i < v.size(); i++) {
        if (cnt > 0) {
            if (result.back() <= v[i]) {
                result.push_back(v[i]);
                solve(v, n, cnt + 1, i + 1);
                result.pop_back();
            }
        } else {
            result.push_back(v[i]);
            solve(v, n, cnt + 1, i + 1);
            result.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    solve(v, m, 0, 0);

    return 0;
}
