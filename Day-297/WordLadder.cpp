class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        while(!q.empty()) {
            pair<string, int> front = q.front();
            q.pop();

            string fString = front.first;
            int fDis = front.second;

            // check weather the front is end word or not
            if(fString == endWord) return fDis;

            // otherwise check every single letter of word and check the word present in the dictionary/set or not
            for(int idx = 0; idx < fString.length(); idx++) {
                char ogLetter = fString[idx];

                for(char ch = 'a'; ch <= 'z'; ch++) {
                    fString[idx] = ch;
                    if(st.find(fString) != st.end()) {
                        // word present in the stack so push
                        q.push({fString, fDis+1});
                        // after insert into queue make sure to remove word set
                        st.erase(fString);
                    }
                }

                // backtrack -> I forget this always
                fString[idx] = ogLetter;
            }

        }

        return 0;
    }
};