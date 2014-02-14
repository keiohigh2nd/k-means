#coding:utf-8

import numpy as np
from sklearn.ensemble import RandomForestClassifier

def load(foldr_name):
    files = os.listdir(foldr_name)
    train_data = []
    for file in files:
		tmp = []
                if file == '.DS_Store':
                        print 'skip'
                else:
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
  
  i = 0
  print len(train0)
  test_foldr = argvs[3]
  test = load(test_foldr)
  test_t = []
  
  for i in xrange(len(test)):
    test_t.append(0)

  model = RandomForestClassifier()
  model.fit(train0, t)
  
  for xa in test:
    output = model.predict(xa)
    print output
    i += 1
  
  print i

