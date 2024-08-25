import java.io.*;

public class _31090 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine().trim());
        for (int i = 0; i < n; i++) {
            String str = br.readLine().trim();
            if (Integer.parseInt(str.substring(2, 4)) != 0 &&
            (Integer.parseInt(str) + 1) % Integer.parseInt(str.substring(2, 4)) == 0) {
                bw.write("Good\n");
            } else {
                bw.write("Bye\n");
            }
        }
        bw.flush();
    }
}