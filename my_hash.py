#!/usr/bin/env python3

import hash_table
from hash_table import HashTable

if __name__ == '__main__':
	table = HashTable()
	for i in range(0, 1000, 1):
		table.add_value_with_key(i, i)
	for i in range(0, 1000, 1):
		table.find_value_by_key(i)
	# print(table._table)
	for i in range(0, 1000, 2):
		table.remove_value_by_key(i)
	# print(table._table)
