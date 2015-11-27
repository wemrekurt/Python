import re

def yildiz(cumle):
	yeni=""
	kelime=cumle.split()
	for i in kelime:
		yeni=yeni+" "+str(re.sub('[aeiouAEIOU]','*',i))

	return yeni


print yildiz("test cumle")
			
