class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes ;

        for(int i=0 ; i<timePoints.size() ; i++){
        int hr = stoi(timePoints[i].substr(0,2));
        int min = stoi(timePoints[i].substr(3));
        minutes.push_back(hr*60+min);
        }

        sort(minutes.begin() , minutes.end());
        int minDiff = INT_MAX ;

        for(int i = 0 ; i<minutes.size()-1 ;i++) {
            minDiff = min(minDiff , (minutes[i+1]-minutes[i]));
        }

        minDiff = min(minDiff , 1440-(minutes[minutes.size()-1]-minutes[0]));
        return  minDiff ;
    }
};