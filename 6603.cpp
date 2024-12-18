#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

vector<int> result;

void solve(vector<int>& v, int cnt, int cur){
    if(cnt == 6){
        for(auto iter : result){
            cout << iter << " ";
        }
        cout << "\n";
        return;
    }
    else{
        int len = v.size();
        for(int i = cur; i < len; i++){
            result.push_back(v[i]);
            solve(v, cnt + 1, i + 1);
            result.pop_back();
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;

        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }

        sort(v.begin(), v.end());
        solve(v, 0, 0);
        cout << "\n";
    }

}