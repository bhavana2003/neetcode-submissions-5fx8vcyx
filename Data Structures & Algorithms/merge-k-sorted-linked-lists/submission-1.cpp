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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(-1001);
        ListNode *prev = dummy, *curr;

        int n = lists.size();
        while(n){
            int minIndex = -1;
            for(int i=0; i<lists.size(); i++){
                if (lists[i] == NULL){
                    continue;
                }
                else if (minIndex == -1 || lists[minIndex] == NULL){
                    minIndex = i;
                }
                else{
                    if (lists[i] && lists[i]->val < lists[minIndex]->val){
                        minIndex = i;
                    }
                }
            }
            if (minIndex == -1) break;
            curr = lists[minIndex];
            lists[minIndex] = lists[minIndex]->next;
            prev->next = curr;
            prev = curr;

            if (lists[minIndex] == NULL)    n--;
        }
        return dummy->next;
    }
};
