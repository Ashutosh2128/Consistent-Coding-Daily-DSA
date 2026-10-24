class Solution {
public:
    int getDay(int d, int m, int month[]) {
        for(int i = 0; i < m-1; i++) d += month[i];
        return d;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int aliceArriveMonth = stoi(arriveAlice.substr(0, 2));
        int aliceArriveDate = stoi(arriveAlice.substr(3, 2));

        int aliceLeaveMonth = stoi(leaveAlice.substr(0, 2));
        int aliceLeaveDate = stoi(leaveAlice.substr(3, 2));

        int bobArriveMonth = stoi(arriveBob.substr(0, 2));
        int bobArriveDate = stoi(arriveBob.substr(3, 2));

        int bobLeaveMonth = stoi(leaveBob.substr(0, 2));
        int bobLeaveDate = stoi(leaveBob.substr(3, 2));

        int a1 = getDay(aliceArriveDate, aliceArriveMonth, month);
        int a2 = getDay(aliceLeaveDate, aliceLeaveMonth, month);
        int b1 = getDay(bobArriveDate, bobArriveMonth, month);
        int b2 = getDay(bobLeaveDate, bobLeaveMonth, month);

        int start = max(a1, b1);
        int end = min(a2, b2);

        return start > end ? 0 : end - start + 1;
    }
};