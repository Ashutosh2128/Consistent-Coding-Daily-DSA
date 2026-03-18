class Solution {
    class Car {
        public:
            int pos;
            int speed;

            Car(int p, int s): pos(p), speed(s) {};
    };
public:
    static bool myComp(Car& a, Car& b) {
        return a.pos < b.pos;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;
        for(int i = 0; i < position.size(); i++) {
            Car c(position[i], speed[i]);
            cars.push_back(c);
        }

        sort(cars.begin(), cars.end(), myComp);
        
        stack<float> st;
        for(Car car: cars) {
            float time = (target - car.pos) / (float) car.speed;
            while(!st.empty() && time >= st.top()) {
                st.pop();
            }
            st.push(time);
        }

        return st.size();
    }
};