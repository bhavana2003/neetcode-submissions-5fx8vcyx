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
    bool hasCycle(ListNode* head) {
        if(!head || !head->next)    return false;

        ListNode *slow = head, *fast = head;

        do{
            if(fast->next){
                fast = fast->next->next;
            }
            else{
                break;
            }
            slow = slow->next;

            if (slow) cout<<slow->val<<"";
            if (fast) cout<<fast->val<<"*";
        }
        while(slow && fast && slow != fast);

        if (slow ==  fast){
            return true;
        }
        else{
            return false;
        }
    }
};
