class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
    
        string clean_str = {};
        for (int i=0; i<s.size(); i++) {
            if (!isalnum(static_cast<unsigned char>(s[i]))) {
                continue;
            }
            else clean_str += s[i]; // clean_str should not have any non-alphanumerical 
        }
        // Remove the case sensitive by letting all keys to be lowercase
        for (int i=0; i<clean_str.size(); i++) {
            clean_str[i] = tolower(static_cast<unsigned char>(clean_str[i]));
        }

        int j = clean_str.size()-1; // j needs to be with clean_str for correct length detection

        while (i<j) {
            if (clean_str[i] == clean_str[j]) {
                i++;
                j--;
            } else return false;
        }  
        return true;
    }
};
