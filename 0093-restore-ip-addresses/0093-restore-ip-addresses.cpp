class Solution {
public:

    void backtrack(string& s , int start , vector<string>& IpParts , vector<string>& result) {
        if(IpParts.size()==4) {
            if(start == s.length()) {
                result.push_back(IpParts[0] + "." + IpParts[1] + "." + IpParts[2] + "." + IpParts[3]);
            }

            return ;
        }

        for(int len = 1 ; len<=3 && start+len<=s.length() ; len++) {
            string segement = s.substr(start , len);

            if(segement.length()>1) {
                if(segement[0] == '0') {
                    break ;
                }

            }

                if(stoi(segement)>255) {
                    break ;
                }

                IpParts.push_back(segement);
                backtrack(s , start+len , IpParts , result);
                IpParts.pop_back();
            
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string>result ;

        if(s.length()<4 || s.length()>12) {
            return result ;
        }

        vector<string>IpParts ;
        backtrack(s , 0 , IpParts , result);
        return result ;
    }
};