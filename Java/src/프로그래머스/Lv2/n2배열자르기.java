package 프로그래머스.Lv2;

import java.util.*;
class n2배열자르기 {
    public int[] solution(int n, long left, long right) {
        int[] answer = {};
        List<Integer> arr = new ArrayList<>();
        for(long i = left; i<=right; i++) {
            int row = (int)(i / n);
            int col = (int)(i % n);
            int value = Math.max(row, col) + 1;
            arr.add(value);
        }
        answer = new int[arr.size()];
        for(int i=0; i<arr.size(); i++) {
            answer[i] = arr.get(i);
        }
        return answer;
    }
}
