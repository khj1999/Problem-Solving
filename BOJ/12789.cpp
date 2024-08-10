#include <iostream>
#include <stack>
using namespace std;

int arr[1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int cnt_num = 1;
    stack<int> s;

    cin >> n;

    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++){
        s.push(arr[i]);
        while (!s.empty() && s.top() == cnt_num){
            s.pop();
            cnt_num++;
        }
    }

    if(s.empty()) cout << "Nice" << '\n';
    else cout << "Sad" << '\n';

    return 0;
}