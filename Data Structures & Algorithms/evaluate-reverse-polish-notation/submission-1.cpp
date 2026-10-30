class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 0) return 0;

        stack<int> operands;
        
        for (int i=0; i<tokens.size(); i++) {
            if (tokens[i] == "+" ) {
                int res = operands.top();
                operands.pop();
                res = operands.top() + res;
                operands.pop();
                operands.push(res);
            } else if (tokens[i] == "-" ) {
                int res = operands.top();
                operands.pop();
                res = operands.top() - res;
                operands.pop();
                operands.push(res); 
            } else if (tokens[i] == "*" ) {
                int res = operands.top();
                operands.pop();
                res = operands.top() * res;
                operands.pop();
                operands.push(res);
            } else if (tokens[i] == "/" ) {
                int res = operands.top();
                operands.pop();
                res = operands.top() / res;
                operands.pop();
                operands.push(res);
            }
            else {
                operands.push(stoi(tokens[i]));   // number, including "-5"
            }
        }


        return operands.top();
}
};