class Solution {
public:
   bool isVowel(char ch) {
        return (ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' || ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }
    
    string sortVowels(string s) {
        string t = s;
        string vowel ="";
        
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])) vowel.push_back(s[i]);
        }
        
        if(vowel.length()==0) return s;
        
        sort(vowel.begin(), vowel.end());
        
        int j=0;
        for(int i=0;i<t.length();i++){
            if(isVowel(t[i])) {
                t[i]=vowel[j];
                j++;
            }
        }
        
        return t;
    }
};