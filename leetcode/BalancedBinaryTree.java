/*
    Author : CNatka
    Date   : Aug 15, 2018
    OJ     : Balanced Binary Tree
    Link   : https://leetcode.com/problems/balanced-binary-tree/description/
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private int max(int a, int b) {
        return a > b ? a : b;
    }
    private int height(TreeNode root) {
        if(root==null) return 0;
        return max(height(root.left), height(root.right))+1;
    }
    public boolean isBalanced(TreeNode root) {
        if(root==null) return true;
        int diff = height(root.left) - height(root.right);
        int mask = diff >> 31;
        int aDiff = (diff+mask)^mask;
        if(aDiff < 2) return isBalanced(root.left) && isBalanced(root.right);
        return false;
    }
}