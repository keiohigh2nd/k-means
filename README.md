Work Flow /n

images -> extract sift features -> output features with text file
-> k-nn cpp-> 10 dimension data -> text output

WorkFlow of Classify

1:train.sh
extraxt sift features

2:reduction.sh
convert sift features into K vectors

3:classify.sh
compare test picture and trained K vectors

Please be careful all K dimensions are the same
