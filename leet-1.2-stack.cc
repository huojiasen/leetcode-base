//stack
#include <stack>
void test() {
  stack<int> st;
  st.push(1);st.top();st.pop();
}
// self relization
template<typename T> class stack {
public:
  stack(int size):max(size) {
    data = new T[max];
    top = -1;
  }
  void push(T e) {
    if (top==(max-1)) {
      return;
    }
    data[++top] = e;
  } 
  T pop() {
    if (top == -1) return;
    return data[top--];
  }
private:
  T *data;
  int max;
  int top;
}
