/*
    Author : CNatka
    Date   : Aug 13, 2018
    OJ     : Leetcode/Valid Parentheses
    Link   : https://leetcode.com/problems/valid-parentheses/description/
    
    Solution
    step 1: do while all the character of string is not processed
            if current char is a closing one and (stack is empty or top one is not corresponding opening one) return false
            else push into stack
    step 2: if at the end stack is not empty return false else return true
*/

class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        int len = s.length();
        for(int i=0; i<len; i++) {
            char c = s.charAt(i);
            switch (c) {
                case ')':
                    if(stack.empty() || stack.pop()!='(') return false;
                    break;
                case '}':
                    if(stack.empty() || stack.pop()!='{') return false;
                    break;
                case ']':
                    if(stack.empty() || stack.pop()!='[') return false;
                    break;
                default:
                    stack.push(c);
            }
        }
        if(stack.empty()) return true;
        return false;
    }
}