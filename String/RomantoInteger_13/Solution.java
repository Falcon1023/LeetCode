public class Solution {
    public int romanToInt(String s) {
        int sum = 0;
        if (s.contains("IV")) sum -= 2;
        if (s.contains("IX")) sum -= 2;
        if (s.contains("XL")) sum -= 20;
        if (s.contains("XC")) sum -= 20;
        if (s.contains("CD")) sum -= 200;
        if (s.contains("CM")) sum -= 200;

        for (int i =0; i < s.length(); i++) {
            if (s.charAt(i) == 'M') sum += 1000;
            else if (s.charAt(i) == 'D') sum += 500;
            else if (s.charAt(i) == 'C') sum += 100;
            else if (s.charAt(i) == 'L') sum += 50;
            else if (s.charAt(i) == 'X') sum += 10;
            else if (s.charAt(i) == 'V') sum += 5;
            else sum++;
        }
        return sum;
    }
}
