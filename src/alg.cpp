// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

int priority(char p) {
  if ((p == '-') || (p == '+'))
    return 2;
  if ((p == '*') || (p == '/'))
    return 3;
  if (p == ')')
    return 1;
  if (p == '(')
    return 0;
  else
    return -1;
}
int oper(char p, int a, int b) {
  if (p == '-')
    return a - b;
  if (p == '+')
    return a + b;
  if (p == '*')
    return a * b;
  if (p == '/')
    return a / b;
}
std::string infx2pstfx(std::string inf) {
  std::string res_str;
  TStack <char> stack1;
  for (int i = 0; i < inf.length(); i++) {
   if (int[i] >= '0' && int [i] <= '9') {
     res_str += int[i] + ' ';
     else if (int[i] == '(' || priority(int[i]) > priority(stack.get()) || stack.isEmpty())
       stack.push(inf[i]);
     else if (int[i] == ')') {
       char a;
       do {
         a = stack.get();
         stack.pop();
         res_str +=a + ' ';
       } while (a != '(');
     }
     else {
       while (priority(int[i]) <= priority(stack.get()) && !stack.isEmpty()) {
         res_str += stack.get() + ' ';
         stack.pop();
       }
       stack.push(inf[i]);
     }
     while (!stack.isEmpty()) {
       res_str += stack.get() + ' ';
       stack.pop();
     }
     res_str.pop_back();
     return res_str;
  
}

int eval(std::string pst) {
   TStack <int> stack2;
  for (i = 0; i < pst.length(); i++) {
    if (pst[i] >= '0' && pst[i] <= '9')
      stack.push(pst[i] - '0');
    else if (pst[i] != ' ') {
      int a = stack.get();
      stack.pop();
      int b = stack.get();
      stack.pop()
        stack.push(oper(p, a , b));
    }
  }
  return stack2.get();
}
