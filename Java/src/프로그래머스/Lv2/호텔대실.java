package 프로그래머스.Lv2;

import java.util.*;
class 호텔대실 {
    public int solution(String[][] book_time) {
        int answer = 1;

        int n = book_time.length;
        Arrays.sort(book_time, (a, b) -> a[0].compareTo(b[0]));
        int enHour = Integer.parseInt(book_time[0][1].split(":")[0]);
        int enMin = Integer.parseInt(book_time[0][1].split(":")[1]);
        int en = enHour*60 + enMin;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        pq.offer(en+10);

        for(int i=1; i<n; i++) {
            int roomEn = pq.poll();
            int curStHour = Integer.parseInt(book_time[i][0].split(":")[0]);
            int curStMin = Integer.parseInt(book_time[i][0].split(":")[1]);
            int curEnHour = Integer.parseInt(book_time[i][1].split(":")[0]);
            int curEnMin = Integer.parseInt(book_time[i][1].split(":")[1]);
            int curSt = curStHour * 60 + curStMin;
            int curEn = curEnHour * 60 + curEnMin;
            if(curSt >= roomEn) { // 입실 가능
                pq.offer(curEn+10);
            } else { // 입실 불가. 새로운 방 배정 필요
                pq.offer(roomEn);
                pq.offer(curEn+10);
                answer++;
            }
            // System.out.println(i + " " + answer + " " + roomEn);
        }
        return answer;
    }
}
