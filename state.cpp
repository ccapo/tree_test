#include "state.hpp"
#include <cmath>
#include <iostream>

Move::Move(int l, int t) : l(l), t(t) {}

State::State() : l(2), t(4), d(0.0) {
  for (int i = 0; i < 9; i++) {
    ts.push_back(i);
  }
  a.push_back(0.38709927);
  a.push_back(0.72333566);
  a.push_back(1.00000261);
  a.push_back(1.52371034);
  a.push_back(5.20288700);
  a.push_back(9.53667594);
  a.push_back(19.18916464);
  a.push_back(30.06992276);
  a.push_back(39.44506973);
  h.push_back(l);
}

double State::transfer(int i, int j) {
  double begin_a = a[i];
  double end_a = a[j];
  double orbit_a = 0.5 * (begin_a + end_a);
  double period = pow(orbit_a, 1.5);
  double duration = 0.5 * period;
  return duration;
}

void State::update(Move m) {
  double dur = transfer(l, m.t);
  d += dur;
  l = m.t;
  h.push_back(l);
}

void State::status() {
  printf("l = %d, t = %d, d = %f, h = [", l, t, d);
  for (int i = 0; i < h.size(); i++) {
    if (i == h.size() - 1) {
      printf("%d", h[i]);
    } else {
      printf("%d, ", h[i]);
    }
  }
  printf("]\n");
}

void State::board() {
  int p = 6 * l + 3;
  std::string player = "@";
  std::string label = "|     |     |     |     |     |     |     |     |     |";
  label.replace(p, 1, player);
  printf("+-----+-----+-----+-----+-----+-----+-----+-----+-----+\n");
  printf("| Mer | Ven | Ear | Mar | Jup | Sat | Ura | Nep | Plu |\n");
  printf("+-----+-----+-----+-----+-----+-----+-----+-----+-----+\n");
  printf("%s\n", label.c_str());
  printf("+-----+-----+-----+-----+-----+-----+-----+-----+-----+\n");
}

Node::Node(State s, Move m): s(s), m(m) {}

void Node::advance(Move m) {
  s.update(m);
  s.status();
  s.board();
}