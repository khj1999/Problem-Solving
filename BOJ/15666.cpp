#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int n, m;
int arr[10], result[10];
map<string, bool> mp;

void solve(int cnt){
    if(cnt == m){
        string tmp;
        for(int i = 0; i < m; i++){
            tmp.append(to_string(result[i]));
            tmp.append(" ");
        }
        if(mp[tmp]) return;
        cout << tmp << '\n';
        mp[tmp] = true;
        return;
    }
    else{
        for(int i = 0; i < n; i++){
            if(cnt == 0 || result[cnt - 1] <= arr[i]){
                result[cnt] = arr[i];
                solve(cnt + 1);
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    solve(0);
    return 0;
}

// map 사용 x
// #include<iostream>
// #include<algorithm>
// using namespace std;

// int n, m;
// int arr[10], result[10];

// void solve(int cnt){
//     if(cnt == m){
//         for(int i = 0; i < m; i++){
//             cout << result[i] << ' ';
//         }
//         cout << '\n';
//         return;
//     }

//     int prev = -1;
//     for(int i = 0; i < n; i++){
//         if((cnt == 0 || result[cnt - 1] <= arr[i]) && arr[i] != prev){
//             result[cnt] = arr[i];
//             prev = arr[i];
//             solve(cnt + 1);
//         }
//     }
// }

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n >> m;
//     for(int i = 0; i < n; i++){
//         cin >> arr[i];
//     }
//     sort(arr, arr + n);
//     solve(0);
//     return 0;
// }
