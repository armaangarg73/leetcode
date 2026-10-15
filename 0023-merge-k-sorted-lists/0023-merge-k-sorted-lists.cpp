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

    struct cmp {
        bool operator() (ListNode* a , ListNode* b) {
            return a->val > b->val ;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size() ;

         priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

         for(int i = 0 ; i<n ; i++) {
             if (lists[i] != NULL) {
                pq.push(lists[i]);
            }
         }

         ListNode* dummy = new ListNode(-1);
         ListNode* tail = dummy ;

         while(!pq.empty()) {
            ListNode* curr = pq.top() ;
            pq.pop() ;

            tail->next = curr;
            tail = tail->next;
          if (curr->next != NULL) {
                pq.push(curr->next);
            }
        }

        return dummy->next;
    }
};