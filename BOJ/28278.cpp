#include<iostream>
#include<stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    stack<int> s;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        switch (n){
        case 1:
            int x;
            cin >> x;
            s.push(x);
            break;
        case 2:
            if(s.empty()) cout << -1 << '\n';
            else{
                if(!s.empty()) cout << s.top() << '\n';
                else cout << -1 << '\n';
                s.pop();
            }
            break;
        case 3:
            cout << s.size() << '\n';
            break;
        case 4:
            if(s.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
            break;
        case 5:
            if(!s.empty()) cout << s.top() << '\n';
            else cout << -1 << '\n';
            break;
        default:
            break;
        }
    }

    return 0;
}