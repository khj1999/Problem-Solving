#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 3코드 다 정답

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int n;
//     cin >> n;
//     for(int i = 0; i < n; i++){
//         int test_case, cnt = 0;
//         vector<int> v(20), line;
//         cin >> test_case;
//         for(int j = 0; j < 20; j++){
//             cin >> v[j];
//         }
//         line.push_back(v.front());
//         for(int j = 1; j < 20; j++){
//             if(!line.empty() && line.back() > v[j]){
//                 vector<int> tmp;
//                 while(!line.empty() && line.back() >= v[j]){
//                     tmp.push_back(line.back());
//                     line.pop_back();
//                     cnt++;
//                 }
//                 line.push_back(v[j]);
//                 while(!tmp.empty()){
//                     line.push_back(tmp.back());
//                     tmp.pop_back();
//                 }
//             }
//             else{
//                 line.push_back(v[j]);
//             }
//         }
//         std::cout << test_case << " " << cnt << '\n';
//     }
//     return 0;   
// }


// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int n;
//     cin >> n;
//     for(int i = 0; i < n; i++){
//         int test_case, cnt = 0;
//         vector<int> v(20), line;
//         cin >> test_case;
//         for(int j = 0; j < 20; j++){
//             cin >> v[j];
//         }
//         for(int j = 1; j < 20; j++){
//             for(int k = 0; k < j; k++){
//                 if(v[j] < v[k]) cnt++;
//             }
//         }
//         std::cout << test_case << " " << cnt << '\n';
//     }
//     return 0;   
// }


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int test_case, cnt = 0;
        vector<int> v(20);
        cin >> test_case;
        for(int j = 0; j < 20; j++){
            cin >> v[j];
        }
        vector<int> line;
        for(int j = 0; j < 20; j++){
            int pos = line.size();
            int len = line.size();
            for (int k = 0; k < len; k++) {
                if (line[k] > v[j]) {
                    pos = k;
                    break;
                }
            }
            cnt += line.size() - pos;
            line.insert(line.begin() + pos, v[j]);
        }
        std::cout << test_case << " " << cnt << '\n';
    }
    return 0;   
}