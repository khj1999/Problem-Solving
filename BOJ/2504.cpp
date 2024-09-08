#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    stack<char> s;
    int tmp = 1, ans = 0, len;
    cin >> str;

    len = str.length();

    for(int i = 0; i < len; i++){
        if(str[i] == '('){
            s.push(str[i]);
            tmp *= 2;
        }
        else if(str[i] == '['){
            s.push(str[i]);
            tmp *= 3;
        }
        else{
            if(str[i] == ')'){
                if(s.empty() || s.top() != '('){
                    ans = 0;
                    break;
                }
                if(str[i - 1] == '(') ans += tmp;
                s.pop();
                tmp /= 2;
            }
            else if(str[i] == ']'){
                if(s.empty() || s.top() != '['){
                    ans = 0;
                    break;
                }
                if(str[i - 1] == '[') ans += tmp;
                s.pop();
                tmp /= 3;
            }
        }
    }
    if(!s.empty()) ans = 0;
    cout << ans;
    return 0;
}