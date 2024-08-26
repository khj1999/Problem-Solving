import java.util.*;
import java.io.*;

public class _30979 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = Integer.parseInt(br.readLine());
        int n = Integer.parseInt(br.readLine());

        int cnt = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            cnt += Integer.parseInt(st.nextToken());
        }
        if(cnt >= t){
            bw.write("Padaeng_i Happy");
        }
        else{
            bw.write("Padaeng_i Cry");
        }
        bw.flush();
    }
}
