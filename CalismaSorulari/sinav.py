# -*- coding: utf-8 -*-

#Soru 1

class Fraction:
	def __init__(self,top,bottom):
		self.num=top
		self.den=bottom
	
	def __str__(self):
		return str(self.num)+"/"+str(self.den)

	#1.a
	def humanize(self):
		tam=self.num/self.den
		new=self.num%self.den
		if new!=0:
			return str(tam)+' tam '+str(new)+' bölü '+str(self.den)
		else:
			return tam
	
	#1.b
	def todouble(self):
		return float(self.num)/self.den

	#1.c
	def fromdouble(self):
		n=raw_input('Sayı Girin: ')
		explode=str(n).split('.')
		us=len(explode[1])
		
		self.num=(int(explode[0]+explode[1])-int(explode[0]))
		self.den=(int('9'*us))
		return self.sadelestir()
	#1.d
	def toppercentile(self):
		topn=(100/self.den)*self.num
		return "%"+str(topn)
	
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
		

#x=Fraction(23333,10000)
a=Fraction(3,4)
print a.toppercentile()
#print x.humanize()
#print x.sadelestir()
print a.fromdouble()


#pi hesabı
"""
def pi(adim):
	if adim<=0 or adim>11:
		return "Hatalı argüman"
	else:
		dizi=[3,7,15,1,292,1,1,1,2,1,3,1]
		new=dizi[0:adim+1]
		gercel=new[::-1]
		payda=gercel[0]
		i=1
		while i<len(gercel):
			payda=gercel[i]+(float(1)/payda)
			i+=1

		pi=str(payda).split('.')
		pi=pi[0]+"."+pi[1][0:adim+1]
		return float(pi)

print pi(11)
"""
