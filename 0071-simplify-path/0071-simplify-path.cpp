class Solution {
public:
    string simplifyPath(string path) {

        stack<string> st;
        stringstream ss(path);
        string part;

        while(getline(ss, part, '/')) {

            // empty or "."
            if(part == "" || part == ".") {
                continue;
            }

            // ".."
            if(part == "..") {
                if(!st.empty()) {
                    st.pop();
                }
            }

            // directory name
            else {
                st.push(part);
            }
        }

        if(st.empty()) {
            return "/";
        }

        string ans = "";

        while(!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        return ans;
    }
};