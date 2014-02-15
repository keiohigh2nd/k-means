#!/bin/bash
set -xue

dir1="/home/keiohigh2nd/k-means/derm_data/train_data/*"
g++ -O2 main.cpp

for filepath in ${dir1}
do
  ./a.out ${filepath}
  mv res_hist.txt ${filepath}.txt
done

mv /home/keiohigh2nd/k-means/derm_data/train_data/*.txt.txt /home/keiohigh2nd/k-means/derm_data/train_data/hist_data/

echo done
