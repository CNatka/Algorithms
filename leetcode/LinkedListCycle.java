/*
    Author : CNatka
    Date   : Aug 19, 2018
    OJ     : Linked List Cycle
    Link   : https://leetcode.com/problems/linked-list-cycle/description/
    
*/

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head==null) return false;
        ListNode sRef = head.next;
        if(sRef==null) return false;
        ListNode fRef = sRef.next;
        while(sRef != null && fRef!=null) {
            if(sRef==fRef) return true;
            sRef = sRef.next;
            if(fRef.next==null) return false;
            fRef = fRef.next.next;
        }
        return false;
    }
}