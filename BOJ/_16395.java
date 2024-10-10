import java.io.*;
import java.util.StringTokenizer;

public class _16395 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n, k;
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        int[][] dp = new int[n + 1][n + 1];
        dp[0][0] = 1;
        dp[1][0] = 1;
        dp[1][1] = 1;
        if(2 <= n){
            for(int i = 2; i < n; i++){
                for(int j = 0; j <= i; j++){
                    if(j == 0 || j == i) dp[i][j] = 1;
                    else{
                        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                    }
                }
            }
        }
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         bw.write(dp[i][j] + " ");
        //     }
        //     bw.write("\n");
        // }
        bw.write(dp[n - 1][k - 1] + "");
        bw.flush();
        bw.close();
    }
}
// 1
// 1 1
// 1 2 1
// 1 3 3 1