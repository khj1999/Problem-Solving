import java.io.*;
import java.util.*;

public class _15656 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int[] arr, result;
    static int n, m;

    static void solve(int cnt) throws IOException {
        if(cnt == m){
            for(int i : result){
                bw.write(i + " ");
            }
            bw.write("\n");
            return;
        }
        for(int i = 0; i < n; i++){
            result[cnt] = arr[i];
            solve(cnt + 1);
        }
    }
    
    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        
        arr = new int[n];
        result = new int[m];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);

        solve(0);
        bw.flush();
        bw.close();
    }
}
