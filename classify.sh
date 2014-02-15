#!/bin/bash
set -xue

test1="/home/keiohigh2nd/k-means/derm_data/test_data/"

train1="/home/keiohigh2nd/k-means/derm_data/train_data/"
train2="/home/keiohigh2nd/k-means/derm_data/train_data/"

#Extract Sift from each picture of test directory
for filepath in ${test1}
do
  python2.7 extract_sift.py ${filepath}
done


g++ -O2 calc_similarity_der.cpp
#Calculate distance from res_hist of test directory
for filepath in ${dir1}
do
  ./a.out ${train1} ${train2} ${filepath}
done


echo done
