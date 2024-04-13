// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>

template<typename T, int size>
class TStack {
private:
T arr[size];
int f;
public:
TStack(): f(-1) {}
void push(T value) {
if (!isFull())
arr[++f] = value;
else
throw std::string("total");
}
T get() const {
return arr[f];
}
T pop() {
if (isEmpty())
throw std::string("null");
else
return arr[f--];
}
bool isEmpty() const {
return f == -1;
}
bool isFull() const {
return f == size - 1;
}
};

#endif  // INCLUDE_TSTACK_H_
