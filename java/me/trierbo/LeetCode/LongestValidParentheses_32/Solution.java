package me.trierbo.LeetCode.LongestValidParentheses_32;

import java.util.Stack;

public class Solution {
    public int longestValidParentheses(String s) {
        Stack<Integer> stack = new Stack<>();
        int left = -1, max = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') stack.push(i);
            else {
                if (stack.empty()) left = i;
                else {
                    stack.pop();
                    if (stack.empty()) max = Math.max(max, i-left);
                    else max = Math.max(max, i-stack.peek());
                }
            }
        }
        return max;
    }
}