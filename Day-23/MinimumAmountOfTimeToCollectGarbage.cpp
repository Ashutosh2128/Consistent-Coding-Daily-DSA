class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        //for Metal
        int pickM = 0;
        int travelM = 0;
        int lastM = 0;

        //for Paper
        int pickP = 0;
        int travelP = 0;
        int lastP = 0;

        //for Glass
        int pickG = 0;
        int travelG = 0;
        int lastG = 0;

        for(int i = 0; i < garbage.size(); i++) {
            string current = garbage[i];

            for(int j = 0; j < current.length(); j++) {
                if(current[j] == 'M') {
                    pickM++;
                    lastM = i;
                }
                if(current[j] == 'P') {
                    pickP++;
                    lastP = i;
                }
                if(current[j] == 'G') {
                    pickG++;
                    lastG = i;
                }
            } 
        } 

        for(int i = 0; i < lastM; i++) {
            travelM += travel[i];
        }

        for(int i = 0; i < lastP; i++) {
            travelP += travel[i];
        }

        for(int i = 0; i < lastG; i++) {
            travelG += travel[i];
        }

        return pickM + pickP + pickG + travelM + travelP + travelG;
    }
};