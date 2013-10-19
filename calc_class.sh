#!/bin/bash
set -xu

files="/home/keiohigh2nd/k-means/ranked_hist/*"

g++ calc_similarity.cpp  
for filepath in ${files}
do  
  ./a.out ${filepath}
done

echo done
