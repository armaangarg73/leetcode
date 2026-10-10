class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.empty()) return 0 ;

        int n = nums.size() ;

        unordered_set<int> set(nums.begin() , nums.end());

        int best = 0;

        for(int i : set) {
            if(set.find(i-1)!=set.end()) {
                continue ;
            }

            int length = 1 ;
            while(set.find(i+length)!=set.end()) {
                length++;
            }

            best = max(best, length);
        }
        return best ;
    }
};