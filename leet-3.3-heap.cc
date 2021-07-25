//heap

#include <queue>
void test() {
  priority_queue<int> pque;
  pque.push(10);
  while(!pque.empty()) {
    int t = pque.top();
    pque.pop();
  }
}

int heap[1000], sz = 0;
void push(int x) {

}

int pop() {

}
