#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> st_Initial, st_Washed, st_Clean;
    int n;
    cin >> n;
    while(n > 0){
        st_Initial.push(n);
        n--;
    }
    while(!st_Initial.empty() || !st_Washed.empty()){
        int order, dish_cnt;
        cin >> order >> dish_cnt;
        if(order == 1){
            while(dish_cnt > 0){
                st_Washed.push(st_Initial.top());
                st_Initial.pop();
                dish_cnt--;
            }
        }
        else{
            while(dish_cnt > 0){
                st_Clean.push(st_Washed.top());
                st_Washed.pop();
                dish_cnt--;
            }
        }
    }
    while(!st_Clean.empty()){
        cout << st_Clean.top() << '\n';
        st_Clean.pop();
    }
    return 0;
}