#include <iostream>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0;
    cin >> n;

    vector<pair<int, int>> v;
    stack<pair<int, int>> s, s2;

    for(int i = 0; i < n; i++){
        int l, h;
        cin >> l >> h;
        v.push_back({l, h});
    }

    sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b){
        return a.first < b.first;
    });

    for(auto tmp : v){
        if(s.empty()) s.push(tmp);
        if(!s.empty() && s.top().second <= tmp.second){
            ans += (s.top().second * abs(s.top().first - tmp.first));
            s.pop();
            s.push(tmp);
        }
    }
    
    sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b){
        return a.first > b.first;
    });

    for(auto tmp : v){
        if(s2.empty()) s2.push(tmp);
        if(!s2.empty() && s2.top().second < tmp.second){
            ans += (s2.top().second * abs(s2.top().first - tmp.first));
            s2.pop();
            s2.push(tmp);
        }
    }

    if(!s.empty() && !s2.empty() && s.top().first == s2.top().first && s.top().second == s2.top().second){
        ans += 1 * s.top().second;
    }

    cout << ans;
    return 0;
};