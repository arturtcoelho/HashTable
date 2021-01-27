#!/usr/bin/env python3

import hash_table
from hash_table import HashTable

if __name__ == '__main__':
	table = HashTable()
	table.add_value_with_key("posição da carol" ,"4272")
	# for i in range(0, 1000, 1):
	# 	table.add_value_with_key(i, i)
	# for i in range(0, 1000, 1):
	# 	table.find_value_by_key(i)
	table.add_value_with_key("posição do artur" ,"666")
	table.add_value_with_key("chave" ,"coisa")
	table.add_value_with_key("chave da carol" ,"carol")
	table.add_value_with_key("chave" ,"valor")
	print(table._table)
	# for i in range(0, 1000, 2):
	# 	table.remove_value_by_key(i)
	# print(table._table)
