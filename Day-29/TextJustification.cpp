class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        vector<string> currentLine;

        int currentLineTotalChar = 0;
        for(int i = 0; i < words.size(); i++) {
            string currentWord = words[i];
            int currentLineNeededSpace = currentLine.size();

            if(currentLineTotalChar + currentLineNeededSpace + currentWord.size() > maxWidth) {
                int currentLineSpaceRequired = maxWidth - currentLineTotalChar;
                int equalSpace = currentLineSpaceRequired / (max(1, (int)(currentLine.size() - 1)));
                int reminder = currentLineSpaceRequired % (max(1, (int)(currentLine.size() - 1)));

                if(currentLine.size() > 1) {
                    for(int j = 0; j < currentLine.size() - 1; j++) {

                        for(int space = 0; space < equalSpace; space++) {
                            currentLine[j] += " ";
                        }

                        if(reminder) {
                            currentLine[j] += " ";
                            reminder--;
                        }
                    }
                } else {
                    //if a single word in the currentLine
                    while(equalSpace--) {
                        currentLine[0] += " ";
                    }
                }

                string spaceWord = "";

                for(int j = 0; j < currentLine.size(); j++) {
                    spaceWord += currentLine[j];
                }

                ans.push_back(spaceWord);

                currentLine.clear();
                currentLineTotalChar = 0;
            }


            currentLine.push_back(currentWord);
            currentLineTotalChar += currentWord.length();
        }

        int spaceRequired = maxWidth - currentLineTotalChar;
        int i = 0;
        while(i < currentLine.size()-1) {
            currentLine[i] += " ";
            spaceRequired--;
            i++;
        }

        while(spaceRequired--) {
            currentLine[i] += " ";
        }

        string spaceWord = "";

        for(int j = 0; j < currentLine.size(); j++) {
            spaceWord += currentLine[j];
        } 

        ans.push_back(spaceWord);
        return ans;
    }
};