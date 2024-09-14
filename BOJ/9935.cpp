#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str, check;
    stack<char> s;
    cin >> str;
    cin >> check;
    int str_len = str.length();
    int check_len = check.length();
    vector<char> tmp, ans;

    for(int i = 0; i < str_len; i++){
        s.push(str[i]);

        if((s.top() == check[check_len - 1]) && (s.size() >= check_len)){
            for(int i = 0; i < check_len; i++){
                if(!s.empty()){
                    tmp.push_back(s.top());
                    s.pop();
                }
            }
            reverse(tmp.begin(), tmp.end());

            bool judge = true;
            for(int i = 0; i < check_len; i++){
                if(check[i] != tmp[i]){
                    judge = false;
                    break;
                }
            }
            if(!judge){;
                for(int i = 0; i < check_len; i++){
                    s.push(tmp[i]);
                }
            }
            tmp.clear();
        }
    }
    if(s.empty()){
        cout << "FRULA";
    }
    else{
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        for(auto ch : ans){
            cout << ch;
        }
    }

    return 0;
}