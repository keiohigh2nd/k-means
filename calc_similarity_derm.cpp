#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include "similarity.hpp"


int main(int argc, char *argv[]) {

    std::vector<double> a = load_array(argv[1]);
    std::vector<double> b = load_array(argv[2]);
    std::string q_name = argv[3];
    std::vector<double> q = load_array(q_name);

    double dist_a = dist_get(a,q);
    double dist_b = dist_get(b,q);

    std::ofstream ofs( "res_class_hist.txt",std::ios::app);  
    if(dist_a > dist_b){
      ofs << "B" << std::endl;
    }else{
      ofs << "A" << std::endl;
    }

 return 0;
}
