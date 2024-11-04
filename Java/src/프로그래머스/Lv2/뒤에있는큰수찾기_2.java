package 프로그래머스.Lv2;

import java.util.*;
class 뒤에있는큰수찾기_2 {
    public int[] solution(int[] numbers) {
        int n = numbers.length;
        int[] answer = new int[n];

        Stack<Integer> s = new Stack<>();
        s.push(0);

        for(int i=1; i<n; i++) {

            while(!s.isEmpty() && numbers[s.peek()] < numbers[i]) {

                answer[s.pop()] = numbers[i];
            }

            s.push(i);
        }

        while(!s.isEmpty()) {
            answer[s.pop()] = -1;
        }

        return answer;
    }
}
