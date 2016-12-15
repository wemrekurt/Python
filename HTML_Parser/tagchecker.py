#Html parse
import re

def html_filter(doc):
	f = open(doc,'r')
	fil = f.readlines()

	first, new, last=[],[],[]

	for i in fil:
		i=i.strip('\n\t')
		first.append(i)
	
	regex = "(?i)<\/?\w+((\s+\w+(\s*=\s*(?:\".*?\"|'.*?'|[^'\">\s]+))?)+\s*|\s*)\/?>"	
	
	for g in first:
		for match in re.finditer(regex,g):
			new.append(match.group())
	
	for j in new:
		spli=j.split(" ")
		spli[0]=spli[0].translate(None,'<>')
		if len(spli)>1:
			last.append(spli[0])
		else:
			last.append(spli[0])

	
	return last


x=html_filter('index.html')

print x
	
	
