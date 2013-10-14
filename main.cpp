#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include "k-means.cpp"

int main(int argc, char *argv[]) {

  int num_iterations = 10;
  int K = 5;

  K_means km;
  km.set_k(K);
  km.sample();
  km.init();

  for (size_t i =0; i < num_iterations; ++i) {
   std::vector<std::vector<double> >res = km.calc_center();
   km.nearest_id(res);
  }

  km.show();

 return 0;
}
