#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

const uint64_t MOD = 4294967296;  // 2^32
int main() {
    uint64_t n;
    cin >> n;

    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    // 에라토스테네스의 체를 이용하여 소수 찾기
    for (uint64_t i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (uint64_t j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    uint64_t ans = 1;
    
    // 소수의 최대 거듭제곱 계산
    for (uint64_t i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            uint64_t power = i;
            while (power * i <= n) {
                power *= i;
            }
            ans = (ans * power) % MOD;
        }
    }

    cout << ans << endl;
    return 0;
}