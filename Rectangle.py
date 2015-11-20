class Rectangle:
	def __init__(self,x,y,w,h):
		self.label = self
		self.w = w
		self.h = h
		self.x = x
		self.y = y
		self.output=None
		
	def __str__(self):
		self.output=self
		if self.output>0:
			return self.output	
		else:
			return "Hatali Islem!"

	def __add__(self,rect2):
		return self.h+self.w+rect2.x-self.x+abs(rect2.h-(self.h-rect2.y))+rect2.h+rect2.w+abs(rect2.w+rect2.x-self.w)+rect2.y-self.y

	def __mul__(self,rect2):
		eks1w=abs(abs(rect2.x-self.x)-abs(self.w-rect2.w))
		eks2h=abs(abs(rect2.y-self.y)-abs(self.h-rect2.h))

		eks1=eks1w*(abs(rect2.y-self.y))
		eks2=eks2h*(abs(rect2.x-self.x))

		ga=(eks1w+self.w)*(eks2h+self.h)

		Alan=ga-(eks1+eks2)
		return Alan

	def __sub__(self,rect2):
		ich=abs(self.h-abs(rect2.y-self.y))
		icw=abs(self.w-abs(rect2.x-self.x))
		
		icevre=(2*icw)+(2*ich)
		return icevre
	
	def __div__(self,rect2):
		ich=abs(self.h-abs(rect2.y-self.y))
		icw=abs(self.w-abs(rect2.x-self.x))
		
		icalan=ich*icw
		return icalan
	
rg1=Rectangle(0,0,8,5)
rg2=Rectangle(3,2,7,4)

rg3= rg1/rg2		

print rg3

