class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                res[i] = n;
            }

            else {
                res[i] = st.top();
            }
            st.push(i);
        }
        return res;
    }

    vector<int> prevSmallerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                res[i] = -1;
            }

            else {
                res[i] = st.top();
            }
            st.push(i);
        }
        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> next = nextSmallerElement(heights);
        vector<int> prev = prevSmallerElement(heights);

        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {

            int length = heights[i];

            int width = next[i] - prev[i] - 1;

            int currArea = length * width;

            maxArea = max(currArea, maxArea);
        }

        return maxArea;
    }
};