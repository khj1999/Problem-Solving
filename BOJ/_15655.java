import java.util.*;
import java.io.*;

public class _15655 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static int n, m; // n: 수의 개수, m: 조합의 크기
    public static int[] arr, result; // arr: 입력 수 배열, result: 조합 결과 배열
    public static boolean[] check; // 선택 여부 체크

    // 조합 생성 함수
    public static void solve(int cnt) throws IOException {
        if (cnt == m) { // 조합의 크기에 도달한 경우
            for (int i = 0; i < m; i++) {
                bw.write(result[i] + " "); // 결과 출력
            }
            bw.write("\n");
        } else {
            for (int i = 0; i < n; i++) {
                // 수를 선택하지 않았고, 이전 수보다 큰 경우
                if (!check[i] && (cnt == 0 || result[cnt - 1] < arr[i])) {
                    check[i] = true; // 수 선택
                    result[cnt] = arr[i]; // 결과 배열에 추가
                    solve(cnt + 1); // 다음 수 선택
                    check[i] = false; // 수 선택 해제
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        // 입력 받기
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        arr = new int[n];
        check = new boolean[n];
        result = new int[m];

        // 수 배열 초기화
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr); // 수 정렬

        solve(0); // 조합 생성 시작
        bw.flush(); // 출력 버퍼 비우기
        bw.close(); // 버퍼 닫기
    }
}
