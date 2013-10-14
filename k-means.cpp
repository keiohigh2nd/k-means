#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include "k-means.hpp"

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

int GetRandom(int min,int max) {
	return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}

//All nodes are set their id first
void K_means::init() {
  std::vector<int> init_point;

  for(size_t i=0; i < this->k; i++) {
    int tmp = GetRandom(0,this->nodes.size());
    init_point.push_back(tmp);
    this->nodes[tmp].id = i;
  }

  std::cout << "init point size is " << init_point.size() << std::endl;

  for(size_t i=0; i < this->nodes.size() ; i++) {
    double init_value = 10000;
    int init_id;
    for (size_t j=0; j < init_point.size() ; j++) {
      double tmp;
      tmp = dist_get(this->nodes[i].data, this->nodes[init_point[j]].data);
      if(tmp < init_value) {
        init_value = tmp;
        init_id = this->nodes[init_point[j]].id;
      }
    }
  set_id(i, init_id);
  }  
}


//After calculation of centers, set id
void K_means::nearest_id(const std::vector<std::vector<double> >&center) {
  for(size_t i=0; i < this->nodes.size() ; i++) {
   double init_value = 10000;
   int init_id;
   for (size_t j=0; j < center.size() ; j++) {
     double tmp;
     tmp = dist_get(this->nodes[i].data, center[j]);
     if(tmp < init_value) {
        init_value = tmp;
        init_id = j;
     }
   }
   set_id(i,init_id);
  }
}

//Calculation of centers
std::vector<std::vector<double> >K_means::calc_center() {
  std::vector<std::vector<int> >k_stack;
  k_stack.resize(this->k);

  std::vector<std::vector<double> >new_center;
  new_center.resize(this->k);

  for(size_t i=0; i < this->nodes.size() ; ++i) {
    int k_id = this->nodes[i].id;
    k_stack[k_id].push_back(i);
  }

  for(size_t i=0; i < this->k; i++) {
    new_center[i] = get_average(k_stack[i]);
  }

 return new_center;

}

//vector<double> average
std::vector<double> K_means::get_average(const std::vector<int>& a) {
  std::vector<double> res;
  res.resize(this->nodes[0].data.size());
  
  std::vector<Node> store;
  for(size_t i=0; i < a.size(); ++i) {
    store.push_back(this->nodes[a[i]]);
  }
  
  for(size_t i=0; i < store.size(); ++i) {
    for(size_t j=0; j < store[0].data.size(); ++j) {
      res[j] += store[i].data[j];
    }
  }

  for(size_t i=0; i < this->nodes[0].data.size() ; ++i) {
    double tmp = (double)res[i]/a.size();
    res[i] = tmp;
  }
  return res;
}

void K_means::sample() {
  int cols = 2;
  int data_size = 100;

  for(size_t i=0; i < data_size; ++i) {
    Node node;
    int x = GetRandom(0, 100);
    int y = GetRandom(0, 100);
    node.data.push_back(x);
    node.data.push_back(y);
    this->nodes.push_back(node);
  }

}

void K_means::show() {
  std::vector<int> total;
  total.resize(this->k);

  for(size_t i=0; i < this->nodes.size(); ++i) {
    int tmp = this->nodes[i].id;
    total[tmp] += 1;
  }

  for(size_t i=0; i < this->k; ++i) {
    std::cout << i <<"th group has " << total[i] << std::endl; 
  }

}
