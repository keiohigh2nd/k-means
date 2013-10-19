#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include "k-means.cpp"


int main(int argc, char *argv[]) {

  int num_iterations = 100;
  int K = 7;

  std::string file_name = argv[1];
  K_means km;
  km.set_k(K);
  km.load_data(file_name);
  km.init();

  for (size_t i =0; i < num_iterations; ++i) {
   std::vector<std::vector<double> >res = km.calc_center();
   km.nearest_id(res);
  }

  km.show();

 return 0;
}
