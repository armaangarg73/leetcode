class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size() ;
        int col = matrix[0].size();
        int n = row*col ;

       
        int low = 0 ;
        int high = n-1 ;

        while(low<=high) {
            int mid = (low+high)/2 ;
            int rowIndex = mid / col;
            int colIndex = mid % col;
            if(matrix[rowIndex][colIndex] == target) {
                return true ;
            }

            else if(matrix[rowIndex][colIndex] < target) {
                low = mid+1 ;
            }

            else {
                high = mid-1 ;
            }
        }
        return false ;
    }
};