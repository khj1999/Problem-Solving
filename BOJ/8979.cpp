#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Medal {
    int gold;
    int silver;
    int bronze;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, Medal>> v;
    for(int i = 0; i < n; i++){
        int no;
        Medal tmp;
        cin >> no >> tmp.gold >> tmp.silver >> tmp.bronze;
        v.push_back({no, tmp});
    }
    sort(v.begin(), v.end(), [](pair<int, Medal> a, pair<int, Medal> b) -> bool{
        if(a.second.gold == b.second.gold){
            if(a.second.silver == b.second.silver){
                return a.second.bronze > b.second.bronze;
            }
            return a.second.silver > b.second.silver;
        }
        return a.second.gold > b.second.gold;
    });

    int ans = 1;
    auto check = [](Medal a, Medal b){
        return a.gold == b.gold && a.silver == b.silver && a.bronze == b.bronze;
    };
    for(int i = 0; i < n; i++){
        if(i > 0 && check(v[i - 1].second, v[i].second)){

        }
        else{
            ans = i + 1;
        }
        if(v[i].first == k){
            cout << ans;
            break;
        }
    }
    return 0;
}