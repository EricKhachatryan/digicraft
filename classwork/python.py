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

"""
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



