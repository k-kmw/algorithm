package 프로그래머스.Lv2;

import java.util.*;
class 디펜스게임 {
    public int solution(int n, int k, int[] enemy) {
        int answer = 0;

        int sz = enemy.length;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        for(int i=0; i<sz; i++) {
            n -= enemy[i];
            pq.offer(enemy[i]);
            if(n < 0 && k > 0) {
                n += pq.poll();
                k--;
            }
            if(n < 0) {
                answer = i;
                return answer;
            }
        }
        return sz;
    }
}
