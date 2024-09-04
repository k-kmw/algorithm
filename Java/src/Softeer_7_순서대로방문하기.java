import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Softeer_7_순서대로방문하기 {
    public static class Pair {
        int y, x;

        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    static int n, m;
    static int[][] board;
    static Pair[] spot;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, -1, 0, 1};
    static int spotIdx;
    static int ans;
    public static void main(String[] args) throws IOException
    {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        n = Integer.parseInt(s[0]);
        m = Integer.parseInt(s[1]);
        board = new int[n+1][n+1];
        spot = new Pair[m];
        for(int i=1; i<=n; i++) {
            s = br.readLine().split(" ");
            for(int j=1; j<=n; j++) {
                board[i][j] = Integer.parseInt(s[j-1]);
            }
        }

        for(int i=0; i<m; i++) {
            s = br.readLine().split(" ");
            int y = Integer.parseInt(s[0]);
            int x = Integer.parseInt(s[1]);
            spot[i] = new Pair(y, x);
        }

        boolean[][] vis = new boolean[n+1][n+1];
        vis[spot[0].y][spot[0].x] = true;
        dfs(spot[0].y, spot[0].x, 1, vis);
        System.out.println(ans);
    }

    public static void dfs(int y, int x, int spotIdx, boolean[][] vis) {

        // System.out.println(y + " " + x + " " + ans);

        if(spotIdx == m) {
            ans++;
            return;
        }

        for(int dir=0; dir<4; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(ny < 1 || ny > n || nx < 1 || nx > n) continue;
            if(board[ny][nx] == 1 || vis[ny][nx]) continue;

            vis[ny][nx] = true;
            if(ny == spot[spotIdx].y &&  nx == spot[spotIdx].x) {
                dfs(ny, nx, spotIdx+1, vis);
            } else {
                dfs(ny, nx, spotIdx, vis);
            }
            vis[ny][nx] = false;
        }
    }
}
