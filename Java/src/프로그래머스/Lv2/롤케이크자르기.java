package 프로그래머스.Lv2;

import java.util.*;
class 롤케이크자르기 {
    public int solution(int[] topping) {
        int answer = 0;
        int n = topping.length;
        Map<Integer, Integer> cake1 = new HashMap<>();
        Set<Integer> cake2 = new HashSet<>();
        for(int t : topping) {
            cake1.put(t, cake1.getOrDefault(t, 0) + 1);
        }

        for(int t : topping) {
            cake1.put(t, cake1.get(t) - 1);
            cake2.add(t);
            if(cake1.get(t) == 0) {
                cake1.remove(t);
            }
            if(cake1.size() == cake2.size()) {
                answer++;
            }
        }

        return answer;
    }
}
