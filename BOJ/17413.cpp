#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    getline(cin, str);

    int len = str.length();
    bool tag = false;
    stack<char> s;

    for (int i = 0; i < len; i++){
        if (str[i] == ' ' || str[i] == '<' || str[i] == '>'){
            if(str[i] == '<'){
                if(!s.empty()){
                    while(!s.empty()){
                        if(s.top() == ' '){
                            s.pop();
                        }
                        else{
                            char tmp = s.top();
                            s.pop();
                            cout << tmp;   
                        }
                    }
                }
                tag = true;
                cout << str[i];
            }
            else if(str[i] == '>'){
                tag = false;
                cout << str[i];
            }
            else if(!tag){
                while(!s.empty()){
                    char tmp = s.top();
                    s.pop();
                    cout << tmp;
                }
                s.push(' ');
            }
            else{
                cout << str[i];
            }
        }
        else if(i == len - 1){
            s.push(str[i]);
            while(!s.empty()){
                if(s.top() == ' '){
                    s.pop();
                }
                else{
                    char tmp = s.top();
                    s.pop();
                    cout << tmp;   
                }
            }
        }
        else if(tag){
            cout << str[i];
        }
        else{
            if(s.empty()) s.push(' ');
            s.push(str[i]);
        }
    }
    return 0;
}