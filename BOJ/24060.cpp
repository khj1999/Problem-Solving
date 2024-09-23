#include <iostream>
#include <vector>
using namespace std;

int ans = -1, cnt = 0; // 저장된 수와 카운트 초기화
int n, k;

// 병합 함수
void merge(vector<int>& A, int p, int q, int r) {
    vector<int> tmp(r - p + 1); // 임시 배열
    int i = p;    // 왼쪽 배열의 시작 인덱스
    int j = q + 1; // 오른쪽 배열의 시작 인덱스
    int t = 0;    // 임시 배열의 인덱스

    // 두 배열을 병합
    while (i <= q && j <= r) {
        if (A[i] <= A[j]) {
            tmp[t++] = A[i++]; // 왼쪽 배열에서 작은 값을 임시 배열에 추가
        } else {
            tmp[t++] = A[j++]; // 오른쪽 배열에서 작은 값을 임시 배열에 추가
        }
    }

    // 왼쪽 배열 부분이 남은 경우
    while (i <= q) {
        tmp[t++] = A[i++];
    }

    // 오른쪽 배열 부분이 남은 경우
    while (j <= r) {
        tmp[t++] = A[j++];
    }

    // 결과를 A[p..r]에 저장
    for (int k = 0; k < t; k++) {
        cnt++;
        A[p + k] = tmp[k];
        if(cnt == ::k) ans = tmp[k];
    }
}

// 병합 정렬 함수
void merge_sort(vector<int>& A, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2; // 중간 지점
        merge_sort(A, p, q); // 전반부 정렬
        merge_sort(A, q + 1, r); // 후반부 정렬
        merge(A, p, q, r); // 병합
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k; // 배열 크기와 K번째 저장 횟수 입력
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i]; // 배열 원소 입력
    }
    
    merge_sort(v, 0, n - 1); // 병합 정렬 호출
    
    // K번째 저장된 수 출력
    cout << ans << endl;
    
    return 0;
}