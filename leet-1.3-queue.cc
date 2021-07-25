//queue
#include <queue>
void test() {
  queue<int> que;
  que.push(1);
  que.front();
  que.pop();
}

template<typename T> class queue {
public:
  queue(int size):max(size) {
    data = new T[max];
    front=rear=0;
  }
  void push(T e) {
    if (front==(rear+1)%max) return;
    data[(++rear)%max] = x;
  }
  T pop() {
    if (front == rear) return;
    return data[(front++)%max];
  }
private:
  T* data;
  int max, front, rear;
};
