#include <iostream>
#include <map>
using namespace std;
#define left first
#define right second 

map<char, pair<char, char>> tree;

void preorder(char cur){
    cout << cur;
    if(tree[cur].left != '.') preorder(tree[cur].left);
    if(tree[cur].right != '.') preorder(tree[cur].right);
}

void inorder(char cur){
    if(tree[cur].left != '.') inorder(tree[cur].left);
    cout << cur;
    if(tree[cur].right != '.') inorder(tree[cur].right);
}

void postorder(char cur){
    if(tree[cur].left != '.') postorder(tree[cur].left);
    if(tree[cur].right != '.') postorder(tree[cur].right);
    cout << cur;
}

void solve(char start){
    preorder(start);
    cout << '\n';

    inorder(start);
    cout << '\n';

    postorder(start);
    cout << '\n';
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        char x, y, z;
        cin >> x >> y >> z;
        tree[x] = make_pair(y, z);
    }

    solve('A');
    return 0;
}