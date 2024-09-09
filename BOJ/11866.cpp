#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    vector<int> ans;
    queue<int> q;

    cin >> n >> k;

    for(int i = 1; i < n + 1; i++) q.push(i);
    int counter = 0;
    while(!q.empty()){
        if(counter == k - 1){
            ans.push_back(q.front());
            q.pop();
            counter = 0;
        }
        else{
            int tmp = q.front();
            q.pop();
            q.push(tmp);
            counter++;
        }
    }
    int len = ans.size();
    cout << "<";
    for(int i = 0; i < len; i++){
        if(i == len - 1) cout << ans[i] << ">";
        else cout << ans[i] << ", ";
    }
    
    return 0;
}