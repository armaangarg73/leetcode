class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int result = 0 ;
        int prev = 0 ;
        int next = 0 ;

        for(int i = 0 ; i<bank.size() ; i++) {
            for(int j = 0 ; j<bank[i].size() ; j++) {
                if(bank[i][j] == '1') {
                    next++;
                }
            }
            if(prev!=0 && next!=0) {
                    result+= prev*next ;
                }

                if(next!=0) {
                    prev = next ;
                    next = 0 ;
                }
        }
        return result ;
    }
};