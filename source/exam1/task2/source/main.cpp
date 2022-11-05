#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

const double beta = 0.0001;
const double gamma = 0.01;

struct State {
  double s;
  double i;
  double r;
};

State update(const State &state) {
  State next_state{.s = -beta * state.s * state.i + state.s,
                   .i = beta * state.i * state.s - gamma * state.i + state.i,
                   .r = gamma * state.i + state.r};

  return next_state;
}

void print_state(const State &state, int day) {
  cout << setw(10) << day 
      << setw(10) << round(state.s) 
      << setw(10) << round(state.r) 
      << setw(10) << round(state.i) 
      << endl;
}

int main() {
  State current_state{.s = 500, .i = 500, .r = 0};
  cout << setw(10) << "day" << setw(10) << "Sn" << setw(10) << "Rn" << setw(10)
       << "In" << endl;
  for (int day = 1; day <= 100; ++day) {
    print_state(current_state, day);
    current_state = update(current_state);
  }
  return 0;
}
