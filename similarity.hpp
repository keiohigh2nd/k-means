#pragma once  

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <fstream>

std::vector<double> load_array(std::string file_name) {

    const std::string g_file_name = file_name;
    std::ifstream g_file(g_file_name.c_str());
    if (!g_file){
        std::cerr << "Failed to open file: file name=" << g_file_name << std::endl;
    }

    std::string g_temp;
    std::vector<double> a;
    while (std::getline(g_file, g_temp)) {
                std::stringstream ss(g_temp);
                for (double x; ss>>x;) {
                        a.push_back(x);
          }
    }

   return a;
}

double dist_get(const std::vector<double>& a, const std::vector<double>& b) {
  if(a.size() != b.size()) {
    std::cout << "error dist_get" << std::endl;
  }
  double sum = 0;
  for(size_t i=0; i < a.size(); i++) {
    double tmp = a[i]-b[i];
    sum += tmp*tmp;
  }
  return sum;
}
