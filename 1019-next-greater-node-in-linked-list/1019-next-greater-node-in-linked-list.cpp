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
    vector<int> nextLargerNodes(ListNode* head) {
    vector<int>arr ;
      stack<int>st ;

        ListNode* temp = head ;

        while(temp!=NULL) {
            arr.push_back(temp->val);
            temp = temp->next ;
        }

        int n = arr.size() ;
        vector<int>res(n) ;

        res[n-1] = 0 ;
        st.push(arr[n-1]);

        for(int i = n-2 ; i>=0 ; i--) {
            while(!st.empty() && st.top()<=arr[i]) {
                st.pop();
            }

            if(st.empty()) {
                res[i] = 0 ;
            }

            else {
                res[i] = st.top() ;
            }
            st.push(arr[i]);
        }

        return res ;
        
    }
};