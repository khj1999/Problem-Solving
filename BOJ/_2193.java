import java.io.*;

public class _2193 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        if (n == 1) {
            bw.write(1 + "");
        }
        else{
            long[] dp = new long[n + 1];

            dp[1] = 1;
            dp[2] = 1;
    
            for (int i = 3; i <= n; i++) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            bw.write(dp[n] + "");
        }
        bw.flush();
    }
}

// 1
// 10
// 100, 101
// 1000, 1001, 1010
// 10000, 10001, 10101, 10010, 10100,