"""
print("Hello World!")
age = 21
pi = 3.14
name = "Eric"
isConected = True
print(age, pi, name, isConected)
name2 = input("Input Name : ")

#print(name2)

age = int(input("Age : "))
if age > 18:
    print(age)
elif age < 10:
    print ("10-")
else:
    print("else")

for i in range(10):
    print("Value", i)
for i in "Hello":
    print("Value", i)
x = 0
while x < 10:
   print("x ", x)
   x += 1 

#Function

def sayHallo(name="AAA"):
    print ("Hello", name)

sayHallo("Eric")
sayHallo()

def Foo(sc):
    if score < 50 :
         print (name,"fail")
    else:
         print (name,score)
foo = 0
user = int(input("Input "))
for i in range(user):
    name = input("name ")
    score = int(input("score "))
    foo += score
    Foo(score)
print(foo/user)

#LIST _____________________
arr = ["1", "2", "3", 5]
arr.append("4")
arr[3] = False
print(arr[3])
for x in arr:
    print(x)

print(len(arr)) #listi argumentneri qanak/ size

print (44 in arr) # stugel 44 ka arrum te che


#Tuple________________________
mytuple = [("Eric",21),("x",11)]
cords = (1,20)

print(mytuple)
print(mytuple[1])
x = mytuple[0]
print(x[0])

x,y = cords
for x, y in mytuple:
    print(x)
    print(y)


#Set_______________________

arr = {2 , 4 , 6}
arr.add(8)
print(arr)

x = {1,2,3}
y = {3,4,5}
print(y | x)
print(y & x)
print(y - x)


#Map_________________________

person = { "name" : "Eric","age" : 23}
print(person["name"])
print(person["age"])
person["city"] = "Vanadzor"
print(person)

for key , value in person.items():
    print(key)
    print(value)

#Python_OOP____________________________________________________________

class Person:
    def __init__(self,name,age):
        self.__name = name
        self.age = age
    def sayHello(self):
        print(f"Hello {self.__name}")

class Student(Person):
    def __init__(self, name, age, grade):
        super().__init__(name,age)
        self.__name = name
        self._age = age
        self.grade = grade
    def sayHello(self):
        print(f"Hello {self._age}")

st = Student("Eric", 21, 100)
st.sayHello()




class Worker:
    def __init__(self,ID,name,age):
        self._ID = ID
        self._name = name
        self._age = age
    def setID(self,ID):
      _ID = ID
    def setName(self,name):
      _name = name
    def setAge(self,age):
      _age = age
   
    def getID(self):
        return self._ID
    def getName(self):
        return self._name
    def getAge(self):
        return self._age

class Employee(Worker):
    def __init__(self,ID,name,age,salory):
        super().__init__(ID,name,age)
        self.salory = salory

    def setSalory(self,salory):
        self.salory = salory
    def getSalory(self):
        return self.salory

work = Employee(100,"Eric",23,150000)

#python Polimorphism______________________________________


class Animal:
    def sound(self):
        print("animal sound")

class Dog:
    def sound(self):
        print("dog sound")

animals = [Animal(), Dog()]
for animal in animals:
    animal.sound()

#Run time Polymorphism_____________________________
class Animal:
    def sound(self):
        print("animal sound")

class Dog(Animal):
    def sound(self):
        print("dog sound")

class Cat(Animal):
    def sound(self):
        print("cat sound")

def makeSound(animal: Animal):
        animal.sound()

makeSound(Animal())
makeSound(Dog())
makeSound(Cat())


#bu`ilt-in Polymorphism_______________________________

print(len([1,2,3,4]))
print(len(["Hello"]))

print ("a" + "b")
print(8 + 10)
print("8" + str(10))


class Shape:
    def area(self):
        print("area")

class Circle(Shape):
    def area(self):
        print("CIRCLE")

class Square(Shape):
    def area(self):
        print("SQUARE")

class Rectangle(Shape):
    def area(self):
        print("RECTANGLE")

def CalculateArea(shape: Shape):
    shape.area()

CalculateArea(Shape())
CalculateArea(Circle())
CalculateArea(Square())
CalculateArea(Rectangle())

class Shape:
    def area(self):
        print("area")

class Circle(Shape):
    def area(self):
        print("CIRCLE")

class Square(Shape):
    def area(self):
        print("SQUARE")

class Rectangle(Shape):
    def area(self):
        print("RECTANGLE")

Mat = [Shape(),Circle(),Square(),Rectangle()]
for mat in Mat:
    mat.area()

def calculator(num1,num2,operator):
    if operator == "+" :
        return num1 + num2
    elif operator == "-" :
        return num1 - num2
    elif operator == "*" :
        return num1 * num2
    elif operator == "/" :
        return num1 / num2
    else :
        print("sxal argument")

num1 = int(input("num 1 : "))
num2 = int(input("num 1 : "))
operator = str(input("num 1 : "))

print(calculator(num1,num2,operator))

"""




















