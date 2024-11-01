package 소프티어;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Softeer_6_출퇴근길 {
    static int n, m;
    static int S, T;
    static List<Integer>[] adjList;
    static List<Integer>[] adjListR;
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        n = Integer.parseInt(s[0]);
        m = Integer.parseInt(s[1]);

        adjList = new ArrayList[n+1];
        adjListR = new ArrayList[n+1];

        for(int i=1; i<=n; i++) {
            adjList[i] = new ArrayList<>();
            adjListR[i] = new ArrayList<>();
        }

        for(int i=0; i<m; i++) {
            s = br.readLine().split(" ");
            int a = Integer.parseInt(s[0]);
            int b = Integer.parseInt(s[1]);
            adjList[a].add(b);
            adjListR[b].add(a);
        }

        s = br.readLine().split(" ");
        S = Integer.parseInt(s[0]);
        T = Integer.parseInt(s[1]);

        // S -> X
        boolean[] visA = new boolean[n+1];
        visA[T] = true;
        dfs(S, adjList, visA);
        // System.out.println();

        // X -> T (T -> X) :
        // 모든 X에 대하여 탐색을 하여 T에 도달하는지 확인하는 것 보다 (시간이 비효율적임)
        // 역방향 그래프를 통해 T에서 X에 도달 가능한지 확인하면, X에서 T에 도달 가능함을 역으로 알 수 있다.
        boolean[] visB = new boolean[n+1];
        dfs(T, adjListR, visB);
        // System.out.println();

        // T -> X
        boolean[] visC = new boolean[n+1];
        visC[S] = true;
        dfs(T, adjList, visC);
        // System.out.println();

        // X -> S (S -> X)
        // 모든 X에 대하여 탐색을 하여 S에 도달하는지 확인하는 것 보다 (시간이 비효율적임)
        // 역방향 그래프를 통해 S에서 X에 도달 가능한지 확인하면, X에서 S에 도달 가능함을 역으로 알 수 있다.
        boolean[] visD = new boolean[n+1];
        dfs(S, adjListR, visD);
        // System.out.println();

        int cnt = 0;
        for(int i=1; i<=n; i++) {
            if(visA[i] && visB[i] && visC[i] && visD[i]) {
                cnt++;
            }
        }
        System.out.println(cnt - 2);
        // 문제 조건에서 S에서 T로 가는 경로와 T에서 S로 가는 경로가 하나 이상 존재한다고 했으므로, S와 T는 반드시 한 번은 방문함
        // 따라서 S와 T를 세는 경우를 빼줌
    }

    public static void dfs(int v, List<Integer>[] adjList, boolean[] vis) {

        if(vis[v]) {
            return;
        }

        // System.out.print(v + " ");

        vis[v] = true;
        for(int neighbor : adjList[v]) {
            dfs(neighbor, adjList, vis);
        }
    }
}
