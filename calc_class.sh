#!/bin/bash
set -xu

rm res_class_hist.txt

files="/home/keiohigh2nd/k-means/ranked_10_normal_hist/*"

g++ calc_similarity.cpp  
for filepath in ${files}
do  
  ./a.out ${filepath}
done

echo done
