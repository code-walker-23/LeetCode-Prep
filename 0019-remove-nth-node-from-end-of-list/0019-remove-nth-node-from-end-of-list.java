/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public int getLength(ListNode head) {
        int count = 0;
        ListNode temp = head;

        while (temp != null) {
            count++;
            temp = temp.next;
        }

        return count;
    }

    public ListNode removeNthFromEnd(ListNode head, int n) {
        int length = getLength(head);
        int k = length - n;

        if (k == 0) {
            // Remove the head
            return head.next;
        }

        ListNode temp = head;
        for (int i = 0; i < k - 1; i++) {
            temp = temp.next;
        }

        if (temp.next != null) {
            temp.next = temp.next.next;
        }

        return head;
    }
}
