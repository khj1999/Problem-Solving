import java.io.*;
import java.util.*;

class Student {
    public int x, y; // x는 주최자가 매긴 점수, y는 심판이 매긴 점수
    public boolean isSelected = false; // 수상 여부
    
    Student(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class _25391 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()); // 학생 수
        int m = Integer.parseInt(st.nextToken()); // 특별상 수상자 수
        int k = Integer.parseInt(st.nextToken()); // 본상 수상자 수
        
        // Student 배열 초기화
        Student[] arr = new Student[n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken()); // 주최자 점수
            int y = Integer.parseInt(st.nextToken()); // 심판 점수
            arr[i] = new Student(x, y);
        }

        // 1. 심판 점수를 기준으로 본상 수상자 K명 선택
        Arrays.sort(arr, (s1, s2) -> Integer.compare(s2.y, s1.y));

        long ans = 0;
        List<Student> ls = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            if (i < k) {
                arr[i].isSelected = true;
                ans += arr[i].x;
            } else {
                ls.add(arr[i]);
            }
        }

        // 2. 남은 학생들 중 주최자 점수를 기준으로 특별상 수상자 M명 선택
        ls.sort((s1, s2) -> Integer.compare(s2.x, s1.x));

        for (int i = 0; i < m; i++) {
            ans += ls.get(i).x;
        }

        // 결과 출력
        bw.write(ans + "\n");
        bw.flush();
    }
}
