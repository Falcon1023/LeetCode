import java.util.Arrays;

public class Solution {
    public String longestCommonPrefix(String[] strs) {
       StringBuilder res = new StringBuilder();
       if (strs != null && strs.length != 0) {
           Arrays.sort(strs);
           char[] first = strs[0].toCharArray();
           char[] last = strs[strs.length - 1].toCharArray();
           for (int i = 0; i < first.length; i++) {
               if (last.length > i && last[i] == first[i])
                   res.append(first[i]);
               else
                   break;
           }
       }
       return res.toString();
    }
}
