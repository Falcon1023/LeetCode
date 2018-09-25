public class Sotution {
    public String longestPalindrome(String s) {
        int start = 0, end = 0;
        boolean[][] p = new boolean[s.length()][s.length()];
        for (int i = 0; i < s.length(); i++)
            p[i][i] = true;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) == s.charAt(i+1)) {
                p[i][i + 1] = true;
                if (end - start < 1) {
                    end = i + 1;
                    start = i;
                }
            } else
                p[i][i+1] = false;
        }
        for (int i = 2; i < s.length(); i++) {
            for (int j = 0; j < s.length() - i; j++) {
                if (s.charAt(j) == s.charAt(i + j) && p[j+1][i+j-1]) {
                    p[j][i+j] = true;
                    if (end - start < i) {
                        end = i + j;
                        start = j;
                    }
                } else
                    p[j][i+j] = false;
            }
        }
        return s.substring(start, end + 1);
    }
}
