import java.io.*;

public class _25501 {
    static int cnt;
    public static int solve(String s, int l, int r){
        cnt++;
        if(l >= r) return 1;
        else if(s.charAt(l) != s.charAt(r)) return 0;
        else return solve(s, l + 1, r - 1);
    }
    public static int isPalindrome(String s){
        return solve(s, 0, s.length() - 1);
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        for(int i = 0; i < n; i++){
            cnt = 0;
            String str = br.readLine();
            bw.write(isPalindrome(str) + " " + cnt + '\n');
        }
        bw.flush();
    }
}