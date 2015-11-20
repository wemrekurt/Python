# -*- coding: utf8 -*-


cumle = raw_input("Cümle Giriniz: ")
kelimeler=cumle.split(" ")
geneltop=0

for i in kelimeler:
	toplam=0
	for j in i:
		if j in "aeıioöuüAEIİOÖUÜ":
			toplam+=1
	print i+ " : "+str(toplam)
	geneltop+=toplam

print "Genel Toplam: "+str(geneltop)

