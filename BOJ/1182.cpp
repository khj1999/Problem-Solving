#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ans = 0;
vector<int> result;

void solve(vector<int>& v, int s, int n, int cnt, int cur){
    if(cnt == n){
        int sum = 0;
        if(!result.empty()){
            for(auto iter : result){
                sum += iter;
            }
        }
        if(sum == s) ans++;
        return;
    }
    else{
        int len = v.size();
        for(int i = cur; i < len; i++){
            result.push_back(v[i]);
            solve(v, s, n, cnt + 1, i + 1);
            result.pop_back();
        }
    }
    return;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    for(int i = 1; i <= n; i++){
        solve(v, s, i, 0, 0);
    }
    cout << ans;
    return 0;
}