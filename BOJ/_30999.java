import java.util.*;
import java.io.*;

public class _30999 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String input = br.readLine();
        StringTokenizer st = new StringTokenizer(input);

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int ans = 0;

        for(int i = 0; i < n; i++){
            int agree = 0;
            String str = br.readLine();
            for(int j = 0; j < m; j++){
                if(str.charAt(j) == 'O'){
                    agree++;
                }
            }
            if(m / 2 < agree) ans++;
        }
        bw.write(ans + "");
        bw.flush();
    }
}
