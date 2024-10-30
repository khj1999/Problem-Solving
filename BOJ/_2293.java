import java.io.*;
import java.util.*;

public class _2293 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[] coin = new int[n + 1];
        int[] dp = new int[m + 1];
        dp[0] = 1;

        for(int i = 1; i <= n; i ++){
            coin[i] = Integer.parseInt(br.readLine());
        }

        for(int i = 1; i <= n; i++){
            for(int j = coin[i]; j <= m; j++){
                dp[j] += dp[j - coin[i]];
            }
        }

        bw.write(dp[m] + "");
        bw.flush();
    }
}
