#!/bin/bash
set -xue

test_pics="/home/keiohigh2nd/k-means/derm_data/MMZIP1/*"

#Trained histogram data
train1="/home/keiohigh2nd/k-means/derm_data/train_data/hist_data/fibrillar_desc.txt.txt"
train2="/home/keiohigh2nd/k-means/derm_data/train_data/hist_data/nails_desc.txt.txt"

g++ -o main.out -O2 main.cpp
g++ -o calc_similarity.out -O2 calc_similarity_derm.cpp

#Calculate distance from res_hist of test directory
for filepath in ${test_pics}
do
  python2.7 extract_sift_pic.py ${filepath}
  ./main.out res_desc.txt
  ./calc_similarity.out  ${train1} ${train2} res_hist.txt
  rm res_hist.txt
  rm res_desc.txt
done


echo done
