class Solution {
public:

      bool isPalindrome(string s, int low, int high) {

        while (low < high) {
            if (s[low] != s[high]) {
                return false;
            }

            low++;
            high--;
        }

        return true;
    }

    void fun(string& s, int n, int idx, vector<string>& diary,
             vector<vector<string>>& res) {

        if (idx == n) {
            res.push_back(diary);
            return;
        }

        for (int j = idx; j < n; j++) {

            if (isPalindrome(s, idx, j)) {

                string temp = s.substr(idx, j - idx + 1);

                diary.push_back(temp);

                fun(s, n, j + 1, diary, res);

                diary.pop_back();
            }
        }

        return;
    }

    vector<vector<string>> partition(string s) {

        vector<string> diary;
        vector<vector<string>> res;

        int n = s.size();
        int idx = 0;

        fun(s, n, idx, diary, res);

        return res;
    }
};