#!/bin/python

if __name__ == '__main__':
	counter_var1 = 0
	counter_var2 = 0
	for arr in [[(int(line.strip('\n').split(' ')[0].split("-")[0]), int(line.strip('\n').split(' ')[0].split('-')[-1])), line.strip('\n').split(' ')[1].strip(':'), line.strip('\n').split(' ')[-1]] for line in open('input', 'r').readlines()]:
		counter_var1 += (arr[0][0] <= arr[2].count(arr[1]) <= arr[0][1])
		counter_var2 += ((arr[2][arr[0][0] - 1] == arr[1]) ^ (arr[2][arr[0][1] - 1] == arr[1]))
	print(f"Day2 Part1: {counter_var1}")
	print(f"Day2 Part2: {counter_var2}")
