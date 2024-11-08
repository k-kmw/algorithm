package 프로그래머스.Lv2;

import java.util.*;
class 귤고르기 {

    public static class Tangerine implements Comparable<Tangerine> {
        public int sz, cnt;

        public Tangerine(int sz, int cnt) {
            this.sz = sz;
            this.cnt = cnt;
        }

        public int compareTo(Tangerine o) {
            return o.cnt - this.cnt;
        }
    }

    public int solution(int k, int[] tangerine) {
        int answer = 0;
        Map<Integer, Integer> map = new HashMap<>();
        for(int sz : tangerine) {
            map.put(sz, map.getOrDefault(sz, 0) + 1);
        }

        PriorityQueue<Tangerine> pq = new PriorityQueue<>();
        for(int key : map.keySet()) {
            pq.offer(new Tangerine(key, map.get(key)));
        }

        while(!pq.isEmpty() && k > 0) {
            Tangerine cur = pq.poll();
            k -= cur.cnt;
            answer++;
        }
        return answer;
    }
}
