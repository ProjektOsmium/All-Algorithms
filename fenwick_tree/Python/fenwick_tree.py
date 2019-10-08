#!/usr/bin/env python3

"""
Binary Indexed Tree / Fenwick Tree
https://www.hackerearth.com/practice/notes/binary-indexed-tree-made-easy-2/
https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/
https://www.youtube.com/watch?v=v_wj_mOAlig
https://www.youtube.com/watch?v=kPaJfAUwViY
"""


def update(index, value, array, bi_tree):
	"""
	Updates the binary indexed tree with the given value
	:param index: index at which the update is to be made
	:param value: the new element at the index
	:param array: the input array
	:param bi_tree: the array representation of the binary indexed tree
	:return: void
	"""

	while index < len(array):
		bi_tree[index] += value
		index += index & -index


def get_sum(index, bi_tree):
	"""
	Calculates the sum of the elements from the beginning to the index
	:param index: index till which the sum is to be calculated
	:param bi_tree: the array representation of the binary indexed tree
	:return: (integer) sum of the elements from beginning till index
	"""
	ans = 0

	while index > 0:
		ans += bi_tree[index]
		index -= index & -index

	return ans


def get_range_sum(left, right, bi_tree):
	"""
	Calculates the sum from the given range

	:param bi_tree: the array representation of the binary indexed tree
	:param left: left index of the range (1-indexed)
	:param right: right index of the range (1-indexed)
	:return: (integer) sum of the elements in the range
	"""
	ans = get_sum(right, bi_tree) - get_sum(left - 1, bi_tree)

	return ans


def main():
	n = int(input('Enter the number of elements: '))
	arr = [int(x) for x in input('Enter the {} elements of the array: '.format(n)).split()]
	arr.insert(0, 0)   # insert dummy node for 1-based indexing
	bit = [0 for i in range(n+1)]

	for index in range(1, n+1):
		update(index, arr[index], arr, bit)

	"""
	For range sum queries
		l, r = map(int, input('Enter the left and right indices for the range sum: ').split())
		print(get_range_sum(l, r, bit))

	For updating the binary indexed tree
		update(index, new_value - arr[index], arr, bit)
	"""


if __name__ == '__main__':
	main()
