package 프로그래머스.Lv2;

import java.util.*;
class 택배상자 {
    public int solution(int[] order) {
        int answer = 0;

        int n = order.length;
        int box = 1;
        int idx = 0;
        Stack<Integer> s = new Stack<>();
        while(box <= n) {

            if(box == order[idx]) { // 컨베이어 벨트에서 순서대로 오는 경우
                answer++;
                idx++;
            } else {
                if(!s.isEmpty() && s.peek() == order[idx]) { // 보조 컨테이너 벨트에서 꺼내는 경우
                    s.pop();
                    idx++;
                    answer++;
                    continue;
                } else { // 나머지 경우
                    s.push(box);
                }
            }
            box++;
        }
        while(!s.isEmpty()) {
            if(s.peek() == order[idx]) {
                answer++;
                idx++;
                s.pop();
            } else {
                break;
            }
        }
        return answer;
    }
}
