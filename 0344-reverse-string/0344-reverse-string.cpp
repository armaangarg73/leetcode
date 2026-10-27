class Solution {
public:

    void fun(vector<char>& s , int low , int high) {
        int len = high-low+1 ;

        if(len == 0 || len == 1){
            return  ;
        }

        if(len>1) {
            swap(s[low] , s[high]);
            fun(s , low+1 , high-1);
        }
    }

    void reverseString(vector<char>& s) {
      int low = 0 ;
      int high = s.size()-1 ;

      fun(s , low , high);
    }
};