import java.io.*;

public class _27433 {
    public static long solve(long n){
        if(n == 1){
            return 1;
        }
        return n * solve(n - 1);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        long n = Integer.parseInt(br.readLine());
        bw.write(solve(n) + "");
        bw.flush();
    }   
}