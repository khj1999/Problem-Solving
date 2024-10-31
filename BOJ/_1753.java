import java.io.*;
import java.util.*;

class edge {
    int to;
    int weight;

    edge(int to, int weight){
        this.to = to;
        this.weight = weight;
    }
}

public class _1753 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static void dijkstra(List<List<edge>> graph, int start) throws IOException {
        int v = graph.size();
        int[] dist = new int[v];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;

        PriorityQueue<edge> pq = new PriorityQueue<>(Comparator.comparingInt(edge -> edge.weight));
        pq.offer(new edge(start, 0));

        while (!pq.isEmpty()) {
            edge cur = pq.poll(); // 현재 가장 짧은 거리의 정점을 꺼냄
            int curNode = cur.to; // 현재 정점
            int curDist = cur.weight; // 현재 정점까지의 거리

            // 이미 방문한 거리가 최단 거리보다 크다면 무시
            if (curDist > dist[curNode]) continue;

            // 인접한 모든 정점을 탐색
            for (edge eg : graph.get(curNode)) {
                int newDist = dist[curNode] + eg.weight; // 새로운 거리 계산

                // 새로운 거리가 기존 거리보다 작으면 업데이트
                if (newDist < dist[eg.to]) {
                    dist[eg.to] = newDist; // 최단 거리 갱신
                    pq.offer(new edge(eg.to, newDist)); // 갱신된 정점을 큐에 추가
                }
            }
        }

        for(int i : dist){
            bw.write((i < Integer.MAX_VALUE ? i : "INF") + "\n");
        }

    }

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int v = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());

        List<List<edge>> graph = new ArrayList<>(v);
        for (int i = 0; i < v; i++) {
            graph.add(new ArrayList<>());
        }

        int startNode = Integer.parseInt(br.readLine());
        for(int i = 0; i < e; i++){
            st = new StringTokenizer(br.readLine());
            int U, V, W;
            U = Integer.parseInt(st.nextToken());
            V = Integer.parseInt(st.nextToken());
            W = Integer.parseInt(st.nextToken());
            graph.get(U - 1).add(new edge(V - 1, W));
        }
        dijkstra(graph, startNode - 1);
        bw.flush();
    }
}
