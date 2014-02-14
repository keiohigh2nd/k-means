
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

  import numpy as np
  from sklearn.cluster import KMeans
  from sklearn import metrics
 
  argvs = sys.argv
  train_foldr = argvs[1]

  X = load(train_foldr)

  kmeans_model = KMeans(n_clusters=3, random_state=1).fit(X)
  labels = kmeans_model.labels_
  metrics.silhouette_score(X, labels, metric='euclidean')

  print labels
