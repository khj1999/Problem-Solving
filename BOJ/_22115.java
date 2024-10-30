import java.io.*;
import java.util.*;

public class _22115 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // 입력 처리
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int[] coffee = new int[n];
        
        // 카페인 함유량 입력
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            coffee[i] = Integer.parseInt(st.nextToken());
        }

        // DP 배열 초기화
        int[] dp = new int[k + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;  // 0 카페인은 커피를 마시지 않아도 되므로 0개

        // DP 배열 갱신
        for (int i = 0; i < n; i++) {
            for (int j = k; j >= coffee[i]; j--) {
                if (dp[j - coffee[i]] != Integer.MAX_VALUE) {
                    dp[j] = Math.min(dp[j], dp[j - coffee[i]] + 1);
                }
            }
        }
        int ans = dp[k] == Integer.MAX_VALUE ? -1 : dp[k];

        bw.write(ans + "");
        bw.flush();
    }
}
