import java.util.*;
import java.io.*;

public class _30501 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        boolean isAns = false;
        for(int i = 0; i < n; i++){
            String str = br.readLine();
            LinkedHashMap<Character, Boolean> strMap = new LinkedHashMap<Character, Boolean>();
            for(char ch : str.toCharArray()){
                strMap.put(ch, true);
            }
            if (strMap.containsKey('S') && !isAns){
                isAns = true;
                bw.write(str);
            }
        }
        bw.flush();
    }
}