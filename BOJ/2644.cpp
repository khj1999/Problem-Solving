#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1, vector<int> (n, 0));
    vector<int> dis(n + 1, 0);
    int x, y, m;
    cin >> x >> y;
    cin >> m;
    for(int i = 0; i < m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        graph[tmp1].push_back(tmp2);
        graph[tmp2].push_back(tmp1);
    }

    queue<int> q;

    q.push(x);
    dis[x] = 1;

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int len = graph[cur].size();
        for(int i = 0; i < len; i++){
            int next = graph[cur][i];
            if(dis[next]) continue;
            q.push(next);
            dis[next] = dis[cur] + 1;
        }
    }
    if(dis[y]) cout << dis[y] - 1;
    else cout << -1;

    return 0;   
}