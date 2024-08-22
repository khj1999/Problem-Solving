import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String str = br.readLine();
        if(str.startsWith("\"") && str.endsWith("\"")){
            if(str.length()<=2){
                bw.write("CE");
            }
            else{
                bw.write(str.substring(1, str.length()-1));
            }
        }
        else{
            bw.write("CE");
        }
        bw.flush();
    }
}