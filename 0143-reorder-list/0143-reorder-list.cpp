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
    void reorderList(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
            return;

        // find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse second half
        ListNode* prev = NULL;
        ListNode* curr = slow;

        while(curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // weave
        ListNode* A = head;
        ListNode* B = prev;

        while(B->next != NULL) {
            ListNode* nextA = A->next;
            ListNode* nextB = B->next;

            A->next = B;
            B->next = nextA;

            A = nextA;
            B = nextB;
        }
    }
    
};