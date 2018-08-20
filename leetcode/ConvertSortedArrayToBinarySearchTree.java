/*
    Author : CNatka
    Date   : Aug 15, 2018
    OJ     : Convert Sorted Array to Binary Search Tree
    Link   : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
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
    private TreeNode makeTree(int[] nums, int lo, int hi) {
        if(lo>hi) return null;
        if(lo==hi) return new TreeNode(nums[lo]);
        int mid = lo + (hi-lo)/2;
        TreeNode root = new TreeNode(nums[mid]);
        root.left = makeTree(nums, lo, mid-1);
        root.right = makeTree(nums, mid+1, hi);
        return root;
    }
    public TreeNode sortedArrayToBST(int[] nums) {
        int len = nums.length;
        if(len==0) return null;
        int lo=0;
        int hi = len-1;
        return makeTree(nums, 0, len-1);
    }
}