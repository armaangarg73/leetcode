class Solution {
public:
    int loga(int n) {
        if (n == 0)
            return 0;

        if (n == 1)
            return 1;

        int res = 0;
        while (n > 0) {
            res++;
            n /= 2;
        }
        return res;
    }

    vector<string> largestString(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;

        for (int i = 0; i < n; i++) {
            string s = "";
            int num = nums[i];
            // cout << num << endl;
            while (num > 0) {
                int logi = loga(num);
                int diff ;
                if (logi >= 27) {
                    s += 'z';
                    diff = (int)(pow(2, 25));
                }
                // cout << logi << " " ;
                else {
                    char c = logi + 97 - 1;
                    s += c;
                    diff = (int)(pow(2, logi - 1));
                }
                num = num - diff;
            }
            ans.push_back(s);
        }
        return ans;
    }
};