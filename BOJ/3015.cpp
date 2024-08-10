#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define ll long long
#define height first
#define count second 


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int, int>> s;
    ll ans = 0;

    int n;
    cin >> n;

    vector<int> h(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }

    for(int i = 0; i < n; i++){
        int cnt = 1;
        while(!s.empty() && s.top().height <= h[i]){
            ans += s.top().count;
            if (s.top().height == h[i]){
                cnt += s.top().count;
            }
            s.pop();
        }
        if(!s.empty()){
            ans += 1;
        }
        s.push({h[i], cnt});
    }
    cout << ans << '\n';
    return 0;
}