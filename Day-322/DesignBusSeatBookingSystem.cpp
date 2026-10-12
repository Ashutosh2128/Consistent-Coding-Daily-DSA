class BusBooking {
    vector<vector<pair<bool, int>>> seats;
    int totalTime = 0;
    int totalMinTime = 0;
public:
    BusBooking(int n) {
        seats = vector<vector<pair<bool, int>>>(n, vector<pair<bool, int>>(4, {0, 0}));
    }
    
    void toggle(string seat) {
        int row = stoi(seat.substr(1)) - 1;
        int col = seat[0] - 'A';

        if(seats[row][col].first == false) {
            int time = 0;
            if(col == 0 && seats[row][col+1].first) time = 3;
            else if(col == 3 && seats[row][col-1].first) time = 3;
            else time = 1;
            
            seats[row][col] = {true, time};
            totalTime += time;
            totalMinTime += 1;
        }
        else {
            auto [book, time] = seats[row][col];
            totalTime -= time;
            totalMinTime -= 1;
            seats[row][col] = {0, 0};
        }
    }
    
    int getTotalTime() {
        return totalTime;
    }
    
    int getMinTime() {
        return totalMinTime;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */