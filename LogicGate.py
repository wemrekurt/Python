class LogicGate:
	def __init__(self,n):
		self.label=n
		self.output=None
	
	def getLabel(self):
		return self.label
	
	def getOutput(self):
		self.output=self.performGateLogic()
		return self.output


class BinaryGate(LogicGate):
	def __init__(self,n):
		LogicGate.__init__(self,n)
		self.pinA=None
		self.pinB=None
	
	
	def getPinA(self):
		return input(self.getLabel()+" PinA: ")


	def getPinB(self):
		return input(self.getLabel()+" PinB: ")

class UnaryGate(LogicGate):
	def __init__(self,n):
		LogicGate.__init__(self,n)
		self.pin=None
	def getPin(self):
		return input(self.getLabel()+" Pin: ")

class AndGate(BinaryGate):
	def __init(self,n):
		BinaryGate.__init__(self,n)

	def performGateLogic(self):
		a = self.getPinA()
		b = self.getPinB()

		if a==1 and b==1:
			return 1
		else:
			return 0

class OrGate(BinaryGate):
	def __init__(self,n):
		BinaryGate.__init__(self,n)
	
	def performGateLogic(self):
		a = self.getPinA()
		b = self.getPinA()

		if a==1 or b==1:
			return 1
		else:
			return 0

class XOrGate(BinaryGate):
	def __init__(self,n):
		BinaryGate.__init__(self,n)

	def performGateLogic(self):
		a = self.getPinA()
		b = self.getPinB()

		if a==b:
			return 0
		else:
			return 1

class NotGate(UnaryGate):
	def __init__(self,n):
		UnaryGate.__init__(self,n)

	def performGateLogic(self):
		a=self.getPin()
		
		if a==0:
			return 1
		else:
			return 0




#g=NotGate("g")
#print g.getOutput()

g1=AndGate("G1")
print g1.getOutput()

g2=OrGate("G2")
print g2.getOutput()




