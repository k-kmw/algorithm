package 프로그래머스.Lv2;

import java.util.*;
class 점찍기 {
    public long solution(int k, int d) {
        long answer = 0;

        long area = (long) d * d;
        int a = 0;
        while(a*k <= d) {
            long xSquare = (long) k * a * k * a;
            long ySquare = area - xSquare;

            long b = (long) (Math.sqrt(ySquare) / k);
            answer += b + 1;
            a++;
        }
        return answer;
    }
}
