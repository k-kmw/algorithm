package 프로그래머스.Lv2;

import java.util.*;
class 숫자변환하기 {

    public static class Pair {
        int num, cnt;

        public Pair(int num, int cnt) {
            this.num = num;
            this.cnt = cnt;
        }
    }
    public int solution(int x, int y, int n) {
        int answer = 0;

        if(x == y)  return 0;

        Queue<Pair> q = new ArrayDeque<>();
        q.offer(new Pair(x, 0));
        boolean[] vis = new boolean[y+1];
        vis[x] = true;

        while(!q.isEmpty()) {

            Pair cur = q.poll();

            if(cur.num + n == y || cur.num * 2 == y || cur.num * 3 == y) {
                return cur.cnt + 1;
            }

            if(cur.num + n <= y && !vis[cur.num + n]) {
                q.offer(new Pair(cur.num + n, cur.cnt + 1));
                vis[cur.num + n] = true;
            }

            if(cur.num * 2 <= y && !vis[cur.num * 2]) {
                q.offer(new Pair(cur.num * 2, cur.cnt + 1));
                vis[cur.num * 2] = true;
            }

            if(cur.num * 3 <= y && !vis[cur.num * 3]) {
                q.offer(new Pair(cur.num * 3, cur.cnt + 1));
                vis[cur.num * 3] = true;
            }
        }

        return -1;
    }
}
