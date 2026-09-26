class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int>kinds ;

        for(int c : candyType) {
            kinds.insert(c) ;
        }

        int n = candyType.size() ;
        return min((int)kinds.size() , n/2);
    }
};