#coding:utf-8

import numpy as np
from sklearn.svm import SVC

def load(foldr_name):
    files = os.listdir(foldr_name)
    train_data = []
    for file in files:
		tmp = []
                if file == '.DS_Store':
                        print 'skip'
                else:
		    print foldr_name
		    print file
		    f = open(foldr_name+file)
		    lines = f.readlines()
		    f.close()
                    for x in lines:
		        tmp.append(x)
		    train_data.append(tmp)
    return train_data


if __name__ == "__main__":
  import sys, os, getopt
  argvs = sys.argv
  train_foldr = argvs[1]
  train_foldr1 = argvs[2]
 
  train0 = load(train_foldr)
  train1 = load(train_foldr1)

  t = []
  for i in xrange(len(train0)):
    t.append(0)
  for i in xrange(len(train1)):
    t.append(1)

  train0.extend(train1)
  
  clf = SVC()
  clf.fit(train0, t)
  count = 0
  i = 0


  test_foldr = argvs[3]
  test = load(test_foldr)
  test_t = []
  
  for i in xrange(len(test)):
    test_t.append(0)

  print len(test_t)
  print len(test)
  for xa in test:
      print clf.predict([xa])
      count += 1
      i += 1
  print count
  print i

