#!/bin/bash
set -xue

dir1="/home/keiohigh2nd/k-means/derm_data/ncn_g/"
#dir2="/home/keiohigh2nd/k-means/derm_data/malignant_melanoma/"
dir2="/home/keiohigh2nd/k-means/derm_data/nails/"

for filepath in ${dir1}
do
  python2.7 extract_sift.py ${filepath}
done

for filepath in ${dir2}
do
  python2.7 extract_sift.py ${filepath}
done



echo done
