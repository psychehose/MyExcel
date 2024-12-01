#ifndef UTILS_H
#define UTILS_H

#include <string>

namespace MyExcel {

class Vector {
  std::string* data;
  int capacity;
  int length;

 public:
  
  Vector(int n = 1);
  ~Vector();

  void push_back(std::string s);
  std::string operator[](int i);

  void remove(int x);
  int size();
};

class Stack {
  struct Node {
    Node* prev;
    std::string s;

    Node(Node* prev, std::string s) : prev(prev), s(s) {}
  };

  Node* current;
  Node start;

public:
  Stack();
  ~Stack();

  void push(std::string s);
  std::string pop();
  std::string peek();
  bool is_empty();

};
class NumStack {
  struct Node {
    Node* prev;
    double s;

    Node(Node* prev, double s) : prev(prev), s(s) {}
  };

  Node* current;
  Node start;

public:
  NumStack();
  ~NumStack();

  void push(double s);
  double pop();
  double peek();
  bool is_empty();
};

} // namespace MyExcel
#endif