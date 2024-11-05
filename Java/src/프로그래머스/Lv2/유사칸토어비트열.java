package 프로그래머스.Lv2;

import java.util.*;
class 유사칸토어비트열 {
    static int n;
    static StringBuilder sb = new StringBuilder();
    public int solution(int n, long l, long r) {
        int answer = 0;
        this.n = n;
        answer = dfs(n, r) - dfs(n, l-1);
        return answer;
    }

    public static int dfs(int k, long idx) {
        if(k == 0) {
            return 1;
        }

        long preLength = (long)Math.pow(5, k-1);
        int oneCount = (int)Math.pow(4, k);
        int order = (int)(idx / preLength);
        if(idx % preLength == 0) {
            order--;
        }

        if(order == 2) { // 0만 있는 구간
            return oneCount / 2;
        } else if(order < 2) { // 0 이전 구간
            return order * (int)Math.pow(4, k-1) + dfs(k-1, idx - order * preLength);
        } else { // 0 이후 구간
            return (order-1) * (int)Math.pow(4, k-1) + dfs(k-1, idx - order * preLength);
        }
    }
}
