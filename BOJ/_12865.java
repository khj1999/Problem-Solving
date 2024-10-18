import java.io.*;
import java.util.*;

public class _12865 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n, k;
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        // 0이 무게, 1이 가치
        int[][] arr = new int[n + 1][2];
        int[][] dp = new int[n + 1][k + 1];

        // 물건의 무게와 가치를 입력받음
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());  // 무게
            arr[i][1] = Integer.parseInt(st.nextToken());  // 가치
        }

        // DP 테이블 채우기
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                if (arr[i][0] <= j) {  // 현재 물건을 배낭에 넣을 수 있는 경우
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - arr[i][0]] + arr[i][1]);
                } else {  // 넣을 수 없는 경우
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        bw.write(dp[n][k] + "");
        bw.flush();
    }
}