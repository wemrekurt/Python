class Person:
	def getInfo(self):
		return "Person:getInfo"

	def printPerson(self):
		print(self.getInfo(),' ')

class Student(Person):
	def getInfo(self):
		return "Student:getInfo"

def main():
		p=Person()
		p.printPerson()
		s=Student()
		s.printPerson()

main()

