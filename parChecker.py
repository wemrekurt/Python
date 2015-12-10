from Stack import *

def parChecker(symbolString):
	s	= Stack()
	balanced = True
	index =0

	while index < len(symbolString) and balanced:
		symbol = symbolString[index]
		if symbol in "([{":
			s.push(symbol)
		else:
			if s.isEmpty():
				balanced=False
			else:
				top = s.pop()
				if not matches(top,symbol):
					balanced=False

		index=index+1

	if balanced and s.isEmpty():
		return True
	else:
		return s.size()

def matches(open,close):
	opens	= "([{"
	closers=")]}"
	return opens.index(open)==closers.index(close)





x= parChecker('([{})')

if x==True:
	print "Duzenli parantez"
else:
	if x>0:
		print "Acilmis ancak kapanmamis "+str(x)+" parantez var"
	else:
		print "Kapanmis ancak acilmamis parantez var"
