from Queue import *

def hotPotato(namelist,N):

  simqueue = Queue()
  for name in namelist:
    simqueue.enqueue(name)

  while simqueue.size() > 1:
    for i in range(N):
      simqueue.enqueue(simqueue.dequeue()) #N'e kadar kuyruktan cikar ve kuyruga sok

    simqueue.dequeue()

  return simqueue.dequeue()

cocuklar =['Ali','Veli','Can','Ayse','Fatma','Fadime','Ibrahim']
kazanan = hotPotato(cocuklar,2)
print "Kazanan: ",kazanan
