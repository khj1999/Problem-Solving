import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class _17845 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n, k;
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        int[][] arr = new int[k + 1][2];
        int[][] dp = new int[k + 1][n + 1];

        for(int i = 1; i <= k; i++){
            st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken()); // 중요도
            arr[i][1] = Integer.parseInt(st.nextToken()); // 공부시간
        }
        
        for(int i = 1; i <= k; i++){
            for(int j = 1; j <= n; j++){
                if(arr[i][1] <= j){
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - arr[i][1]] + arr[i][0]);
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        int ans = dp[k][n];
        bw.write(ans + "");
        bw.flush();
    }
}
