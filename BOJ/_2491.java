import java.io.*;
import java.util.*;

public class _2491 {
    public static int findMax(int[][] arr){
        int max = arr[0][0];
        for (int[] arr1 : arr) {
            for (int j = 0; j < arr1.length; j++) {
                if (max < arr1[j]) {
                    max = arr1[j];
                }
            }
        }
        return max;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        int[][] dp = new int[n + 1][2];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        dp[0][0] = 1;
        dp[0][1] = 1;

        for(int i = 1; i < n; i++){
            if(arr[i] == arr[i - 1]){
                dp[i][0] = dp[i - 1][0] + 1;
                dp[i][1] = dp[i - 1][1] + 1;
            }
            else if(arr[i] > arr[i - 1]){
                dp[i][0] = dp[i - 1][0] + 1;
                dp[i][1] = 1;
            }
            else if (arr[i] < arr[i - 1]){
                dp[i][1] = dp[i - 1][1] + 1;
                dp[i][0] = 1;
            }
        }
        int ans = findMax(dp);
        bw.write(ans + "");
        bw.flush();
    }
}