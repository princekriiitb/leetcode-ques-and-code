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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode* temp=head;
       stack<int> st;
       ListNode* slow=head;
       ListNode* fast=head;
       while(fast!=NULL && fast->next!=NULL){
               st.push(slow->val);
               fast=fast->next->next;
              
               slow=slow->next;

       }
       if(fast!=NULL){ 
        slow=slow->next;
       }
       while(slow!=NULL){
            if(slow->val!=st.top()){
                return false;
            }
            slow=slow->next;
            st.pop();
       }
       return true;
          
    }
};