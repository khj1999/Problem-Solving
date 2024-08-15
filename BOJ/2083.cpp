#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        string name;
        int age, weight;
        cin >> name >> age >> weight;
        if(name == "#") break;
        if(age > 17 || weight >= 80) cout << name << " " << "Senior\n";
        else cout << name << " " << "Junior\n";
    }
    return 0;
}