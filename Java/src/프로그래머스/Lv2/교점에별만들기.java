package 프로그래머스.Lv2;

import java.util.*;
class 교점에별만들기 {

    public class Pair {
        int x, y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }
            Pair pair = (Pair) o;
            return x == pair.x && y == pair.y;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }
    }

    public List<String> solution(int[][] line) {

        List<String> answer = new ArrayList<>();

        int n = line.length;
        Set<Pair> s = new HashSet<>();

        for(int i=0; i<n; i++) {
            int[] l1 = line[i];
            long A = l1[0];
            long B = l1[1];
            long E = l1[2];

            for(int j=0; j<n; j++) {
                if(i == j)  continue;
                int[] l2 = line[j];
                long C = l2[0];
                long D = l2[1];
                long F = l2[2];

                long denominator = (A * D) - (B * C);
                if (denominator == 0) continue;

                long xNumerator = (B * F) - (E * D);
                long yNumerator = (E * C) - (A * F);

                if (xNumerator % denominator == 0 && yNumerator % denominator == 0) {
                    int x = (int) (xNumerator / denominator);
                    int y = (int) (yNumerator / denominator);
                    s.add(new Pair(x, y));
                }
            }
        }

        int mnY = Integer.MAX_VALUE;
        int mnX = Integer.MAX_VALUE;
        int mxY = Integer.MIN_VALUE;
        int mxX = Integer.MIN_VALUE;
        for(Pair p : s) {
            mnY = Math.min(mnY, p.y);
            mnX = Math.min(mnX, p.x);
            mxY = Math.max(mxY, p.y);
            mxX = Math.max(mxX, p.x);
        }

        int width = mxX - mnX + 1;
        int height = mxY - mnY + 1;
        char[][] board = new char[height][width];

        for(int i=0; i<height; i++) {
            Arrays.fill(board[i], '.');
        }

        for(Pair p : s) {
            board[mxY - p.y][p.x - mnX] = '*';
        }

        for(char[] row : board) {
            answer.add(new String(row));
        }
        return answer;
    }
}
