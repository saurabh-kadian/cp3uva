# UVa 324 - Factorial Frequencies
# from __future__ import print_function            # making compatibility with python 2.x

from sys import stdin

facts = [1] * 400
def fact():
	facts[0] = 1
	x = 1
	for i in range(1,390 + 1):
		x *= i
		facts[i] = x
fact()

x = int(input())
while x != 0:
    print(str(x) + "!" + " --")
    stringVal = str(facts[x])
    number = [0] * 10
    for i in stringVal:
        number[int(i)] += 1

    print("   (0) {:4}    (1) {:4}    (2) {:4}    (3) {:4}    (4) {:4}".format(number[0], number[1], number[2], number[3], number[4]))
    print("   (5) {:4}    (6) {:4}    (7) {:4}    (8) {:4}    (9) {:4}".format(number[5], number[6], number[7], number[8], number[9]))
    
    x = int(input())
