class Solution {
public:
   bool checkInclusion(string s1, string s2) {
        int k = s1.size();

        if (k > s2.size())
            return false;

        vector<int> target(26, 0);
        vector<int> window(26, 0);

        // target = char counts of s1
        for (char c : s1) {
            target[c - 'a']++;
        }

        // build first window
        for (int i = 0; i < k; i++) {
            window[s2[i] - 'a']++;
        }

        if (window == target)
            return true;

        // slide window
        for (int right = k; right < s2.size(); right++) {

            window[s2[right - k] - 'a']--;  // remove old
            window[s2[right] - 'a']++;       // add new

            if (window == target)
                return true;
        }

        return false;
    }
};