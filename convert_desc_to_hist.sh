#!/bin/bash
set -xu

files="/home/keiohigh2nd/k-means/ranked_desc/*"

g++ main.cpp
for filepath in ${files}
do  
  ./a.out ${filepath}
  mv res_hist.txt ${filepath}_hist.txt 
done

echo done
