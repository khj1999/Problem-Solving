import java.io.*;

public class _27433 {
    public static long solve(long n){
        if(n == 1 || n == 0){  // 팩토리얼 정의: 0! = 1
            return 1;
        }
        return n * solve(n - 1);  // 재귀적으로 n! 계산
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        long n = Long.parseLong(br.readLine());  // 입력이 long형이므로 Long.parseLong 사용
        bw.write(solve(n) + "\n");
        bw.flush();
        bw.close();
    }   
}