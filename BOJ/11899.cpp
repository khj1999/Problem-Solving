#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<char> s;
    string str;
    cin >> str;
    int len = str.length();
    for(int i = 0; i < len; i++){
        if(!s.empty() && s.top() == '(' && str[i] == ')'){
            s.pop();
        }
        else{
            s.push(str[i]);
        }
    }

    cout << s.size() << '\n';

    return 0;
}