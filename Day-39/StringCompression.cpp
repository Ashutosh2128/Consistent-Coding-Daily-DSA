class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;
        int prev = 0;
        int count = 1;

        for(int i = 1; i < chars.size(); i++) {
            if(chars[prev] == chars[i]) count++;
            else {
                chars[index++] = chars[prev];
                int start = index;
                if(count > 1) {
                    while(count) {
                        chars[index++] = (count % 10) + '0';
                        count /= 10;
                    }
                }
                prev = i;
                count = 1;
                reverse(chars.begin() + start, chars.begin() + index);
            }
        }

        chars[index++] = chars[prev];
        int start = index;
        if(count > 1) {
            while(count) {
                chars[index++] = (count % 10) + '0';
                count /= 10;
            }
        }
        reverse(chars.begin() + start, chars.begin() + index);

        return index;
    }
};