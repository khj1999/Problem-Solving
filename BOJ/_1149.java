import java.io.*;
import java.util.*;

public class _1149 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        int[] r = new int[n];
        int[] g = new int[n];
        int[] b = new int[n];
        int[][] dp = new int[n][3];
        
        for(int i = 0; i < n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            r[i] = Integer.parseInt(st.nextToken());
            g[i] = Integer.parseInt(st.nextToken());
            b[i] = Integer.parseInt(st.nextToken());
        }

        dp[0][0] = r[0];
        dp[0][1] = g[0];
        dp[0][2] = b[0];

        for(int i = 1; i < n; i++){
            dp[i][0] = Math.min(dp[i-1][1], dp[i-1][2]) + r[i];
            dp[i][1] = Math.min(dp[i-1][0], dp[i-1][2]) + g[i];
            dp[i][2] = Math.min(dp[i-1][0], dp[i-1][1]) + b[i];
        }
        int ans = Math.min(dp[n - 1][0], Math.min(dp[n - 1][1], dp[n - 1][2]));
        bw.write(ans + "");
        bw.flush();
    }
}
