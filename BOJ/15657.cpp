#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> result;

void solve(vector<int> v, int n, int cnt){
    int len = v.size();
    if(n == cnt){
        for(auto iter : result){
            cout << iter << " ";
        }
        cout << '\n';
        return;
    }
    else{
        for(int i = 0; i < len; i++){
            if(0 < cnt){
                if(result.back() <= v[i]){
                    result.push_back(v[i]);
                    solve(v, n, cnt + 1);
                    result.pop_back();
                }
            }
            else{
                result.push_back(v[i]);
                solve(v, n, cnt + 1);
                result.pop_back();
            }
        }
    }
    return;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    solve(v, m, 0);
    return 0;
}