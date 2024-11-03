package 프로그래머스.Lv2;

class 뒤에있는큰수찾기 {
    public int[] solution(int[] numbers) {
        int n = numbers.length;
        int[] d = new int[n];

        d[n-1] = -1;
        for(int i=n-2; i>=0; i--) {
            if(numbers[i] < numbers[i+1]) {
                d[i] = numbers[i+1];
            } else if(numbers[i] < d[i+1]) {
                d[i] = d[i+1];
            } else {
                int idx = i+1;
                int num = 0;
                while(num != -1) {
                    num = d[idx];
                    if(num > numbers[i]) {
                        d[i] = num;
                        break;
                    }
                    idx++;
                }
                if(d[i] == 0) {
                    d[i] = -1;
                }
            }
        }
        return d;
    }
}
