class Complex:
	def __init__(self,r,i):
		self.reel=r
		self.img=i

	def __str__(self):
		if self.img<0:
			return str(self.reel)+"-"+str(self.img)+"i"
		elif self.img>0:
			return str(self.reel)+"+"+str(self.img)+"i"
		else:
			return str(self.reel)		
		
	def __add__(self,oc):
		reel=self.reel+oc.reel
		imagine=self.img+oc.img
		return Complex(reel,imagine)

	def __sub__(self,oc):
		reel=self.reel-oc.reel
		imagine=self.img-oc.img
		return Complex(reel,imagine)

	def __mul__(self,oc):
		reel=(self.reel*oc.reel)-(self.img*oc.img)
		imag=(self.reel*oc.img)+(self.img*oc.reel)
		return Complex(reel,imag)
	
	def __div__(self,oc):
		ustr=(self.reel*oc.reel)+(self.img*oc.img)
		altr=oc.reel**2+oc.img**2
		
		usti=(self.img*oc.reel)-(self.reel*oc.img)
		alti=oc.reel**2+oc.img**2
		
		reel=str(ustr)+"/"+str(altr)
		imag=str(usti)+"/"+str(alti)
		return reel+" + "+ imag + " i"
	

a=Complex(3,-2)
b=Complex(1,-1)
c=a/b

print c

