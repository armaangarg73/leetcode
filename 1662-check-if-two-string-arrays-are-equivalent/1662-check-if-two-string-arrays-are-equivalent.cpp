class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int w1 = 0 ;
        int w2 = 0 ;
        int i1 = 0 ;
        int i2 = 0 ;

        while(w1<word1.size() && w2<word2.size()) {
            if(word1[w1][i1] != word2[w2][i2]) {
                return false ;
            }

            i1++;
            i2++;

            if(i1 == word1[w1].size()) {
                w1++;
                i1 = 0 ;
            }

            if(i2 == word2[w2].size()) {
                w2++;
                i2 = 0 ;
            }
        }

        if(w1 == word1.size() && w2 == word2.size()) {
            return true ;
        }

        else
        return false ;
    }
};