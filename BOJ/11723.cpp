#include<iostream>
using namespace std;

bool arr[21];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        string order;
        int num;
        cin >> order;
        if(order == "add"){
            cin >> num;
            arr[num] = true;
        }
        else if(order == "remove"){
            cin >> num;
            arr[num] = false;
        }
        else if(order == "check"){
            cin >> num;
            if(arr[num]){
                cout << 1 << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }
        else if(order == "toggle"){
            cin >> num;
            if(arr[num]) arr[num] = false;
            else arr[num] = true;
        }
        else if(order == "all"){
            for(int i = 0; i <= 20; i++){
                arr[i] = true;
            }
        }
        else if(order == "empty"){
            for(int i = 0; i <= 20; i++){
                arr[i] = false;
            }            
        }                
    }

    return 0;
}