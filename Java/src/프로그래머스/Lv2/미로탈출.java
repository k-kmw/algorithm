package 프로그래머스.Lv2;

import java.util.*;
class 미로탈출 {

    public static class Pair {
        public int y, x;
        public int isOpen, cnt;

        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
            this.isOpen = 0;
            this.cnt = 0;
        }

        public Pair(int y, int x, int isOpen, int cnt) {
            this.y = y;
            this.x = x;
            this.isOpen = isOpen;
            this.cnt = cnt;
        }
    }

    static boolean[][][] vis;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, -1, 0, 1};
    public int solution(String[] maps) {
        int answer = 0;
        int n = maps.length;
        int m = maps[0].length();

        vis = new boolean[n][m][2];

        Queue<Pair> q = new ArrayDeque<>();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(maps[i].charAt(j) == 'S') {
                    q.offer(new Pair(i, j));
                    break;
                }
            }
            if(!q.isEmpty())    break;
        }

        while(!q.isEmpty()) {
            Pair cur = q.poll();

            for(int dir=0; dir<4; dir++) {
                int ny = cur.y + dy[dir];
                int nx = cur.x + dx[dir];

                if(ny < 0 || ny >= n || nx < 0 || nx >= m)  continue;
                if(maps[ny].charAt(nx) == 'X' || vis[ny][nx][cur.isOpen])    continue;
                if(maps[ny].charAt(nx) == 'E' && cur.isOpen == 1) {
                    return cur.cnt+1;
                }

                if(maps[ny].charAt(nx) == 'L') {
                    q.offer(new Pair(ny, nx, 1, cur.cnt+1));
                    vis[ny][nx][cur.isOpen] = true;
                } else {
                    q.offer(new Pair(ny, nx, cur.isOpen, cur.cnt+1));
                    vis[ny][nx][cur.isOpen] = true;
                }

            }
        }

        return -1;
    }
}
