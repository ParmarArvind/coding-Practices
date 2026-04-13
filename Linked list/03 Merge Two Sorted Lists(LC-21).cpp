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
// iterative method
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* temp1, ListNode* temp2) {

        ListNode dummy(0);
        ListNode* tail = &dummy; 

        while(temp1 && temp2)
        {
            if(temp1->val <= temp2->val)
            {
                tail->next=temp1;
                tail=tail->next;
                temp1=temp1->next;

            }
            else
            {
                 tail->next=temp2;
                tail=tail->next;
                temp2=temp2->next;
            }
        }

        while(temp1)
        {
             tail->next=temp1;
                tail=tail->next;
                temp1=temp1->next;
        }

        while(temp2)
        {
             tail->next=temp2;
                tail=tail->next;
                temp2=temp2->next;
        }
      
        return dummy.next;
        
    }
};

//  recursive method 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2== nullptr) return list1;

        ListNode* result;
        if(list1->val < list2->val)
        {
            result=list1;
            result->next=mergeTwoLists(list1->next,list2);
        }
        else {
            result=list2;
            result->next=mergeTwoLists(list1,list2->next);
        }

        return result;
    }
};
