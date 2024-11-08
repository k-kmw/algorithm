package 프로그래머스.Lv2;

import java.util.*;
class 숫자카드나누기 {
    public int solution(int[] arrayA, int[] arrayB) {
        int answer = 0;

        int gcdA = arrayA[0];
        int gcdB = arrayB[0];

        int n = arrayA.length;
        for(int i=1; i<n; i++) {
            gcdA = gcd(gcdA, arrayA[i]);
            gcdB = gcd(gcdB, arrayB[i]);
        }

        if(check(gcdA, arrayB)) {
            answer = Math.max(gcdA, answer);
        }
        if(check(gcdB, arrayA)) {
            answer = Math.max(gcdB, answer);
        }

        return answer;
    }

    public static int gcd(int a, int b) {
        if(a % b == 0)  return b;
        return gcd(b, a % b);
    }

    public static boolean check(int divisor, int[] arr) {
        for(int a : arr) {
            if(a % divisor == 0) {
                return false;
            }
        }
        return true;
    }
}
