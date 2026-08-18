class Solution {
public:
    int calculate(int a, int b, char op){
        switch(op){
            case '+': return a+b; 
            case '-': return a-b; 
            case '*': return a*b;
            case '/': 
               if (b != 0) return a / b; 
        }
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string &c:tokens){
            if(c == "+" || c == "-"  || c == "*"  || c == "/" ){
                if(st.size()>=2){
                    int top1 = st.top();
                    st.pop();
                    int top2 = st.top();
                    st.pop();
                    int ans = calculate(top2,top1,c[0]);
                    st.push(ans);
                }
            }
            else{
                st.push(stoi(c));
            }
        }

        return st.top();
    }
};
