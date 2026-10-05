class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for(char ch : s) {
            if(ch == '(') {
                st.push(0);
            }
            else {
                int inner = st.top();
                st.pop();

                if(inner == 0) {
                    st.top() += 1;       // "()"
                }
                else {
                    st.top() += 2 * inner; // "(A)"
                }
            }
        }

        return st.top();
    }
};