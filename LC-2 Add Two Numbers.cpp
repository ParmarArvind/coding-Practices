//-----------------------------C++-----------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        int digit;
        int carry=0;
        while(l1 && l2)
        { 
            int sum= l1->val + l2->val + carry;
            digit = sum%10;
            carry = sum/10;
            l1=l1->next;
            l2=l2->next;

            // create list
            if(head==NULL) 
            {
                head=new ListNode(digit);
                tail=head;
            }

            //linked list exist
            else
            {
                tail->next=new ListNode(digit) ;
                tail = tail->next;
            }
        }

        while(l1)
        {
            int sum= l1->val + carry;
            digit = sum%10;
            carry = sum/10;

            l1=l1->next;

            tail->next=new ListNode(digit) ;
            tail = tail->next;
        }

        while(l2)
        {
            int sum= l2->val + carry;
            digit = sum%10;
            carry = sum/10;
            
            l2=l2->next;

            tail->next=new ListNode(digit) ;
            tail = tail->next;
        }
        if(carry) 
        {
            tail->next=new ListNode(carry) ;
            tail = tail->next;
        }

        return head;
        
    }
};
