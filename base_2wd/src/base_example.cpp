#include "base_2wd.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

  Base base;
  std::cout << "Go base forward..." << '\n';
  base.forward();
  std::cout << "Go base backward..." << '\n';
  base.backward();
  std::cout << "Go base left..." << '\n';
  base.left();
  std::cout << "Go base right..." << '\n';
  base.right();
  std::cout << "Go base stop..." << '\n';
  base.stop();

  return 0;
}
