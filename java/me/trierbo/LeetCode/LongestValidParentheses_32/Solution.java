package me.trierbo.LeetCode.LongestValidParentheses_32;

import java.util.Stack;

public class Solution {
    public int longestValidParentheses(String s) {
        int[] num = new int[s.length()];
        int max = 0;
        for (int i = 0; i < s.length(); i++) {
            num[i] = 0;
            Stack<Character> stack = new Stack<>();
            if (s.charAt(i) == '(') {
                stack.push(s.charAt(i));
                for (int j = i+1; j < s.length() && !stack.empty(); j++) {
                    if (s.charAt(j) == '(')
                        stack.push('(');
                    else {
                        stack.pop();
                        num[i] += 2;
                    }
                }
                if (!stack.empty())
                    num[i] = 0;
                if (num[i] > max)
                    max = num[i];
            }
        }
        return max;
    }
}