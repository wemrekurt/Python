def kucuk(cumle):
	kelime=cumle.split()
	toplam=0
	for i in kelime:
		for j in i:
			if j.islower():
				toplam+=1
	
	return str(toplam)


cumle=raw_input("Cumleyi Gir: ")

print kucuk(cumle)+" kucuk harf bulunmaktadir"	
