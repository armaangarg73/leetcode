class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> seen(26 , false) ;
        int cnt = 0 ;

        for(char c : sentence) {
            int index = c - 'a' ;

            if(seen[index] == false) {
                cnt++;
                seen[index] = true ;
            }

            if(cnt == 26) {
                return true ;
            }
        }
        return false ;
    }
};