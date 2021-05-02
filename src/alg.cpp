// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

int prior(char p) {
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
  TStack <char> stack1;
  std::string res_str;
  for (int i = 0; i < inf.length(); i++) {
    if ((int[i] >= '0') && (int[i] <= '9')) {
      res_str += int[i];
      res_str += ' ';
    }
    else if ((int[i] == '(') || (prior(int[i]) > prior(stack1.get())) || (stack1.isEmpty()))
      stack1.push(inf[i]);
    else if (int[i] == ')') {
      while (stack1.get() != '(' && !stack1.isEmpty()) {
        res_str += stack1.get();
        res_str += ' ';
        stack1.pop();
      }
    }
      else {
        while ((prior(int[i]) <= prior(stack1.get())) && (!stack1.isEmpty())) {
          res_str += stack1.get();
          res_str += ' ';
          stack1.pop();
        }
        stack1.push(inf[i]);
      }
  }
  while (!stack1.isEmpty()) {
    res_str += stack1.get();
    res_str += ' ';
    stack1.pop();
  }
  return res_str;
}
int eval(std::string pst) {
   TStack <int> stack2;
  for (i = 0; i < pst.length(); i++) {
    if ((pst[i] >= '0') && (pst[i] <= '9'))
      stack2.push(pst[i] - '0');
    else if (pst[i] != ' ') {
      int a = stack2.get();
      stack2.pop();
      int b = stack2.get();
      stack2.pop()
        stack2.push(oper(p, a , b));
    }
  }
  return stack2.get();
}
