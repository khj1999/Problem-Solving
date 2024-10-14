import java.io.*;
import java.util.*;

public class _16953 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long n = Long.parseLong(st.nextToken());
        long m = Long.parseLong(st.nextToken());
        int cnt = 0;

        while (m > n) {
            if (m % 10 == 1) {
                m /= 10;
            } else if (m % 2 == 0) {
                m /= 2;
            } else {
                break;
            }
            cnt++;
        }

        if (n == m) {
            bw.write(cnt + 1 + "");
        } else {
            bw.write("-1");
        }
        bw.flush();
    }
}
