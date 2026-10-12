class Solution {
public:

    static bool comp(vector<int>&a, vector<int>&b) {
		return a[1] < b[1];
	}

    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size() ; 
        if(n<=0) return 0 ;

        sort(courses.begin() , courses.end() , comp) ;

        priority_queue<int>pq ;
        int days = 0 ;

        for(int i = 0 ; i<n ; i++) {
            int duration = courses[i][0];
            int lastDay  = courses[i][1] ;

            days+=duration ;
            pq.push(duration);

            if(days>lastDay) {
                days-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};