package 프로그래머스.Lv2;

import java.util.*;
class 우박수열정적분 {
    public double[] solution(int k, int[][] ranges) {

        int x = 0;
        double[] d = new double[200];
        d[0] = 0;
        while(k > 1) {
            int y1 = k;
            if(k % 2 == 0) {
                k /= 2;
            } else {
                k = k * 3 + 1;
            }
            int y2 = k;
            x++;
            d[x] = d[x-1] + (y1 + y2) / 2.0;
        }

        List<Double> ans = new ArrayList<>();
        for(int[] range : ranges) {
            int a = range[0];
            int b = x + range[1];
            if(a > b) {
                ans.add(-1.0);
            } else if(a == b) {
                ans.add(0.0);
            } else if(a == 0 && b == 0) {
                ans.add(d[x]);
            } else {
                ans.add(d[b] - d[a]);
            }
        }
        double[] answer = new double[ans.size()];
        for(int i=0; i<ans.size(); i++) {
            answer[i] = ans.get(i);
        }
        return answer;
    }
}
