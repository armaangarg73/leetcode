class Solution {
public:
    string toLowerCase(string s) {
        string p;
        for(int i=0;i<s.length();i++){
         if(s[i] >= 'A' && s[i]<= 'Z'){
                p.push_back(s[i]+32);
            }
            else{
                p.push_back(s[i]);
            }
        }
        return p;
    }
};