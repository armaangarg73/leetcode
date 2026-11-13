class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>>res ;

        int n = s1.size() ;
        int i = 0 ;

        while(i<n){
            if(s1[i] == s2[i]){
                i++;
                continue ;
            }

            int j = i ;
            while(i<n && s1[i]!=s2[i]){
                i++;
            }
            string sub1 = s1.substr(j , i-j);
            string sub2 = s2.substr(j , i-j);
            res.push_back({sub1 , sub2});
        }
        return res ;
    }
};