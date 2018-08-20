/*
    Author : CNatka
    Date   : Aug 20, 2018
    OJ     : Rotate Array
    Link   : https://leetcode.com/problems/rotate-array/description/
    
*/

class Solution {
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        boolean[] visited = new boolean[n];
        for(int i=0; i<n; i++) {
            int next = (i+k)%n;
            int val = nums[i];
            while(!visited[next]) {
                int temp = nums[next];
                nums[next] = val;
                val = temp;
                visited[next] = true;
                next = (next+k)%n;
            }
        }
    }
}