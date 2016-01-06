from Deque import *

def check(word):
  
  charDeque = Deque()
  
  for i in word:
    charDeque.addRear(i)

  stillEqual = True

  while charDeque.size() > 1 and stillEqual:
    front = charDeque.removeFront()
    back = charDeque.removeRear()
    if front != back:
      stillEqual = False
    
  return stillEqual


#kavak,radar,madam,pop,eniyimesebesemiyine(en iyi mese bese mi yine)
print check('eniyimesebesemiyine')
