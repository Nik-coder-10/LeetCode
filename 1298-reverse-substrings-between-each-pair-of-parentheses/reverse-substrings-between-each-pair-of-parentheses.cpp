class Solution {
public:
    string reverseParentheses(string s) {
        string st;

        for (char c : s) {
            if (c != ')') {
                st += c;
            } else {
                string temp;

                while (st.back() != '(') {
                    temp += st.back();
                    st.pop_back();
                }

                st.pop_back();
                st += temp;
            }
        }

        return st;
    }
};