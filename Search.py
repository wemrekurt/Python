class Search:
	def __init__(self,opens,val,closers):
		self.opens = opens
		self.val	 = val
		self.closers=closers

	def doit(self):
		i=0
		found=False
		
		while i<len(self.opens) and found==False:
			if self.val==self.opens[i]:
				found=True
			i=i+1

		if found==True:
			return self.closers[i-1]
		else:
			return False



dizi1=["Turkiye","Almanya","Fransa"]
dizi2=["Ankara","Berlin","Paris"]
x=Search(dizi1,"Fransa",dizi2)

print x.doit()
