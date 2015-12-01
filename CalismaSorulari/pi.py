# -*- coding: utf8 -*-
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
  		
pim=raw_input("Pi hesabı adım sayısı girin: ")
pim=int(pim) 
print pi(pim)

