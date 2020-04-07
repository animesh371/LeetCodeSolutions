/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // 342
        // 465
        // 807
         //  2 -> 4-> 3
        // 5 -> 6 -> 4
        // 7 -> 0 -> 8 
        // 1
        // 99999
        // 000001
        ListNode* resultList = new ListNode(0);
        ListNode* currentPtr = resultList;
        int carry = 0;
        
        while(l1!= nullptr || l2 != nullptr) {
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            int sum = (x+y+carry);
            carry = sum / 10; 
            currentPtr->next = new ListNode(sum % 10);
            currentPtr = currentPtr->next;
            if(l1)
                l1 = l1 ->next;
            if(l2)
                l2 = l2->next;
        }
        
        if(carry) {
            currentPtr->next = new ListNode(carry);
        }
        return resultList->next;
        
        
    }
};