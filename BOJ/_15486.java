import java.io.*;
import java.util.*;

public class _15486 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        long[] dp = new long[n + 2];
        long[][] arr = new long[n + 2][2];

        for(int i = 1; i <= n; i++){
            st = new StringTokenizer(br.readLine());
            arr[i][0] = Long.parseLong(st.nextToken());
            arr[i][1] = Long.parseLong(st.nextToken());
        }

        for(int i = 1; i <= n; i++){
            if(i + arr[i][0] <= n + 1){
                dp[i + (int)arr[i][0]] = Math.max(dp[i + (int)arr[i][0]], dp[i] + arr[i][1]);
            }
            dp[i + 1] = Math.max(dp[i + 1], dp[i]);
        }
        bw.write(Arrays.stream(dp).max().getAsLong() + "");
        bw.flush();
    } 
}
