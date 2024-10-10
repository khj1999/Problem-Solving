import java.io.*;

public class _13301 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        long n = Long.parseLong(br.readLine());
        long[] dp = new long[(int)n];
        if(n == 1){
            bw.write(4 + "");
        }
        else if(n == 2){
            bw.write(6 + "");
        }
        else{
            dp[0] = 1;
            dp[1] = 1;
            for(int i = 2; i < n; i++){
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            // long ans = dp[(int)n - 1] * 3 + dp[(int)n - 2] * 3 + dp[(int)n - 3];
            long ans = dp[(int)n - 1] * 4 + dp[(int)n - 2] * 2;
            bw.write(ans + "");
        }
        bw.flush();
        bw.close();
    }
}
