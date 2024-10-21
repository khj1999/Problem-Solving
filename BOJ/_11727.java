import java.io.*;

public class _11727 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        long[] dp = new long[n + 3];
        dp[1] = 1;
        dp[2] = 3;
        dp[3] = 5;
        for(int i = 4; i <= n; i++){
            dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 2]) % 10007;
        }
        bw.write(dp[n] + "");
        bw.flush();
    }
}
