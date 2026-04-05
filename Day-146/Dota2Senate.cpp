class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiantQ;
        queue<int> direQ;

        int position = 0;
        while(position < senate.size()) {
            char senator = senate[position];

            if(senator == 'R') radiantQ.push(position);
            else direQ.push(position);

            position++;
        }

        while(!radiantQ.empty() && !direQ.empty()) {
            int rFront = radiantQ.front();
            int dFront = direQ.front();

            radiantQ.pop();
            direQ.pop();

            if(rFront < dFront) radiantQ.push(position++);
            else direQ.push(position++);
        }

        if(!radiantQ.empty()) return "Radiant";
        return "Dire";
    }
};