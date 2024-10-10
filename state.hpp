#include <vector>

class Move {
public:
  int l, t;
  Move(int l, int t);
};

class State {
  std::vector<double> a;
  double transfer(int i, int j);
public:
  State();
  ~State() {}
  void update(Move m);
  void board();
  void status();

  int l, t;
  std::vector<int> ts;
  std::vector<int> h;
  double d;
};

class Node {
public:
  Node(State s, Move m);
  void advance(Move m);
  State s;
  Move m;
};