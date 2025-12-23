class Solution {
public:
    int devicesCount(string& str) {
        int cnt = 0;

        for(char ch : str) {
            if(ch == '1') cnt++;
        }

        return cnt;
    }

    int numberOfBeams(vector<string>& bank) {
        vector<int> devices;

        for(auto it : bank)
            devices.push_back(devicesCount(it));

        int beams = 0;
        for(int i = 0; i < devices.size(); i++) {
            int j = i + 1;

            while(j < devices.size()) {
                beams += devices[i] * devices[j];
                if(devices[j] == 0) j++;
                else break;
            }
        }

        return beams;
    }
};