"""
def max (a,b,c):
    if a > b:
        if a > c:
            return a
        else:
            return c
    if b > a:
       if b > c:
           return b
       else:
           return c


print(max(15,250,9))

def foo(numbers):
    num = 0
    for x in numbers: 
        if x % 2 == 0:
            num += 1
    return num

print(foo([1,2,3,4,5,10,15,26,40,30]))


def foo(numbers):
    result = []
    for num in numbers:
        if num > 10:
            result.append(num)
    return result        
    
print(foo([1,50,3,50,90,70,90,1]))



def foo(numbers):
    return set(numbers)
print(foo([1,1,2,2,3,3,4,4,5,5,6,7,8,9,10]))
    

"""
numbers = [1, 2, 3, 4]
result = list(map(lambda x: x * 2, numbers))
print(result)





























