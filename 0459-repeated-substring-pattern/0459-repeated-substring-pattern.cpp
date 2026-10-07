class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length() ;

        for(int len = 1 ; len<=n/2 ; len++) {
            if(n % len == 0) {
                string sub = s.substr(0 , len);
                string newString = "" ;

                for(int i = 0 ; i<n/len ; i++) {
                    newString = newString+sub ;
                }

                if(newString == s) {
                    return true ;
                }
            }
        }
        return false ;
    }
};