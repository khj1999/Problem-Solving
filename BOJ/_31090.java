import java.io.*;

public class _31090 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine().trim());

        for (int i = 0; i < n; i++) {
            String str = br.readLine().trim();
            int tmp = Integer.parseInt(str);

            int lastTwoDigits = Integer.parseInt(str.substring(2, 4));
            if (lastTwoDigits != 0 && (tmp + 1) % lastTwoDigits == 0) {
                bw.write("Good\n");
            } else {
                bw.write("Bye\n");
            }
        }

        bw.flush();
    }
}