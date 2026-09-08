class Solution {
public:

    long long possible(vector<int>& piles , int n , int speed) {
        long long hour = 0 ;
        for(int i = 0 ; i<piles.size() ; i++) {
            hour = hour + piles[i]/speed ;
            if(piles[i]% speed !=0) {
                hour++;
            }
        }
        return hour ;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1 ;
        int high = *max_element(piles.begin() , piles.end()) ;
        int res = -1 ;
        int n = piles.size() ;

        while(low<=high) {
            int mid = (low+high)/2 ;
            long long hour = possible(piles , n , mid) ;
            if(hour > h) {
                low = mid+1 ;
            }
            else {
                res = mid ;
                high = mid-1 ;
            }
        }
        return res ;
    }
};