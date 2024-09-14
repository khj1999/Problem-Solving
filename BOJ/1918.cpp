#include <iostream>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<char> s;
    string str;
    cin >> str;
    bool judge = false;
    int len = str.length();

    auto cmp = [](char c) -> int {
        if(c == '*' || c == '/'){
            return 2;
        }
        else if(c == '+' || c == '-'){
            return 1;
        }
        return 0;
    };

    for(int i = 0; i < len; i++){
        if(isalpha(str[i])){
            cout << str[i];
        }
        else if (str[i] == '('){
            s.push(str[i]);
        }
        else if (str[i] == ')'){
            while(!s.empty() && s.top() != '('){
                cout << s.top();
                s.pop();
            }
            s.pop();
        }
        else{
            while(!s.empty() && cmp(s.top()) >= cmp(str[i])){
                cout << s.top();
                s.pop();
            }
            s.push(str[i]);
        }
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
    return 0;
}