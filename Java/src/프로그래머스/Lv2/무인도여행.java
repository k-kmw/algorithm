package 프로그래머스.Lv2;

import java.util.*;
class 무인도여행 {

    public static class Pair {
        int y, x;

        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    static boolean[][] vis;
    static String[] board;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, -1, 0, 1};
    static int n, m;
    public int[] solution(String[] maps) {
        int[] answer = {};
        List<Integer> days = new ArrayList<>();
        n = maps.length;
        m = maps[0].length();
        this.board = maps;
        vis = new boolean[n][m];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(vis[i][j] || board[i].charAt(j) == 'X')   continue;
                days.add(bfs(i, j));
            }
        }
        if(days.isEmpty()) {
            return new int[]{-1};
        }
        answer = new int[days.size()];
        for(int i=0; i<days.size(); i++) {
            answer[i] = days.get(i);
        }
        Arrays.sort(answer);
        return answer;
    }

    private static int bfs(int i, int j) {
        Queue<Pair> q = new ArrayDeque<>();
        q.offer(new Pair(i, j));
        vis[i][j] = true;
        int cnt = board[i].charAt(j) - '0';

        while(!q.isEmpty()) {
            Pair cur = q.poll();

            for(int dir=0; dir<4; dir++) {
                int ny = cur.y + dy[dir];
                int nx = cur.x + dx[dir];

                if(ny < 0 || ny >= n || nx < 0 || nx >= m)  continue;
                if(vis[ny][nx] || board[ny].charAt(nx) == 'X') continue;

                cnt += board[ny].charAt(nx) - '0';
                q.offer(new Pair(ny, nx));
                vis[ny][nx] = true;
            }
        }

        return cnt;
    }
}
