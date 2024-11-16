package 프로그래머스.Lv2;

import java.util.*;
class 할인행사 {
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        Map<String, Integer> map = new HashMap<>();
        int m = want.length;
        for(int i=0; i<m; i++) {
            map.put(want[i], number[i]);
        }

        int n = discount.length;
        for(int i=0; i<=n-10; i++) {
            answer += check(discount, new HashMap<>(map), i);
        }
        return answer;
    }

    public static int check(String[] discount, Map<String, Integer> map, int st) {
        for(int i=st; i<st+10; i++) {
            String prod = discount[i];
            if(!map.containsKey(prod))  return 0;
            map.put(prod, map.get(prod) - 1);
            if(map.get(prod) == 0) {
                map.remove(prod);
            }
        }
        if(map.size() > 0) {
            return 0;
        }
        return 1;
    }
}
