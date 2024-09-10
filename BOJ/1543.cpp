#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cur;
    string str, pattern;
    getline(cin, str);
    getline(cin, pattern);

    int pattern_len = pattern.length();
    int pos = 0, ans = 0;
    while(1){
        if((pos = str.find(pattern, pos)) != -1){
            ans++;
            pos += pattern_len;
        }
        else{
            break;
        }
    }
    cout << ans;
    return 0;
}