#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, t;
    cin >> n >> a >> t;
    int tmp = a > t ? a - t : t - a;
    if(n - (a + t) > tmp){
        cout << "No" << '\n';
    }
    else{
        cout << "Yes" << '\n';
    }
}