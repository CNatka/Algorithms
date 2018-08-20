/*
    Author : CNatka
    Date   : Aug 16, 2018
    OJ     : Leetcode / Path Sum
    Link   : https://leetcode.com/problems/path-sum/description/
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
    private boolean hasPathSum(TreeNode root, int sum, int curSum) {
        if (root==null) return false;
        if(root.left==null && root.right==null) {
            return (root.val+curSum==sum);
        }
        return hasPathSum(root.left, sum, curSum+root.val) || hasPathSum(root.right, sum, curSum+root.val);
    }
    public boolean hasPathSum(TreeNode root, int sum) {
        return hasPathSum(root, sum, 0);
    }
}