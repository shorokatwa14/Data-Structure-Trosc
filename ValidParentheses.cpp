#include <iostream>
#include <stack>
using namespace std;
int main() {
    string s="(())())";
        stack <char> st;
        bool valid = true;
        for (int i = 0 ;i<s.size();i++){
            if (s[i] == '(')
                st.push('(');
            else if (s[i] == ')' && !st.empty())
                st.pop();
            else
                valid = false;

        }
        if (valid) cout << "Balanced";
        else cout << "Not Balanced";
    return 0;
}
