class Solution {
public:

    long long possible(vector<int>& candies , int n , long long each) {
        long long children = 0 ;
        for(int i = 0 ;i<n ; i++) {
            children = children + candies[i]/each ;
        }
            return children ;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1 ;
        long long high = *max_element(candies.begin() , candies.end());
        long long res = 0 ; 
        long long n = candies.size() ;

        while(low<=high) {
            long long mid = (low+high)/2 ;
            long long children = possible(candies , n , mid);
            if(k<=children) {
                res = mid ;
                low = mid+1 ;
            }
            else {
                high = mid-1 ;
            }
        }
        return res ;
    }
};