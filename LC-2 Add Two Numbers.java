
//----------------------------------------Java---------------------------------------------------------------------------
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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
       ListNode head = null;
        ListNode tail = null;

        int digit;
        int carry=0;
        while(l1!=null && l2!=null)
        { 
            int sum= l1.val + l2.val + carry;
            digit = sum%10;
            carry = sum/10;
            l1=l1.next;
            l2=l2.next;

            // create list if not exist 
            if(head==null) 
            {
                head=new ListNode(digit);
                tail=head;
            }

            //linked list exist then add new node
            else
            {
                tail.next=new ListNode(digit) ;
                tail = tail.next;
            }
        }

        while(l1!=null)
        {
            int sum= l1.val + carry;
            digit = sum%10;
            carry = sum/10;

            l1=l1.next;

            tail.next=new ListNode(digit) ;
            tail = tail.next;
        }

        while(l2!=null)
        {
            int sum= l2.val + carry;
            digit = sum%10;
            carry = sum/10;
            
            l2=l2.next;

            tail.next=new ListNode(digit) ;
            tail = tail.next;
        }
        if(carry !=0) 
        {
            tail.next=new ListNode(carry) ;
            tail = tail.next;
        }

        return head;
         
    }
}
