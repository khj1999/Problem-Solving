import java.io.*;

public class _31775 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        boolean l = false, k = false, p = false;
        for(int i = 0; i < 3; i++){
            String str = br.readLine();
            if(str.startsWith("l")){
                l = true;
            } else if (str.startsWith("k")) {
                k = true;
            } else if (str.startsWith("p")) {
                p = true;
            }
        }
        if(l && k && p){
            System.out.println("GLOBAL");
        }
        else {
            System.out.println("PONIX");
        }
    }
}