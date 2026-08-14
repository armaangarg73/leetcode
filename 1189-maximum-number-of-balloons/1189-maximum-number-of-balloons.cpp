class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size() ;
        unordered_map<char , int>have ;
        for(int i = 0 ;i<n ; i++) {
            have[text[i]]++;
        }

        unordered_map<char , int>need ;
        need['b'] = 1;
        need['a'] = 1;
        need['l'] = 2;
        need['o'] = 2;
        need['n'] = 1;

        int res = INT_MAX ;
        for(auto i : need) {
            char c = i.first ;
            int freq_need = i.second ;
            int freq_have = have[c];

            if(freq_have < freq_need) {
                return 0 ;
            }
            int total = freq_have/freq_need ;
            res = min(res , total);
        }
        return res ;
    }
};