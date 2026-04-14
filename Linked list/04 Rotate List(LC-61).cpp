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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0) return head;
        vector<int> arr;
        ListNode* temp=head;
      
        while(temp)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }
      
        int n=arr.size();
        if(n==0) return head;
        k=k%n;
        
        reverse(arr.begin(),arr.end());
        reverse(arr.begin(),arr.begin()+k);
        reverse(arr.begin()+k,arr.end());
      
        int i=0;
        temp=head;
        
        while(temp)
        {
            temp->val=arr[i];
        
            i++;
            temp=temp->next;
        }
        return head;
    }
};
