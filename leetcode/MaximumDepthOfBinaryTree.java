/*
    Author : CNatka
    Date   : Aug 14, 2018
    OJ     : Maximum Depth of Binary Tree
    Link   : https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
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
    public int maxDepth(TreeNode root) {
        if(root==null) return 0;
        return max(maxDepth(root.left), maxDepth(root.right))+1;
    }
}