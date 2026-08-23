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
    ListNode* partition(ListNode* head, int x) {

        if(!head || !head->next) {
            return head ;
        }
        ListNode* smallList = new ListNode(-1);
        ListNode* bigList = new ListNode(-1);

        ListNode*small = smallList ;
        ListNode* big = bigList ;

        while(head!=NULL) {
            if(head->val<x) {
                small->next = head ;
                small = head ;
            }
            else{
                big->next = head ;
                big = head ;
            }
            head = head->next ;
        }
        small->next = bigList->next ;
         big->next = NULL ;

         ListNode* result = smallList->next ;
         return result ;
    }
};