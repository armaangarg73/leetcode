class Solution {
public:
    bool isAnagram(string s, string t) {
       if(s.length()!=t.length()) return false ;

       unordered_map<char, int> count;
       for(auto c : s) {
        count[c]++;
       }
       for(auto c : t) {
        count[c]--;
           if(count[c] < 0) return false ;
       }
       return true ;
    }
};