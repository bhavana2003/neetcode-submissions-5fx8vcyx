class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;

        for(string s:tokens){
            if (s == "+" || s == "-" || s == "/" || s == "*"){
                int second = st.top();
                st.pop();

                int first = st.top();
                st.pop();

                int res = operation(first, second, s[0]);
                st.push(res);
            }
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }

    int operation(int first, int second, char c){
        if (c == '+'){
            return first + second;
        }
        else if (c == '-'){
            return first - second;
        }
        else if (c == '*'){
            return first * second;
        }
        else{
            return first/second;
        }
    }
};
