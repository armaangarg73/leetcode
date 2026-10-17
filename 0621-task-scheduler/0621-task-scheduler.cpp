class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
          vector<int> freq(26, 0);

        for (char ch : tasks) {
            freq[ch - 'A']++;
        }

        int maxFreq = 0;
        int ties = 0;

        for (int count : freq) {
            if (count > maxFreq) {
                maxFreq = count;
                ties = 1;
            }
            else if (count == maxFreq) {
                ties++;
            }
        }

        int frame = (maxFreq - 1) * (n + 1) + ties;

        return max((int)tasks.size(), frame);
    }
};