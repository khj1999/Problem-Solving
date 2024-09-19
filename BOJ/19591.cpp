#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    deque<long long> num;
    deque<char> op;
    string number = "";

    auto is_operator = [](char c) -> bool {
        return c == '+' || c == '-' || c == '*' || c == '/';
    };

    bool sign = false;
    int len = str.length();

    for(int i = 0; i < len; i++) {
        if (i == 0 && str[i] == '-') sign = true;
        else if (is_operator(str[i])) {
            op.push_back(str[i]);
            long long tmp = stoll(number);
            if (sign) {
                tmp *= -1;
                sign = false;
            }
            num.push_back(tmp);
            number = "";
        } else {
            number += str[i];
        }
        if (i == len - 1) {
            long long tmp = stoll(number);
            if (sign) {
                tmp *= -1;
                sign = false;
            }
            num.push_back(tmp);
            number = "";
        }
    }

    auto calc = [](deque<long long>& num, int idx, char op) -> long long {
        if (op == '*') return num[idx] * num[idx + 1];
        else if (op == '/') return num[idx] / num[idx + 1];
        else if (op == '+') return num[idx] + num[idx + 1];
        else return num[idx] - num[idx + 1];
    };

    auto cmp = [](char op) -> int {
        if (op == '*' || op == '/') return 2;
        else return 1;
    };

    while(num.size() > 1 && !op.empty()) {
        char op_front = op.front(), op_rear = op.back();
        int cur_front = 0, cur_rear = num.size() - 2;
        long long calc_front = calc(num, cur_front, op_front);
        long long calc_rear = calc(num, cur_rear, op_rear);
        bool front = false, rear = false;

        if (cmp(op_front) > cmp(op_rear)) front = true;
        else if (cmp(op_front) < cmp(op_rear)) rear = true;
        else if (calc_front >= calc_rear) front = true;
        else rear = true;

        if (front) {
            num.pop_front();
            num.pop_front();
            num.push_front(calc_front);
            op.pop_front();
        } else {
            num.pop_back();
            num.pop_back();
            num.push_back(calc_rear);
            op.pop_back();
        }
    }

    cout << num.front();
    return 0;
}
