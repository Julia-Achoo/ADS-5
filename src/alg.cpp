// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"
bool isDigit(char l) {
return (l >= '0' && l <= '9');
}
bool isOperator(char x) {
return (x == '+'  x == '-'  x == '*'  x == '/'   x == '('  x == ')');
}
int prior(char m) {
if (m == '+'  m == '-')
return 1;
if (m == '*' || m == '/')
return 2;
return 0;
}
std::string infx2pstfx(std::string inf) {
std::string p;
int count = 0;
TStack <char, 100> stack;
for (char c : inf) {
if (isDigit(c)) {
count++;
if (count == 1) {
p += c;
continue;
}
p = p + ' ' + c;
} else if (isOperator(c)) {
if (c == '(') {
stack.push(c);
} else if (stack.isEmpty()) {
stack.push(c);
} else if (prior(c) > prior(stack.get())) {
stack.push(c);
} else if (c == ')') {
while (stack.get() != '(') {
p = p + ' ' + stack.get();
stack.pop();
}
stack.pop();
} else {
int q = prior(c);
int r = prior(stack.get());
while (!stack.isEmpty() && q <= r) {
p = p + ' ' + stack.get();
stack.pop();
}
stack.push(c);
}
}
}
while (!stack.isEmpty()) {
p = p + ' ' + stack.get();
stack.pop();
}
return p;
}
int eval(std::string pref) {
TStack <int, 100> stack;
for (char c : pref) {
if (isDigit(c)) {
stack.push(c - '0');
} else if (isOperator(c)) {
int q = stack.get();
stack.pop();
int r = stack.get();
stack.pop();
switch (c) {
case '+':
stack.push(q + r);
break;
case '-':
stack.push(r - q);
break;
case '*':
stack.push(q * r);
break;
case '/':
stack.push(r / q);
break;
default:
continue;
}
} else {
continue;
}
}
return stack.get();
}
