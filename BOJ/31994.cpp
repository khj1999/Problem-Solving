#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    pair<string, int> max;
    max.first = ""; max.second = 0;
    for(int i = 0; i < 7; i++){
        string str;
        int num;
        cin >> str >> num;
        if(max.second < num) {
            max.first = str;
            max.second = num;
        }    
    }
    cout << max.first;
    return 0;
}