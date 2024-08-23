import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int ans = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        String judge = br.readLine();
        String[] arr = new String[n];
        for(int i = 0; i < n; i++) {
            String tmp = String.valueOf(st.nextToken().charAt(0));
            if (judge.equals(tmp)) {
                ans++;
            }
        }

        bw.write(ans+"");
        bw.flush();
    }
}