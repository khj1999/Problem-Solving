#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    map<string, bool> mp;
    cin >> n;
    auto check_commute = [](string str) -> bool{
        if(str == "enter") return true;
        else return false;
    };

    for(int i = 0; i < n; i++){
        string name, check;
        cin >> name >> check;
        mp[name] = check_commute(check);
    }

    vector<pair<string, bool>> ans(mp.begin(), mp.end());

    sort(ans.begin(), ans.end(), [](pair<string, bool> tmp1, pair<string, bool> tmp2) -> bool{
        return tmp1.first > tmp2.first;
    });

    for(auto tmp : ans){
        if(tmp.second){
            cout << tmp.first << '\n';
        }
    }
    return 0;
}