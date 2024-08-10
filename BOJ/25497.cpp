#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; string str;
    int ans = 0;
    stack<char> lr, sk;
    cin >> n;
    cin >> str;

    for(int i = 0; i < n; i++){
        if(str[i] == 'L' || str[i] == 'S'){
            if(str[i] == 'L') lr.push(str[i]);
            else sk.push(str[i]);
        }
        else if(str[i] == 'R' || str[i] == 'K'){
            if(str[i] == 'R'){
                if(!lr.empty()){
                    ans++;
                    lr.pop();
                }
                else break;
            }
            else {
                if(!sk.empty()){
                    ans++;
                    sk.pop();
                }
                else break;
            }
        }
        else {
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}