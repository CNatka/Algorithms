/*
    Author : CNatka
    Date   : Aug 20, 2018
    OJ     : Remove Linked List Elements
    Link   : https://leetcode.com/problems/remove-linked-list-elements/description/
    
*/


/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        while(head != null && head.val == val) head = head.next;
        if(head == null) return null;
        ListNode pre = head;
        ListNode cur = head.next;
        while(cur != null) {
            if(cur.val == val) pre.next = cur.next;
            else pre = cur;
            cur = cur.next;
        }
        return head;
    }
}