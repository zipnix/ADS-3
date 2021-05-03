// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

int pr(char p) {
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
  TStack <char> st1;
  std::string res_str;
  for (int i = 0; i < inf.length(); i++) {
    if ((inf[i] >= '0') && (inf[i] <= '9')) {
      res_str += inf[i];
      res_str += ' ';
    } else {
      if ((inf[i] == '(') || (pr(inf[i]) > pr(st1.get())) || (st1.isEmpty())) {
        st1.push(inf[i]);
      } 
    } else {
      if (inf[i] == ')') {
        while (st1.get() != '(' && !st1.isEmpty()) {
          res_str += st1.get();
          res_str += ' ';
          st.pop();
        }
      }
    } else {
      while ((pr(inf[i]) <= pr(st1.get())) && (!st1.isEmpty())) {
        res_str += st1.get();
        res_str += ' ';
        st1.pop();
      }
      st1.push(inf[i]);
    }
  }
  while (!st1.isEmpty()) {
    res_str += st1.get();
    res_str += ' ';
    st1.pop();
  }
  return res_str;
}
int eval(std::string pst) {
  TStack <int> st2;
  for (int i = 0; i < pst.length(); i++) {
    if ((pst[i] >= '0') && (pst[i] <= '9'))
      st2.push(pst[i] - '0');
    else {
      if (pst[i] != ' ') {
        int a = st2.get();
        st2.pop();
        int b = st2.get();
        st2.pop()
          st2.push(oper(p, a , b));
      }
    }
  }
  return st2.get();
}
