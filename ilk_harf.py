def ilkbuyuk(cmle):
	kelime=cmle.split()
	yeni=""
	for i in kelime:
		yeni=yeni+" "+i.capitalize()
	return yeni

cumle=raw_input('Cumle girin ')

print ilkbuyuk(cumle)
