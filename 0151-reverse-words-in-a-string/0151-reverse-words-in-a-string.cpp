class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int n = s.length();
        int e = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                 if(e!=0) {
                    s[e] = ' ';
                    e++;
                }
             int start = e ;

              while(i<n && s[i]!=' ') {
                s[e] = s[i];
                e++;
                i++;
              }

              reverse(s.begin()+start , s.begin()+e) ;
            }
        }

        s.erase(s.begin()+e , s.end());
        return s ;
    }
};