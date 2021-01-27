#!/usr/bin/env python3

import math

class HashTable():
	
	TABLE_SIZE = 11
	HASH_PRIMES = (19, 101, 17)
	t1 = [None for _ in range(TABLE_SIZE)]
	t2 = [None for _ in range(TABLE_SIZE)]

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

	def search(self, key):
		i = self.h1(key)
		if i == None: 
			print("Index Error")
			return None

		if (self.t1[i] == None):
			return None

		if (self.t1[i] == key):
			return i

		return self.h2(key)

	def insert(self, key):
		i = self.h1(key)
		if i == None: 
			print("Index Error")
			return
		
		if (self.t1[i] == None or self.t1[i] == -1):
			self.t1[i] = key
			return

		if (self.t1[i] == key):
			return
		
		k2 = self.t1[i]
		j = self.h2(k2)
		self.t2[j] = k2

		self.t1[i] = key
		return
		
	def remove(self, key):
		j = self.h2(key)
		if j == None: 
			print("Index Error")
			return
		
		if (self.t2[j] == key):
			self.t2[j] = None
			return

		i = self.h1(key)
		if i == None: 
			print("Index Error")
			return

		self.t1[i] = -1
		return

	def print(self):
		for i in range(self.TABLE_SIZE):
			print("{} {}".format(self.t1[i], self.t2[i]))
		print()

	def line_print(self):
		outs = []
		for i in range(self.TABLE_SIZE):
			if (self.t1[i] != None and self.t1[i] != -1):
				outs.append(tuple((self.t1[i], "T1", i)))
		for i in range(self.TABLE_SIZE):
			if (self.t2[i] != None and self.t2[i] != -1):
				outs.append(tuple((self.t2[i], "T2", i)))
		
		outs.sort(key = lambda t: t[0])
		for l in outs:
			print("{},{},{}".format(l[0], l[1], l[2]))