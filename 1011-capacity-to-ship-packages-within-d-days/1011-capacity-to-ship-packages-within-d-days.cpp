class Solution {
public:

    bool isPossible(vector<int>& weights , int n , long long capacity , int days) {
        int k = 1 ;
        long long packages = 0 ;

        for(int i = 0 ; i<n ; i++) {
            if(packages + weights[i] <= capacity) {
                packages = packages + weights[i] ;
            }

            else  {
                k++ ;
                packages = weights[i] ;
            }
            if(k>days) {
                return false ;
            }
        }
        return true ;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size() ;
        if(n<days) {
            return -1 ;
        }

        long long low = 0 ;
        long long high ;

        for(int i = 0 ; i<n ; i++) {
             low = max(low, (long long)weights[i]);
            high+=weights[i] ;
        }
          
        long long res = -1 ;
        while(low<=high) {
            long long mid = (low+high)/2 ;
            if(isPossible(weights , n , mid , days)) {
                res = mid ;
                high = mid-1 ;
            }
            else {
                low = mid+1 ;
            }
        }
        return (int)res ;
    }
};