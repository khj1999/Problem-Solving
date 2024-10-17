import java.io.*;
import java.util.*;

public class _13398 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        
        // dp1: i번째까지의 최대 연속합, dp2: i번째 요소를 제거했을 때의 최대 연속합
        int[][] dp = new int[2][n];
        
        dp[0][0] = arr[0];
        dp[1][0] = arr[0];
        int ans = arr[0];
        
        for (int i = 1; i < n; i++) {
            dp[0][i] = Math.max(dp[0][i - 1] + arr[i], arr[i]);
            dp[1][i] = Math.max(dp[1][i - 1] + arr[i], dp[0][i - 1]);
            ans = Math.max(ans, Math.max(dp[0][i], dp[1][i]));
        }
        
        bw.write(ans + "");
        bw.flush();
    }
}
