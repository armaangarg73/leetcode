class Solution {
public:

     int fun(int n , int m , int mid) {
        int row = n-1 ;
        int col = 1 ;
        int cnt = 0 ;
        
        while(row >= 0 && col <= m) {
            if((row + 1) * col <= mid) {
                cnt += row + 1;
                col++;
            }
            else {
                row--;
            }
        }

        return cnt;
    }

    int findKthNumber(int m, int n, int k) {
    int low = 1;
    int high = n * m;
    int res = -1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        int ans = fun(n, m, mid);

        if(ans < k) {
            low = mid + 1;
        }
        else {
            res = mid;
            high = mid - 1;
        }
    }

    return res;
    }
};