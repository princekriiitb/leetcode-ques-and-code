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
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

//         ListNode *l3=new ListNode();
//         int c=0;
//         while(l1->next!=NULL){
//             int t=l1->val + l2->val +c;

//             if(t>=10){
//                 l3->val=t-10;
//                 c=1;
//             }
//             else
//             l3->val=t;

//             l3=l3->next;
//             l1=l1->next;
//             l2=l2->next;
            
//         }

//         return l3;


        
//     }
// };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy head keeps track of the start of our new list
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;
        
        // Loop continues as long as there is data in l1, l2, or a leftover carry
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            
            // Add l1's value if it exists, then move l1 forward
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            // Add l2's value if it exists, then move l2 forward
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            // Calculate the new carry (e.g., 15 / 10 = 1)
            carry = sum / 10;
            
            // Create a new node with the single digit (e.g., 15 % 10 = 5)
            curr->next = new ListNode(sum % 10);
            
            // Move the current pointer forward
            curr = curr->next;
        }
        
        // The actual result starts at dummyHead->next
        ListNode* result = dummyHead->next;
        delete dummyHead; // Free the dummy node to prevent memory leaks
        return result;
    }
};