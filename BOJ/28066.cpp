#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    queue<int> q;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }
    while(1){
        int tmp = q.front();
        if(q.size() == 1) break;
        if(q.size() < k){
            while(!q.empty()) q.pop();
            q.push(tmp);
        }
        else{
            for(int i = 0; i < k; i++){
                q.pop();
            }
            q.push(tmp);
        }
    }
    cout << q.front();
    return 0;
}