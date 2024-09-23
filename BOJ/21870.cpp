#include <iostream>
#include <vector>
using namespace std;

int gcd(int x, int y) {
    if (y == 0) return x;
    else return gcd(y, x % y);
}

int solve(vector<int>& v, int left, int right){
    if(left == right) return v[left];
    int mid = (right + left - 1) / 2;
    int left_gcd = v[left], right_gcd = v[mid + 1];

    for(int i = left + 1; i <= mid; i++){
        left_gcd = gcd(left_gcd, v[i]);
    }
    for(int i = mid + 2; i <= right; i++){
        right_gcd = gcd(right_gcd, v[i]);
    }
    int tmp1 = left_gcd + solve(v, mid + 1, right);
    int tmp2 = right_gcd + solve(v, left, mid);

    return max(tmp1, tmp2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int ans = solve(v, 0, n - 1);
    cout << ans << "\n";
    return 0;
}