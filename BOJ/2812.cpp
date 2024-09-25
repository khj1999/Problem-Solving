#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, remove_cnt;
    string str, ans = "";
    stack<char> s;
    cin >> n >> remove_cnt;
    cin >> str;
    for(int tmp : str){
        while(!s.empty() && s.top() < tmp && remove_cnt > 0){
            s.pop();
            remove_cnt--;
        }
        s.push(tmp);
    }

    while(remove_cnt > 0){
        s.pop();
        remove_cnt--;
    }

    while(!s.empty()){
        ans += s.top();
        s.pop();
    }

    reverse(ans.begin(), ans.end());

    cout << ans;
    return 0;
}