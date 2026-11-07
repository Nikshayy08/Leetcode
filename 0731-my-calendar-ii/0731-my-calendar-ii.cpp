class MyCalendarTwo {
public:
    vector<vector<int>> bookings; // stores all intervals
    vector<vector<int>> overlapBookings; // stores intersaction of overlapped intervals (double booking)
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        // check for triple bookings
        for(int i=0 ; i<overlapBookings.size() ; i++){
            int s = max(startTime,overlapBookings[i][0]);
            int e = min(endTime-1,overlapBookings[i][1]);

            if(s<=e){
                return false;
            }
        }

        for(int i=0 ; i<bookings.size() ; i++){
            int s = max(startTime,bookings[i][0]);
            int e = min(endTime-1,bookings[i][1]);

            if(s<=e){
                overlapBookings.push_back({s,e});
            }            
        }

        // Add current booking
        bookings.push_back({startTime,endTime-1});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */