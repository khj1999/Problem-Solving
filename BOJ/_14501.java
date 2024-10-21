import java.io.*;
import java.util.*;

public class _14501 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[][] arr = new int[n + 1][2];  // 상담 기간과 수익을 저장할 배열
        int[] dp = new int[n + 2];  // 최대 이익을 저장할 dp 배열

        StringTokenizer st;
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());  // 상담 기간 T
            arr[i][1] = Integer.parseInt(st.nextToken());  // 상담 수익 P
        }

        for (int i = 1; i <= n; i++) {
            // 상담을 하지 않는 경우에도 다음 날로 이익을 넘겨줌
            dp[i + 1] = Math.max(dp[i + 1], dp[i]);
            
            // 상담을 할 수 있는 경우
            if (i + arr[i][0] <= n + 1) {
                dp[i + arr[i][0]] = Math.max(dp[i + arr[i][0]], dp[i] + arr[i][1]);
            }
        }

        // n일 마지막 날 또는 그 이전까지의 최대 수익을 출력
        int ans = Arrays.stream(dp).max().getAsInt();
        bw.write(ans + "\n");
        bw.flush();
    }
}
