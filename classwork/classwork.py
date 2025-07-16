"""
import random
goldenNum = random.randint(1,10)
while True: 
    num = int(input("input number : "))
    if goldenNum == num :
        print("tisht e")
        break
    else:
        print("sxal")

list = []
while True:
    print("___________MENU____________")
    answer = str(input("input : Add : View : Exit : "))
    if answer == "Add" :
        text = str(input("text : "))
        list.append(text)
    elif answer == "View" :
        print(list)
    elif answer == "Exit" :
        print("Exit")
        break;
    else:
        print("false argument")

"""


list = []
while True:
    print("___________MENU____________")
    answer = str(input("input : Add : View : Search : Delete : Update : Exit : "))
    if answer == "Add" :
        text = str(input("name : ")),int(input("number :"))
        list.append(text)
    elif answer == "View" :
        print(list)
    elif answer == "Search" :
        search = str(input("input name : "))
        for i,x in list:
            if i == search:
                print(i,x)
    elif answer == "Update" :
        search = str(input("input name : "))
        for i,x in list:
            if i == search:
                x = int(input("input new number : "))
                list[i,x]
    elif answer == "Exit" :
        print("Exit")
        break;
    else:
        print("false argument")



