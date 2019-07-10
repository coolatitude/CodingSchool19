# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    launch.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/14 16:10:36 by pvanderl          #+#    #+#              #
#    Updated: 2019/05/23 22:33:49 by pvanderl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import os
import random
import matplotlib.pyplot as plt
import statistics as st
import sys
import argparse

from common import *

#Default python version:
pyvers = "python3.7 "

ps = argparse.ArgumentParser(prog="launch.py", description="tools for push_swap")
ps.add_argument('file', metavar='program', type=str, help="the push_swap/checker program/file to test")
ps_group = ps.add_argument_group('push_swap')
ps_group.add_argument('-i', metavar='N', type=int, default=200, help="inspect the output of the program")
ps_group.add_argument('-g', metavar='N', type=int, default=500, help="show a graph from 0 to N entries")
ps_group.add_argument('-m', metavar='N', type=int, default=500, help='do the mean on N input args. default N = 500')
ps_group.add_argument('-t', metavar='N', type=int, help="number of tests done. default = 200")
ch_group = ps.add_argument_group('checker')
ch_group.add_argument('-c', nargs=2, metavar=(""))

args = ps.parse_args()

program = args.file
if program.startswith("./"):
	program = program[2:]
if program.endswith(".py"):
	program = pyvers + program
else:
	program = "./" + program
program += " "

if not args.t:
	time = 200

if args.g:
	print("graph")
if args.m:
	print("mean")
if args.i:
	print("inspect push_swap")
elif args.c:
	print("inspect checker")


#com = "python3.7 V1.2.py "
times = 200

maxEntries = 500
numberEntries = 100

nbnumbers = []
results = []



'''
elif "-g" in sys.argv:
	while times > 0:
		n = round(random.random() * maxEntries)
		numbers = []
		while n > 0:
			x = round(random.random() * 2 * 2147483648) - 2147463648
			if not x in numbers:
				numbers.append(x)
			n -= 1
		result = os.popen(com + ' '.join(str(x) for x in numbers)).read().count('\n');
		results.append(result)
		nbnumbers.append(len(numbers))
		times -= 1

	plt.plot(nbnumbers, results, 'ro')
	plt.show()
elif "-c" in sys.argv:
	versions = os.listdir("./old/")
elif "-s" in sys.argv:
	nb = int(sys.argv[sys.argv.index("-s") + 1])
	n = nb
	a = []
	b = []
	while n > 0:
		x = round(random.random() * 2 * 2147483647) - 2147483648
		if not x in a:
			a.append(x)
			n -= 1
	result = os.popen(com + ' '.join(str(x) for x in a)).read()
	for l in result.splitlines():
		if l == "sa" and len(a) > 1:
			a = sx(a)
		elif l == "sb" and len(b) > 1:
			b = sx(b)
		elif l == "ss" and len(b) > 1 and len(a) > 1:
			a = sx(a)
			b = sx(b)
		elif l == "pa" and len(b) > 0:
			a, b = px(a, b)
		elif l == "pb" and len(a) > 0:
			b, a = px(b, a)
		elif l == "ra":
			a = rx(a)
		elif l == "rb":
			b = rx(b)
		elif l == "rr":
			a, b = rr(a, b)
		elif l == "rra":
			a = rrx(a)
		elif l == "rrb":
			b = rrx(b)
		elif l == "rrr":
			a, b = rrr(a, b)
	sorted = True
	for i, x in enumerate(a):
		if i < len(a) - 1 and x < a[i + 1]:
			sorted = False
	if sorted:
		print("OK")
	else:
		print("KO")
		print('\n'.join(str(x) for x in a))

else:
	if len(sys.argv) != 1:
		numberEntries = int(sys.argv[1])
	time2 = times
	while times > 0:
	    numbers = []
	    n = numberEntries;
	    while n > 0:
	        x = round(random.random() * 2 * 2147483648) - 2147463648
	        if not x in numbers:
	            numbers.append(x)
	            n -= 1
	    result = os.popen(com + ' '.join(str(x) for x in numbers)).read().count('\n')
	    results.append(result)
	    times -= 1
	print("nombre d'entrees: " + str(numberEntries) + "\nnombre d'actions: " + str(st.mean(results)))
'''
