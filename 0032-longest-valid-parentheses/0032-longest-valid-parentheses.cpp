class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0;
        int close = 0;
        int n = s.length();
        int len = 0;

        // Left to right
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                open++;
            }
            else {
                close++;
            }

            if(close > open) {
                open = 0;
                close = 0;
            }

            if(close == open) {
                len = max(len, 2 * close);
            }
        }

        open = 0;
        close = 0;

        // Right to left
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '(') {
                open++;
            }
            else {
                close++;
            }

            if(open > close) {
                open = 0;
                close = 0;
            }

            if(open == close) {
                len = max(len, 2 * open);
            }
        }

        return len;
    }
};