/*
    Author : CNatka
    Date   : Aug 14, 2018
    OJ     : Symmetric Tree
    Link   : https://leetcode.com/problems/symmetric-tree/description/
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
    private boolean isSymmetric(TreeNode p, TreeNode q) {
        if(p==null && q==null) return true;
        if(p==null || q==null) return false;
        if(p.val==q.val) return isSymmetric(p.left, q.right)&&isSymmetric(p.right, q.left);
        return false;
    }
    public boolean isSymmetric(TreeNode root) {
        if(root == null) return true;
        if(root.left==null && root.right==null) return true;
        if(root.left==null || root.right==null) return false;
        return isSymmetric(root.left, root.right);
    }
}