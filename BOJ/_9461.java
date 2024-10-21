import java.io.*;

public class _9461 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        long[] dp = new long[101];
        dp[2] = 1;
        dp[3] = 1;
        dp[4] = 2;
        dp[5] = 2;
        dp[6] = 3;

        for(int i = 7; i <= 100; i++){
            dp[i] = dp[i - 1] + dp[i - 5];
        }

        int tc = Integer.parseInt(br.readLine());
        for(int i = 0; i < tc; i++){
            int n = Integer.parseInt(br.readLine());
            bw.write(dp[n] + "\n");
        }
        bw.flush();
    }    
}
