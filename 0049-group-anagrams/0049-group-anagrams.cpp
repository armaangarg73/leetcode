class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string, vector<string>> groups;

        for (string word : strs) {
            string sig = word;
            sort(sig.begin(), sig.end());   
            groups[sig].push_back(word);
        }

        vector<vector<string>> ans;
        for (auto it : groups) {
            ans.push_back(it.second);
        }

        return ans;
    }
};