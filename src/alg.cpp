// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

std::string infx2pstfx(std::string inf) {
  int pt(char p) {
  switch (p) {
    case '(':
      return 0;
    case ')':
      return 1;
    case '-':
    case '+':
      return 2;
    case '*':
    case '/':
      return 3;
    default:
      return -1;
  }
}
  TStack <char> s1;
  std::string res_str;
  for (int i = 0; i < inf.length(); i++) {
    if ((inf[i] >= '0') && (inf[i] <= '9')) {
      res_str += inf[i];
      res_str += ' ';
    } else if (inf[i] == '(' || pt(inf[i]) > pt(s1.get()) || s1.isEmpty()) {
      s1.push(inf[i]);
      } else if (inf[i] == ')') {
      while (s1.get() != '(' && !s1.isEmpty()) {
        res_str += s1.get();
        res_str += ' ';
        s1.pop();
      }
      if (s1.get() == '(') {
        s1.pop();
      }
    } else {
      while (pt(inf[i]) <= pt(s1.get()) && !s1.isEmpty()) {
        res_str += s1.get();
        res_str += ' ';
        s1.pop();
      }
      s1.push(inf[i]);
    }
  }
  while (!s1.isEmpty()) {
    res_str += s1.get();
    res_str += ' ';
    s1.pop();
  }
  while (res_str[res_str.length() - 1] == ' ') {
        res_str = res_str.substr(0, res_str.length()-1);
  }
  return res_str;
}
int eval(std::string pst) {
  int oper(char o, int a, int b) {
    switch (o) {
      case '+':
        return a + b;
        break;
      case '-':
        return a - b;
        break;
      case '*':
        return a * b;
        break;
      case '/':
        return a / b;
        break;
    }
  TStack <int> s2;
  for (int i = 0; i < pst.length(); i++) {
    if ((pst[i] >= '0') && (pst[i] <= '9')) {
      s2.push(pst[i] - '0');
    } else if (pst[i] != ' '
            ) {
      int a = s2.get();
      s2.pop();
      int b = s2.get();
      s2.pop();
      s2.push(oper(pst[i], a, b));
    }
  }
  return s2.get();
}
