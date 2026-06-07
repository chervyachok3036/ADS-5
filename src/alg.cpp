// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

std::string infx2pstfx(const std::string& inf) {
  TStack<char, 100> st;
  std::string postf;
  std::string num;
  std::map<char, int> pr;
  pr['+'] = 1;
  pr['-'] = 1;
  pr['*'] = 2;
  pr['/'] = 2;

  for (size_t i = 0; i < inf.size(); i++) {
    char el = inf[i];
    if (el == ' ') {
      continue;
    }
    if (el >= '0' && el <= '9') {
      num += el;
    } else {
      if (!num.empty()) {
        postf += num + ' ';
        num.clear();
      }
      if (el == '(') {
        st.push(el);
      } else if (el == ')') {
        while (!st.isEmpty() && st.get() != '(') {
          postf += st.get();
          postf += ' ';
          st.pop();
        }
        st.pop();
      } else if (pr.count(el)) {
        while (!st.isEmpty() && pr.count(st.get()) &&
          pr[st.get()] >= pr[el]) {
          postf += st.get();
          postf += ' ';
          st.pop();
        }
        st.push(el);
      }
    }
  }
  if (!num.empty()) {
    postf += num + ' ';
  }
  while (!st.isEmpty()) {
    postf += st.get();
    postf += ' ';
    st.pop();
  }
  if (!postf.empty() && postf.back() == ' ') {
  postf.pop_back();
  return postf;
}

int eval(const std::string& pref) {
  TStack<int, 100> st;
  std::string num;

  for (size_t i = 0; i < pref.size(); ++i) {
    char el = pref[i];
    if (el >= '0' && el <= '9') {
      num += el;
    } else if (el == ' ') {
      if (!num.empty()) {
        st.push(std::stoi(num));
        num.clear();
      }
    } else if (el == '+' || el == '-'
      || el == '*' || el == '/') {
      int b = st.get(); st.pop();
      int a = st.get(); st.pop();
      int res = 0;
      if (el == '+') {
        res = a + b;
      } else if (el == '-') {
        res = a - b;
      } else if (el == '*') {
        res = a * b;
      } else if (el == '/') {
        res = a / b;
      }
      st.push(res);
    }
  }
  return st.get();
}
