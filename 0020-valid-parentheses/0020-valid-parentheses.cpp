class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); i++) {
            char c = s[i];

            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                // Closing bracket but stack is empty
                if(st.empty())
                    return false;

                if((c == ')' && st.top() == '(') ||
                   (c == '}' && st.top() == '{') ||
                   (c == ']' && st.top() == '[')) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};