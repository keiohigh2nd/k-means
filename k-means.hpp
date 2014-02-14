#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <time.h>
#include <sys/time.h>

struct Node {
  std::vector<double> data;
  int id;
};

class K_means {

  public:
    void set_k(int i){this->k = i;}
    void set_id(int i, int p){this->nodes[i].id = p;}
    void init();
    void nearest_id(const std::vector<std::vector<double> >&center);
    std::vector<std::vector<double> > calc_center();
    std::vector<double> get_average(const std::vector<int>& a);
    void sample();
    void load_data(std::string);
    void load_descriptors(std::vector<std::vector<double> >&desc);
    std::vector<double> desc();
    void show();
  private:
    std::vector<Node> nodes;
    int k; 
};

