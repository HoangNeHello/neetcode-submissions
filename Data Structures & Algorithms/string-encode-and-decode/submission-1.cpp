class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.size() == 0) return {""};

        string output;
        for (int i=0; i<strs.size(); i++) {
            output.append("\"");

            for (int j=0; j<strs[i].size(); j++) {
                // Add \ at front to protect it, if the original has " or \ inside it
                if (strs[i][j] == '"' || strs[i][j] == '\\') output += '\\';
                output += strs[i][j];
            }

            output.append("\"");
            
            if (i != strs.size() - 1) {
                output.append(",");
            } else continue;
       } 

       return output;
    }

    vector<string> decode(string s) {
        if (s.size() == 0) return {};
        
        vector<string> output;
        string str;
        bool inside_word = false; // The switch to indicate the string is outside the "" or not

        for (int i=0; i<s.size(); i++) {
            if (s[i] == '\\') { // The \ indicate the appearance of " inside
                str += s[i+1];
                i++; // Skip the index
            }

            else if (s[i] == '\"') {
                if (inside_word == false) {
                    inside_word = true; // We're inside now
                } else {
                    output.push_back(str);
                    str = ""; // Reset the string to go over the new word
                    inside_word = false;
                }
            }

            else if (inside_word ==  true) {
                str += s[i];
            }

            else {
                // DO NOTHING. Since comma has nothing to do inside the vector, just let the computer skips it. There's no command telling it to add blindlessly anyway.
            }


        }
        return output;
    }
};
