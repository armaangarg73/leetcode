class Solution {
public:

    bool isValid(vector<vector<int>>& grid ,  int r , int c , int currValue , int n){
        if(r<0 || c<0 || r>=n || c>=n || grid[r][c]!=currValue){
            return false ;
        } 

        if(currValue>=n*n-1){
            return true ;
        }
        int ans1 = isValid(grid , r-2 , c-1 , currValue+1 , n);
        int ans2 = isValid(grid , r-1 , c-2 , currValue+1 , n);
        int ans3 = isValid(grid , r+1 , c-2 , currValue+1 , n);
        int ans4 = isValid(grid , r+2 , c-1 , currValue+1 , n);
        int ans5 = isValid(grid , r+2 , c+1 , currValue+1 , n);
        int ans6 = isValid(grid , r+1 , c+2 , currValue+1 , n);
        int ans7 = isValid(grid , r-1 , c+2 , currValue+1 , n);
        int ans8 = isValid(grid , r-2 , c+1 , currValue+1 , n);

        return ans1||ans2||ans3||ans4||ans5||ans6||ans7||ans8;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        return isValid(grid , 0 , 0 , 0 , grid.size());
    }
};