# -*- coding: utf-8 -*-

import os
import shutil
import stat

if __name__ == '__main__':

	dir = "/home/keiohigh2nd/k-means/derm_data/MMZIP2/"
	files = os.listdir(dir)

	f = open("res_class_hist.txt","r")
	lines = f.readlines()
	f.close()

	A_dir = "/home/keiohigh2nd/k-means/derm_data/A_dir"
	B_dir = "/home/keiohigh2nd/k-means/derm_data/B_dir"

	i = 0
	max = len(lines)
	for file in files:
		if i == max:
			break
		if lines[i].strip() == "A":
			shutil.move(dir + file,A_dir)
		else:
			shutil.move(dir + file,B_dir)
		i += 1


