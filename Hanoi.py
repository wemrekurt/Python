from Stack import *

class Hanoi:
  def __init__(self,n):
    self.move = n
    self.tower = [0]
    [self.tower.append(Stack()) for a in range(1,4)] # 3 Stack kule olustur
    
    self.tofh()
      
  def tofh(self):
    #Kuleye diskleri yerlestir
    for i in range(self.move,0,-1): 
      self.tower[1].push(i)
    
    print 'K: Kaynak Kule, Y: Yardimci Kule, H: Hedef Kule'
    self.display()
    self.movement(self.move,1,2,3)

  def movement(self,n,a,b,c):
    if n > 0:
      self.movement(n-1,a,c,b)
      d = self.tower[a].pop()
      self.tower[c].push(d)
      self.display()
      self.movement(n-1,b,a,c)

  def display(self):
    print ' K |  Y  |  H '
    print '--------------'
    
    for i in range(self.move-1,-1,-1):
      try:
        source = self.tower[1].show()[i]
      except IndexError:
        source = " "
      
      try:
        helper = self.tower[2].show()[i]
      except IndexError:
        helper = " "

      try:
        target = self.tower[3].show()[i]
      except IndexError:
        target = " "
      
      print source,' | ', helper,' | ',target
   
    print '\n' 

    
tofhanoi = int(raw_input('Disk Sayisi Giriniz: '))
test = Hanoi(tofhanoi)

