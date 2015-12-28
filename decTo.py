"""
hexadecimal -> 16'lik sistem 	'0x100'
decimal		-> 10'luk sistem 	'100'
octal		-> 8'lik sistem		'0100'
binary		-> 2'lik sistem		'0b100'
"""
from Stack import *

class Converter:
	def __init__(self,val,base):
		self.val = val
		self.base = base

	def decTo(self):
		digits = "0123456789ABCDEF"
		remstack = Stack()

		while self.val > 0:
			rem = self.val % self.base
			remstack.push(rem)
			self.val = self.val / self.base

		newOne = ""
		while not remstack.isEmpty():
			newOne = newOne + digits[remstack.pop()]

		return newOne

	def toDec(self):
		giveme = raw_input("BirSayiGiriniz: ")

		if giveme[0] != '0':
			return False
		else:
			if giveme[1] == 'x':
				# TODO : return hexafunc
				return self.cToDec(giveme,16)
			elif giveme[1] == 'b':
				# TODO : return binaryfunc
				return 1
			else:
				# TODO : return octal func.
				return 1


	def cToDec(self,given,base):
		given = given.split('x')
		clear = given[1][::-1]
		x=[]

		for i, val in enumerate(clear):
			work = (base ** (i+1)) * int(val)
			x.append(work)

	def convert(self,pol):
		if pol == 'r/[A-Z]'
			

test = Converter(25,13)
print test.toDec()

		
