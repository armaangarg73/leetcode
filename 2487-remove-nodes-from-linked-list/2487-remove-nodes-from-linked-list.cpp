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
    ListNode* removeNodes(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev ;
        int maxi = head->val;
        curr = head;

        while (curr != NULL && curr->next != NULL) {
            
            if (curr->next->val < maxi) {
                curr->next = curr->next->next;
            }
            else {
                maxi = curr->next->val;
                curr = curr->next;
            }
        }

        curr = head ;
        prev = NULL ;

         while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;

    }
};