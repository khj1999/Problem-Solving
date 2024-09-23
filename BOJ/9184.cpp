#include <iostream>
using namespace std;

int memo[101][101][101];

int solve(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    if(a > 20 || b > 20 || c > 20){
        if(!memo[a + 50][b + 50][c + 50]){
            memo[a + 50][b + 50][c+ 50] = solve(20, 20, 20);
        }
        else{
            return memo[a + 50][b + 50][c + 50];
        }
    }
    if(a < b && b < c) {
        if(!memo[a + 50][b + 50][c + 50]){
            memo[a + 50][b + 50][c + 50] = solve(a, b, c-1) + solve(a, b-1, c-1) - solve(a, b-1, c);
        }
        else{
            return memo[a + 50][b + 50][c + 50];
        }
    }
    if(memo[a + 50][b + 50][c + 50]){
        return memo[a + 50][b + 50][c + 50];
    }
    return memo[a + 50][b + 50][c + 50] = solve(a-1, b, c) + solve(a-1, b-1, c) + solve(a-1, b, c-1) - solve(a-1, b-1, c-1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1) break;
        int ans = solve(a, b, c);
        cout << "w(" << a << ", " << b << ", " << c << ") = " << ans << '\n';
    }
    return 0;
}