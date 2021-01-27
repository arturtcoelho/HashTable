#!/usr/bin/env python3

import math

class HashTable():
	
	TABLE_SIZE = 11
	HASH_PRIMES = (19, 101, 17)
	t1 = [[] for i in range(TABLE_SIZE)]
	t2 = [[] for i in range(TABLE_SIZE)]

	def __init__(self, size = None):
		if size != None:
			self.TABLE_SIZE = size

	def h1(self, key):
		try: 
			key = int(key)
		except: 
			print("Key type error")
			return None

		return key % self.TABLE_SIZE

	def h2(self, key):
		try: 
			key = float(key)
		except: 
			print("Key type error")
			return None

		return math.floor(self.TABLE_SIZE * (key * 0.9 - math.floor(key * 0.9)))

	def add_value_with_key(self, key, value):
		index = self._hash_by_string(key)
		if index == None: 
			print("Index Error")
			return 0
		
		l = self._table[index]
		l = [i for i in l if i[0] == key]
		if len(l) > 0: 
			return 1

		self._table[index].append((key, value)[:])
		return 1

	def get_value_by_key(self, key):
		index = self._hash_by_string(key)
		if index == None: 
			print("Index Error")
			return None

		l = self._table[index]
		l = [i for i in l if i[0] == key]

		if len(l) > 0:
			return l[0][1]
		
		return None

	def find_value_by_key(self, key):
		index = self._hash_by_string(key)
		if index == None: 
			print("Index Error")
			return None

		l = self._table[index]
		l = list(filter(lambda t: t[0] == key, l))

		if len(l) > 0:
			return 1
		
		return 0

	def remove_value_by_key(self, key):
		index = self._hash_by_string(key)
		if index == None: 
			print("Index Error")
			return 0

		l = self._table[index]
		l = list(filter(lambda t: t[0] != key, l))
		self._table[index] = l
		
		return 1
