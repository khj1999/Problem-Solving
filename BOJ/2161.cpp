#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> q, ans_q;

    int n;
    
    cin >> n;
    for(int i = 0; i < n; i++) q.push(i + 1);
    while(!q.empty()){
        ans_q.push(q.front());
        q.pop();
        int tmp = q.front();
        if(q.empty()) break;
        else{
            q.pop();
            q.push(tmp);
        }
    }

    while(!ans_q.empty()){
        cout << ans_q.front() << ' ';
        ans_q.pop();
    }

    return 0;
}