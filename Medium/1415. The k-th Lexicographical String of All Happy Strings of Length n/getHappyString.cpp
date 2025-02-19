class Solution {
public:
    bool happyStringFound(string& possibleChars, string& happyString,
                          int& numLeft, int8_t idx) {

        for (string::iterator it = possibleChars.begin(); it != possibleChars.end(); ++it) {
            if (idx == 0 || *it != happyString[idx - 1]) {
                happyString[idx] = *it;
                if (idx == happyString.size() - 1) {
                    numLeft--;
                    if (numLeft <= 0) {
                        return true;
                    }
                } else {
                    if (happyStringFound(possibleChars, happyString, numLeft,
                                         idx + 1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    string getHappyString(int n, int k) {
        string happyString(n, '0');
        string possibleChars = "abc";
        if(happyStringFound(possibleChars, happyString, k, 0)){
            return happyString;
        }
        happyString.clear();
        return happyString;
    }
};