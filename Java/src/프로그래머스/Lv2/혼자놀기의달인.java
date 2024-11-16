package 프로그래머스.Lv2;

import java.util.*;
class 혼자놀기의달인 {
    public int solution(int[] cards) {
        int answer = 0;

        int n = cards.length;
        boolean[] vis = new boolean[n+1];
        List<Integer> groupSzs = new ArrayList<>();

        for(int i=0; i<n; i++) {
            if(vis[i])  continue;
            int groupSz = dfs(cards, vis, i);
            groupSzs.add(groupSz);
        }

        if(groupSzs.size() < 2) {
            return 0;
        }

        groupSzs.sort(Collections.reverseOrder());
        answer = groupSzs.get(0) * groupSzs.get(1);
        return answer;
    }

    public static int dfs(int[] cards, boolean[] vis, int cur) {

        if(vis[cur])    return 0;
        vis[cur] = true;
        return 1 + dfs(cards, vis, cards[cur] - 1);
    }
}
