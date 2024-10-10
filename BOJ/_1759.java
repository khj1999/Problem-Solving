import java.io.*;
import java.util.*;

public class _1759 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int n, m;
    static char[] alphas, result;
    static boolean[] check_index;
    static char[] vowels = {'a', 'e', 'i', 'o', 'u'};

    static boolean checkVowels(char ch){
        for(char iter : vowels){
            if(iter == ch){
                return true;
            }
        }
        return false;
    }

    static void solve(int cnt, int vowelCnt, int consonantCnt) throws IOException {
        if(cnt == n){
            // 모음이 1개 이상, 자음이 2개 이상일 때만 출력
            if(vowelCnt >= 1 && consonantCnt >= 2){
                for(char ch : result){
                    bw.write(ch);
                }
                bw.write("\n");
            }
            return;
        }
        
        for(int i = 0; i < m; i++){
            if(!check_index[i] && (cnt == 0 || result[cnt - 1] < alphas[i])){
                check_index[i] = true; 
                result[cnt] = alphas[i];
                
                // 모음인지 자음인지 체크
                if(checkVowels(alphas[i])){
                    solve(cnt + 1, vowelCnt + 1, consonantCnt);  // 모음일 경우
                } else {
                    solve(cnt + 1, vowelCnt, consonantCnt + 1);  // 자음일 경우
                }

                check_index[i] = false;  // 백트래킹
            }
        }
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());  // 만들어야 하는 비밀번호 길이
        m = Integer.parseInt(st.nextToken());  // 주어진 문자 개수

        result = new char[n];
        alphas = new char[m];
        check_index = new boolean[m];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < m; i++){
            alphas[i] = st.nextToken().charAt(0);
        }

        Arrays.sort(alphas);  // 사전 순으로 정렬
        solve(0, 0, 0);  // cnt, 모음 개수, 자음 개수 초기화

        bw.flush();
        bw.close();
    }
}