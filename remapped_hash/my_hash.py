#!/usr/bin/env python3

import hash_table
from hash_table import HashTable

if __name__ == '__main__':
	table = HashTable()
	for i in range(12):
		print(table.h1(i), table.h2(i))