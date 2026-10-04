class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt = 0 ;

        int numCols = strs[0].size() ;
        int numRows = strs.size() ;


        for(int i = 0 ; i<numCols;i++) {
            for(int j = 0 ; j<numRows-1; j++) {
                if(strs[j][i]>strs[j+1][i]) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt ;
    }
};