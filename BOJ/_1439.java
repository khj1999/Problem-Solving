import java.io.*;

public class _1439 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String str = br.readLine();
        
        int zeroToOne = 0; // "0"에서 "1"로 전환되는 횟수
        int oneToZero = 0; // "1"에서 "0"으로 전환되는 횟수
        char curChar = str.charAt(0);

        for (int i = 1; i < str.length(); i++) {
            if (str.charAt(i) != curChar) {
                if (curChar == '0') {
                    zeroToOne++;
                } else {
                    oneToZero++;
                }
                curChar = str.charAt(i);
            }
        }

        // 마지막 구간에 대한 처리를 위해 현재 문자가 무엇인지에 따라 한 번 더 카운트
        if (curChar == '0') {
            zeroToOne++;
        } else {
            oneToZero++;
        }

        // 최소 구간을 뒤집어야 하므로 더 작은 횟수를 출력
        bw.write((zeroToOne > oneToZero ? oneToZero : zeroToOne) + "");
        bw.flush();
    }
}
