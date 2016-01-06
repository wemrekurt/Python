def gcd(x,y):
  while x%y != 0:
    newx = y
    y = x % y
    x = newx
  
  return y

print gcd(121,33)
