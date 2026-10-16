class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st ;

        for(char ch : num) {
            while(!st.empty() && k>0 && st.top()>ch) {
                st.pop();
                k--;
            }

            st.push(ch);
        }

        while(k>0 && !st.empty()) {
            st.pop();
            k--;
        }

        string res = "" ;

        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin() , res.end());

        int i = 0 ;
        while (i < res.length() && res[i] == '0') {
            i++;
        }

        res = res.substr(i);

        if (res.empty()) {
            return "0";
        }

        return res;
    }
};