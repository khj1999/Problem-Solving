
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class _12605 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        for(int i = 0; i < n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int token_count = st.countTokens();
            String[] arr = new String[token_count];
            for(int j = 0; j < token_count; j++){
                arr[j] = st.nextToken();
            }
            bw.write("Case #" + (i + 1) + ": ");
            for(int cnt = token_count - 1; cnt >= 0; cnt--){
                bw.write(arr[cnt] + " ");
            }
            bw.write("\n");
        }
        bw.flush();
    }
}
