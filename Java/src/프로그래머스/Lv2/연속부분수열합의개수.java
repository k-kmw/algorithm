package 프로그래머스.Lv2;

import java.util.*;
class 연속부분순열합의개수 {
    public int solution(int[] elements) {
        int answer = 0;

        Set<Integer> s = new HashSet<>();
        int n = elements.length;

        int[] d = new int[n+1];
        d[1] = elements[0];
        for(int i=2; i<=n; i++) {
            d[i] = d[i-1] + elements[i-1];
        }

        for(int len=1; len<=n; len++) {
            for(int st=1; st<=n; st++) {
                int en = st + len - 1;
                int sum = 0;
                if(en > n) {
                    en = en % n;
                    sum = d[n] - d[st-1] + d[en];
                    s.add(sum);
                } else {
                    sum = d[en] - d[st-1];
                    s.add(sum);
                }
            }
        }
        answer = s.size();
        return answer;
    }
}
