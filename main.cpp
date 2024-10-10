#include "state.hpp"
#include <iostream>

int main() {
  std::vector<int> traj{0, 8, 4, 2};
  State s;
  Move m(4, 2);
  Node n(s, m);

  s.status();
  s.board();
  for (auto &j : traj) {
    Move m(s.l, j);
    n.advance(m);
  }

  return 0;
}