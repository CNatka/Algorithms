/*
    Author : CNatka
    Date   : Aug 15, 2018
    OJ     : Leetcode / Minimum Depth of Binary Tree
    Link   : https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
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
    int min(int a, int b) {
        return a < b ? a : b;
    }
    public int minDepth(TreeNode root) {
        if(root==null) return 0;
        if(root.left==null && root.right==null) return 1;
        if(root.left==null) return minDepth(root.right)+1;
        if(root.right==null) return minDepth(root.left)+1;
        return min(minDepth(root.left), minDepth(root.right))+1;
    }
}