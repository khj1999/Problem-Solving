import java.io.*;
import java.util.*;

public class _11054 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        int[][] dp = new int[n][2];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
            dp[i][0] = 1;
            dp[i][1] = 1;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(arr[i] > arr[j]){
                    dp[i][0] = Math.max(dp[i][0], dp[j][0] + 1);
                }
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (arr[i] > arr[j]) {
                    dp[i][1] = Math.max(dp[i][1], dp[j][1] + 1);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = Math.max(ans, dp[i][0] + dp[i][1] - 1);
        }
        bw.write(ans + "");
        bw.flush();
    }   
}