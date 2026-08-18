class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size() ;
        int oneDeletion =  0 ;
        int noDeletion = arr[0];
        int res = arr[0] ;

        for(int i = 1 ; i<n ; i++) {
            int v1 = arr[i];
            int v2 = noDeletion + arr[i];
            int v3 = oneDeletion + arr[i];
            int v4 = noDeletion ;

            res = max(res, max(max(v1,v2), max(v3,v4)));
            noDeletion = max(v1 , v2);
            oneDeletion = max(v3,v4);
        }
        return res ;
    }
};