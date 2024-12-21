#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(range) for(int i = 0; i < range; i++)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);

    FOR(n){
        cin >> v[i];
    }
    int ans = INT32_MAX;
    sort(v.begin(), v.end());
    FOR(n){
        int idx = lower_bound(v.begin(), v.end(), v[i] + m) - v.begin();
        if(n <= idx) continue;
        if(ans > v[idx] - v[i]){
            ans = v[idx] - v[i];
        }
    }
    
    cout << ans;
    return 0;
}