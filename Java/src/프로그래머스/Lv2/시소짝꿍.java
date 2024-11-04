package 프로그래머스.Lv2;
import java.util.*;

class 시소짝꿍 {
    public long solution(int[] weights) {
        long answer = 0;
        int n = weights.length;

        Arrays.sort(weights);
        Map<Double, Integer> map = new HashMap<>();

        for(int weight : weights) {
            double a = weight * 1.0;
            double b = weight * 2.0 / 3;
            double c = weight * 2.0 / 4;
            double d = weight * 3.0 / 4;

            if(map.containsKey(a))  answer += map.get(a);
            if(map.containsKey(b))  answer += map.get(b);
            if(map.containsKey(c))  answer += map.get(c);
            if(map.containsKey(d))  answer += map.get(d);

            int cnt = 0;
            if(map.containsKey(a)) {
                cnt = map.get(a);
            }
            map.put(a, cnt+1);
        }
        return answer;
    }
}