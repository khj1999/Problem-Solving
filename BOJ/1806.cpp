#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    int ans = INT32_MAX;
    for(int st = 0, en = 1, total = v[0]; st < n; st++){
        while(en < n && total < s){
            en++;
            if(en != n) total += v[en];
        }
        if(en == n) break;
        ans = min(ans, en - st + 1);
        total -= v[st];
    }
    if(ans == INT32_MAX) ans = 0;
    cout << ans;
    return 0;
}