/*
    Author : CNatka
    Date   : Aug 14, 2018
    time.  : 8 min 10 sec
    OJ     : Remove Duplicates from Sorted List
    Link   : https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
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
    public ListNode deleteDuplicates(ListNode head) {
        if(head==null) return head;
        ListNode lastNode = head;
        ListNode nextNode=head.next;
        while(nextNode!=null) {
            if(nextNode.val != lastNode.val) {
                lastNode = nextNode;
                nextNode = nextNode.next;
            } else {
                lastNode.next = nextNode.next;
                nextNode = nextNode.next;
            }
        }
        return head;
    }
}