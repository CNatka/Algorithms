/*
    Author : CNatka
    Date   : Aug 19, 2018
    OJ     : Intersection of Two Linked Lists
    Link   : https://leetcode.com/problems/intersection-of-two-linked-lists/description/
    
*/


/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    private int getLength(ListNode a) {
        ListNode temp = a;
        int len=0;
        while(temp!=null) {
            len++;
            temp = temp.next;
        }
        return len;
    }
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if(headA == null || headB == null) return null;
        int aLen = getLength(headA);
        int bLen = getLength(headB);
        ListNode bigList = headB;
        ListNode smallList = headA;
        if(aLen > bLen) {
            bigList = headA;
            smallList = headB;
        }
        int lDiff = aLen-bLen;
        int mask = lDiff >> 31;
        lDiff = (lDiff+mask)^mask;
        for(int i=0; i<lDiff; i++){
            bigList = bigList.next;
        }
        while(bigList != null) {
            if(bigList == smallList) return bigList;
            bigList = bigList.next;
            smallList = smallList.next;
        }
        return null;
    }
}