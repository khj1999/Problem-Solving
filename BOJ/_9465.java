import java.io.*;
import java.util.*;

public class _9465 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[][] arr = new int[2][n];
            int[][] dp = new int[2][n];

            for (int i = 0; i < 2; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            
            dp[0][0] = arr[0][0];
            dp[1][0] = arr[1][0];

            if (n > 1) {
                dp[0][1] = arr[0][1] + dp[1][0];
                dp[1][1] = arr[1][1] + dp[0][0];
            }

            for (int i = 2; i < n; i++) {
                dp[0][i] = Math.max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
                dp[1][i] = Math.max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
            }


            int ans = Math.max(dp[0][n - 1], dp[1][n - 1]);
            bw.write(ans + "\n");
        }
        bw.flush();
    }
}