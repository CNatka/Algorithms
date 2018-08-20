/*
    Author : CNatka
    Date   : Aug 20, 2018
    OJ     : Reverse Linked List
    Link   : https://leetcode.com/problems/reverse-linked-list/description/
    
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
    public ListNode reverseList(ListNode head) {
        if(head == null) return null;
        ListNode cur = head;
        ListNode pre = null;
        while(cur.next != null) {
         ListNode temp = cur.next; 
         cur.next = pre;
         pre = cur;
         cur = temp;
        }
        cur.next = pre;
        return cur;
    }
}