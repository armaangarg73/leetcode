class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> setA(nums1.begin(), nums1.end());
    unordered_set<int> result;

    for (int y : nums2) {
        if (setA.count(y)) {
            result.insert(y);
        }
    }

    return vector<int>(result.begin(), result.end());
    }
};