class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        int m = matrix[0].size() ;

        int top = 0 ;
        int bottom = n-1 ;
        int left = 0 ;
        int right = m-1 ;

        vector<int>ans ;

        while(top<=bottom && left<=right) {
            for(int col = left ; col<=right ; col++) { //left->right
                ans.push_back(matrix[top][col]);
            }

            top++;

            for(int row = top ; row<=bottom ; row++) { // top->bottom
                ans.push_back(matrix[row][right]);
            }
            right--;

            if(top<=bottom) {
                for(int col = right ; col>=left ; col--) { // right->left
                    ans.push_back(matrix[bottom][col]);
                }

                bottom--;
            }

            if(left<=right) {
                for(int row = bottom ; row>=top ; row--) { // bottom->top
                    ans.push_back(matrix[row][left]);
                }

                left++;
            }
        }
        return ans ;
    }
};