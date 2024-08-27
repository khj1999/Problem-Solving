import java.io.*;
// import java.util.StringTokenizer;

public class _31822 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
//        StringTokenizer st = new StringTokenizer(br.readLine());
        String str = br.readLine();
        int ans = 0;
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            String tmp = br.readLine();
            if(tmp.startsWith(str.substring(0,5))){
                ans++;
            }
        }
        pw.println(ans);
        pw.flush();
        pw.close();
    }
}
