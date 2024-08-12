#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define student first
#define menu second

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    queue<pair<int, int>> q;
    vector<int> ans_a, ans_b, ans_c;
    
    for(int i = 0; i < n; i++){
        int tmp, a, b;
        cin >> tmp;
        if(tmp == 1){
            cin >> a >> b;
            q.push({a, b});
        }
        else{
            cin >> b;
            if(b == q.front().menu){
                ans_a.push_back(q.front().student);
            }
            else {
                ans_b.push_back(q.front().student);
            }
            q.pop();
        }
    }

    while(!q.empty()){
        ans_c.push_back(q.front().student);
        q.pop();
    }

    sort(ans_a.begin(), ans_a.end());
    sort(ans_b.begin(), ans_b.end());
    sort(ans_c.begin(), ans_c.end());

    if(ans_a.size() == 0){
        cout << "None\n";
    }
    else{
        for(auto i : ans_a) cout << i << ' ';
        cout << '\n';
    }


    if(ans_b.size() == 0){
        cout << "None\n";
    }
    else{
        for(auto i : ans_b) cout << i << ' ';
        cout << '\n';
    }


    if(ans_c.size() == 0){
        cout << "None\n";
    }
    else{
        for(auto i : ans_c) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}