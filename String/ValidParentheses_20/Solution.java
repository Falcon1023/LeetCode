package me.trierbo.LeetCode.ValidParentheses_20;

import java.util.Stack;

public class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(' || s.charAt(i) == '[' || s.charAt(i) == '{') {
                stack.push(s.charAt(i));
            } else if (s.charAt(i) == ')') {
                if (!stack.empty() && stack.peek() == '(') stack.pop();
                else return false;
            } else if (s.charAt(i) == ']') {
                if (!stack.empty() && stack.peek() == '[') stack.pop();
                else return false;
            } else {
                if (!stack.empty() && stack.peek() == '{') stack.pop();
                else return false;
            }
        }
        return stack.empty();
    }
}
