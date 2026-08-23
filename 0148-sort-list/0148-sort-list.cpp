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

    ListNode*findMid(ListNode* head){
        ListNode* slow = head ;
        ListNode* fast = head->next ;

        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next ;
            slow = slow->next;
        }
        return slow ;
    }

      ListNode* merge(ListNode* list1, ListNode* list2) {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        ListNode* ans = new ListNode(-1);
        ListNode* mptr = ans;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                mptr->next = list1;
                mptr = list1;
                list1 = list1->next;
            }

            else {
                mptr->next = list2;
                mptr = list2;
                list2 = list2->next;
            }
        }
        while (list1 != NULL) {
            mptr->next = list1;
            mptr = list1;
            list1 = list1->next;
        }

        while (list2 != NULL) {
            mptr->next = list2;
            mptr = list2;
            list2 = list2->next;
        }
        return ans->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head ;
        }
        ListNode* mid = findMid(head);
        ListNode* left = head ;
        ListNode* right = mid->next ;
        mid->next = NULL ;

        left = sortList(left);
        right = sortList(right);

        ListNode* mergedLL = merge(left , right);
        return mergedLL ;
    }
};