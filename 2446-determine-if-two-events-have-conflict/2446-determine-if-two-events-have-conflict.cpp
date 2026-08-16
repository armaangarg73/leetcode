class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {

        int i = 0;
        int j = 0;

        while (i < event1.size() && j < event2.size()) {

            string start1 = event1[0];
            string end1 = event1[1];
            string start2 = event2[0];
            string end2 = event2[1];

            if (start1 <= start2) {
                if (end1 >= start2) {
                    return true ;
                }
            } else {
                if (end2 >= start1) {
                    return true ;
                }
            }
            if (end1 <= end2) {
                i++;
            } else {
                j++;
            }
        }
        return false;
    }
};