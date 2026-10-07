class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>st ;

        int additions = 0 ;
        for(char ch : s) {
            if(ch == '(') {
                st.push(ch);
            }

            else {
                if(st.empty()) {
                    additions++;
                }
            else{
                st.pop();
            }
            }
        }
        int finalAns = additions + st.size() ;// additons->opening brackets ke liye and st.size() -> no. of closing brackets ke liye
        return finalAns ;
    }
};