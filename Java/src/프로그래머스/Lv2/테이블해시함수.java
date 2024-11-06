package 프로그래머스.Lv2;

import java.util.*;
class 테이블해시함수 {
    public int solution(int[][] data, int col, int row_begin, int row_end) {
        int answer = 0;
        Arrays.sort(data, (a, b) -> {
            if (a[col-1] == b[col-1]) {
                return Integer.compare(b[0], a[0]);
            }
            return Integer.compare(a[col-1], b[col-1]);
        });

        int m = data[0].length;
        for(int i=row_begin-1; i<row_end; i++) {
            int si = 0;
            for(int j=0; j<m; j++) {
                si += (data[i][j] % (i+1));
            }
            answer ^= si;
        }
        return answer;
    }
}
