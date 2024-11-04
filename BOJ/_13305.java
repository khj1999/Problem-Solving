import java.io.*;
import java.util.*;
public class _13305 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        int[] dist = new int[n];
        int[] cost = new int[n];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n - 1; i++){
            dist[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            cost[i] = Integer.parseInt(st.nextToken());
        }

        long tmp_cost = cost[0];
        long ans = 0;
        
        for(int i = 0; i < n - 1; i++){
            ans += tmp_cost * dist[i];

            if(tmp_cost > cost[i + 1]){
                tmp_cost = cost[i + 1];
            }
        }

        bw.write(ans + "");
        bw.flush();
    }
}
