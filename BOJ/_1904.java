import java.io.*;

public class _1904 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        int[] dp = new int[n + 2];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
        }
        int ans = dp[n];
        bw.write(ans + "");
        bw.flush();
    }
}