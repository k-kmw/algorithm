package 프로그래머스.Lv2;

import java.util.*;
class 숫자변환하기_2 {
    public int solution(int x, int y, int n) {
        int answer = 0;
        int[] d = new int[y+1];

        final int MAX_VALUE = 1_000_000;

        Arrays.fill(d, MAX_VALUE);
        d[x] = 0;

        for(int i=x; i<=y; i++) {

            if(i + n <= y) {
                d[i+n] = Math.min(d[i+n], d[i] + 1);
            }

            if(i * 2 <= y) {
                d[i*2] = Math.min(d[i*2], d[i] + 1);
            }

            if(i * 3 <= y) {
                d[i*3] = Math.min(d[i*3], d[i] + 1);
            }
        }

        if(d[y] == MAX_VALUE)   return -1;

        return d[y];
    }
}
