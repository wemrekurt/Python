import math
def dalga(l,n):
	hesap=(2*l)/float(n)
	return "Lambda: " + str(hesap) + " cm ve Lambdakare: "+ str(hesap**2) + " cm"

def gerilme(m,g):
	t = float(m) * g
	return "Gerilme " + str(t) + " dyn"


def frekans(l):
	t=5*980
	mu = 2.5*(10**(-3))
	kk=math.sqrt(float(t)/mu)
	f=(1/l)*kk
	return f

dalsay = [7,6,5,4,3]
kutle = [5,7,10,18,30]
luzun = [112,95,80,62,50]
boliki = [32,31.66,32,31,33.33]

"""
for i, val in enumerate(luzun):
	print dalga(val,dalsay[i])

for j in kutle:
	print gerilme(j,980)
"""

for val in boliki:
	print frekans(val)
