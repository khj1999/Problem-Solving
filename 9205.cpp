#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

struct Location{
    int x;
    int y;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    auto calc = [](Location a, Location b) -> int {
        return abs(a.x - b.x) + abs(a.y - b.y);
    };

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<Location> loc(n + 2);
        for(int i = 0; i < n + 2; i++){
            cin >> loc[i].x >> loc[i].y;
        }
        vector<vector<int>> graph(n + 2);
        for(int i = 0; i < n + 2; i++){
            for(int j = 0; j < n + 2; j++){
                if(calc(loc[i], loc[j]) <= 1000){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        queue<int> q;
        vector<bool> vis(n + 2, false);
        q.push(0);
        vis[0] = true;

        bool ans = false;
        while(!q.empty()){
            int cur = q.front();
            q.pop();

            if(cur == n + 1){
                ans = true;
                break;
            }

            for(int nxt : graph[cur]){
                if(vis[nxt]) continue;
                vis[nxt] = true;
                q.push(nxt);
            }
        }
        cout << (ans ? "happy" : "sad") << "\n";
    }

    return 0;
}