#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void solve(string& str, int pos, int len){
    if(len == 0) return;
    int newLen = len / 3;
    int tmp = pos + newLen;
    for(int i = tmp; i < tmp + newLen; i++){
        str[i] = ' ';
    }
    solve(str, pos, newLen);
    solve(str, tmp + newLen, newLen);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    auto init = [](int len) -> string {
        string str = "";
        for(int i = 0; i < len; i++){
            str.append("-");
        }
        return str;
    };

    while(cin >> n){
        n = (int)pow(3, n);
        string str = init(n);
        solve(str, 0, n);
        cout << str << '\n';
    }
    return 0;
}