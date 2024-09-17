#include <iostream>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<int, bool> mp;
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        mp[tmp] = true;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        int tmp;
        cin >> tmp;
        if(mp.find(tmp) != mp.end()){
            cout << 1 << ' ';
        }
        else{
            cout << 0 << ' ';
        }
    }
    return 0;
}