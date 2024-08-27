import java.io.*;
// import java.util.Arrays;

public class _31821 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        int[] check = new int[n];
        int ans = 0;

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        int m = Integer.parseInt(br.readLine());
        for (int i = 0; i < m; i++) {
            int tmp = Integer.parseInt(br.readLine());
            check[tmp - 1]++;
        }


        for (int i = 0; i < n; i++) {
            ans += arr[i] * check[i];
        }

        pw.println(ans);
        pw.flush();
        pw.close();
    }
}