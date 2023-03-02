#include <iostream>
#include <stack>

bool is_right(std::string& l) {
    std::stack<char> st;
    st.push(l[0]);
    for (int i = 1; i < l.size(); i++) {
        if (l[i] - 1 == st.top() || l[i] - 2 == st.top()) {
            st.pop();
        }
        else {
            st.push(l[i]);
        }
    }
    return st.empty();
}
int main()
{
    std::string l =  "((({}])))";
    if (is_right(l)) {
        std::cout << "YES" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }
}

