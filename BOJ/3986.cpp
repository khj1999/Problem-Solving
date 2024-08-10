#include<iostream>
#include<stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    int ans = 0;
    cin >> t;

    for (int i = 0; i < t; i++){
        stack<char> s;
        string str;
        cin >> str;
        int len = str.length();
        for(int i = 0; i < len; i++){
            if(!s.empty() && s.top() == str[i]){
                s.pop();
            }
            else s.push(str[i]);
        }

        if(s.empty()) ans++;
    }

    cout << ans << '\n';
    return 0;
}