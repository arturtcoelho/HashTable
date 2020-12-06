#!/usr/bin/env python3

class HashTable():
	
	TABLE_SIZE = 1000
	HASH_PRIMES = (19, 101, 17)
	_table = [[] for i in range(TABLE_SIZE)]
	stored = 0

	def __init__(self, size = None):
		if size != None:
			self.TABLE_SIZE = size

	def _hash_by_string(self, key):
		hash = self.HASH_PRIMES[0]
		try: 
			key = str(key)
		except: 
			print("Key type error")
			return None

		old_c = self.HASH_PRIMES[2]
		for i in key:
			c = ord(i)
			hash += (self.HASH_PRIMES[1] * c * old_c)
			old_c = c

		# return hash
		return hash % self.TABLE_SIZE

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
