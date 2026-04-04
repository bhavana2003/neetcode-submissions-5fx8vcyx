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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1)    return head;

        ListNode *dummy = new ListNode (0);
        ListNode *slow = head, *fast = head, *dummycurr = dummy;

        while (slow && fast){
            bool isPossible = true;
            for(int i=0; i<k; i++){
                if (fast){
                    fast = fast->next;
                }
                else{
                    isPossible = false;
                }
            }

            if (isPossible){
                ListNode *temp = slow, *prev = NULL;
                while(slow && slow != fast){
                    ListNode *tempnext = slow->next;
                    slow->next = prev;
                    prev = slow;
                    slow = tempnext;
                }
                // prev = head;
                temp->next = slow;
                dummycurr->next = prev;
                dummycurr = temp;
            }
            else break;  
        }
        return dummy->next;
    }
};
