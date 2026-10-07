class Solution {
public:
    int minSwaps(string s) {
        if(s.size()%2==1) {
            return -1 ;
        }

        int open = 0 ;
        int close = 0 ;

        for(char ch : s){
            if(ch == ']' && open>0) {
                open--;
            }

            else {
                if(ch == '[') {
                    open++;
                }

                else {
                    close++;
                }
            }
        }
        return (open+1)/2 ;
    }
};