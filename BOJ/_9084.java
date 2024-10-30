import java.io.*;
import java.util.*;
public class _9084 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int tc = Integer.parseInt(br.readLine());
        while(tc-- > 0){
            int n = Integer.parseInt(br.readLine());
            int[] coin = new int[n + 1];
            StringTokenizer st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(br.readLine());
            int[] dp = new int[k + 1];
            for(int i = 0; i < n; i++){
                coin[i] = Integer.parseInt(st.nextToken());
            }
            dp[0] = 1;
            for(int i = 0; i < n; i++){
                for(int j = coin[i]; j <= k; j++){
                    dp[j] += dp[j - coin[i]];
                }
            }
            bw.write(dp[k] + "\n");
        }
        bw.flush();
    }
}
