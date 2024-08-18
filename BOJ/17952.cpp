#include <iostream>
#include <stack>
using namespace std;

#define SCORE first
#define TIME second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0;
    stack<pair<int, int>> s;
    cin >> n;

    for(int i = 0; i < n; i++){
        int order;
        cin >> order;
        if(order == 1){
            int a, t;
            cin >> a >> t;
            --t;
            if(t == 0) ans += a;
            else s.push({a, t});
        }
        else{
            if(s.empty()) continue;
            pair<int, int> tmp = s.top();
            tmp.TIME--;
            if(tmp.TIME == 0){
                s.pop();
                ans += tmp.SCORE;
            }
            else{
                s.pop();
                s.push(tmp);
            }
        }
    }
    cout << ans;
    return 0;
}