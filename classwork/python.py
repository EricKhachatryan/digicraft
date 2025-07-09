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

"""



