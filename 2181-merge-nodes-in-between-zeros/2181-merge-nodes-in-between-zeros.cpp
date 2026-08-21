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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = head ;
        ListNode* curr = head->next ;
        int sum = 0 ;

        while(curr!=NULL) {
            if(curr->val==0) {
                ans->next->val = sum ;
                ans = ans->next ;
                sum = 0 ;
            }
            else {
                sum+=curr->val ;
            }
             curr = curr->next ;
        }

        ans->next = NULL ;
        return head->next ;
    }
};