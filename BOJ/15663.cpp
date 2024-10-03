#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n, m;
int arr[10];
int result[10];
bool check[10];
map<string, bool> mp;

void solve(int cnt){
    if(cnt == m){
        string tmp;
        for(int i = 0; i < m; i++){
            //cout << result[i] << ' ';
            tmp.append(to_string(result[i]));
            tmp.append(" ");
        }
        if(mp[tmp]) return;
        cout << tmp;
        mp[tmp] = true;
        
        cout << '\n';
        return;
    }
    else{
        for(int i = 0; i < n; i++){
            if(!check[i]){
                check[i] = true;
                result[cnt] = arr[i];
                solve(cnt + 1);
                check[i] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    solve(0);
    return 0;
}