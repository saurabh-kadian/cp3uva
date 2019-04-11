# UVa 623 - 500!
# C++ have to code the factorials in a 1000x1000 grid
# Row -> factorial of number = row
from sys import stdin

facts = [1] * 1005
def fact():
	facts[0] = 1
	x = 1
	for i in range(1, 1002 + 1):
		x *= i
		facts[i] = x
fact()
while True:
    try:
        x = int(input())
        print(str(x) + "!")
        print(facts[x])
    except EOFError:
        break
