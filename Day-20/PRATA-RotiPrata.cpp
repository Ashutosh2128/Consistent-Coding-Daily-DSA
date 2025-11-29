#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossibleTime(vector<int>& cooks, int numOfPrata, int time) {
    int prataCreated = 0;

    for(int i = 0; i < cooks.size(); i++) {
        int rank = cooks[i];
        int timeReq = 0;
        int j = 1;

        while(1) {
            timeReq += rank * j;
            if(timeReq > time) break;
            prataCreated++;
            j++;
        }

        if(prataCreated >= numOfPrata) return true;
    }

    return false;
}

int minimumTimeRequired(vector<int>& cooks, int numOfPrata) {
    int s = 0;
    int maxEle = *max_element(cooks.begin(), cooks.end());
    int e = maxEle * (numOfPrata * (numOfPrata + 1) / 2);

    int ans = -1;

    while(s <= e) {
        int mid = s + ((e - s) >> 1);

        if(isPossibleTime(cooks, numOfPrata, mid)) {
            ans = mid;
            e = mid - 1;
        }
        else s = mid + 1;
    }

    return ans;
}

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		int numOfPrata;
	    int numOfCooks;
	
	    cin >> numOfPrata;
	    cin >> numOfCooks;
	
	    vector<int>cooks;
	
	    for(int i = 0; i < numOfCooks; i++) {
	        int rank;
	        cin >> rank;
	        cooks.push_back(rank);
	    }
	
	    cout << minimumTimeRequired(cooks, numOfPrata) << endl;
	}
    

    return 0;
}