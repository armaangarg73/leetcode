class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long m = 1LL * n * n;
        long long expectedSum = m * (m + 1) / 2;
        long long expectedSumSq = m * (m + 1) * (2 * m + 1) / 6;

        long long actualSum = 0;
        long long actualSumSq = 0;

        for(int i = 0 ; i<grid.size() ; i++) {
            for(int j = 0 ; j<grid[i].size() ; j++) {
                actualSum+=grid[i][j] ;
                actualSumSq += 1LL * grid[i][j] * grid[i][j];
            }
        }

        long long sumDiff = actualSum - expectedSum ; // a-b
        long long plus = (actualSumSq - expectedSumSq) / sumDiff; //a+b
        long long repeated = (sumDiff + plus)/2 ; //a
        long long missing = plus - repeated; //b

        return {(int)repeated, (int)missing};
    }
};