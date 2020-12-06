#!/usr/bin/env python3

import hash_table
from hash_table import HashTable

if __name__ == '__main__':
	table = HashTable()
	table.add_value_with_key(123, "teste")
	table.add_value_with_key(124, "teste1")
	table.add_value_with_key(121, "teste2")
	table.add_value_with_key(125, "teste3")
	print(table.get_value_by_key(123))
	print(table.get_value_by_key(124))
	print(table.get_value_by_key(121))
	print(table.get_value_by_key(125))
	print(table._table)
	table.remove_value_by_key(123)
	print(table.get_value_by_key(123))
	print(table._table)
