#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    vector<bool> vis(n + 1);
    cin >> m;

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    vis[1] = true;

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int len = graph[cur].size();
        for(int i = 0; i < len; i++){
            int next = graph[cur][i];
            if(vis[next]) continue;
            q.push(graph[cur][i]);
            vis[next] = true;
        }
    }
    int ans = -1;
    for (auto tmp : vis){
        if(tmp) ans++;
    }
    cout << ans;
    return 0;
}