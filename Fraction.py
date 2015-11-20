# -*- coding: utf-8 -*-
class Fraction:
	def __init__(self,pay,payda):
		self.num=pay
		self.den=payda

	def __str__(self):
		return str(self.num)+"/"+str(self.den)

	def __add__(self,dk):
		p=self.num*dk.den+dk.num*self.den
		pd=self.den*dk.den
		return Fraction(p,pd)

	def __sub__(self,other):
		py=self.num*other.den-other.num*self.den
		pyd=self.den*other.den
		return Fraction(py,pyd)

	def __mul__(self,ok):
		ust=self.num*ok.num
		alt=self.den*ok.den
		return Fraction(ust,alt)

	def __div__(self,bol):
		p=self.num*bol.den
		pd=self.den*bol.num
		return Fraction(p,pd)

	def sadelestir(self):
		if self.num > self.den:
			i=self.den
		elif self.num==self.den:
			i=1
			self.num=1
			self.den=1
		else:
			i=self.num
		while i>1:
			if self.den%i == 0 and self.num%i == 0:
				self.den=self.den/i
				self.num=self.num/i
			i=i-1
		return Fraction(self.num,self.den)

	def equal(self,other):
		if self.num == other.num and self.den == other.den:
			return True
		else:
			return False
			
	

f4=Fraction(6,9)
f5=Fraction(6,9)
#print f4.equal(f5)
print f4.sadelestir()

#f1=Fraction(2,3)
#f2=Fraction(1,4)
#f3=f1*f2
#print "Orjinal: " + str(f3)
#print "Sade: " + str(f3.sadelestir())

