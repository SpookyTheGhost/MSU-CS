# zhangke8, kohleyal
# Lab exercise 3
# 1/24/2013


#prompt for input
num = input ("Please input a number ('quit' to end): ")
print ("Number is: ",num)
if num == "quit" "QUIT" "Quit":
    print('Thank you for playing')
    
if num.isdigit():
    print ("Please enter an integer: ")
    
else:
    print ("Please enter a value: ")
num_int = int(num)
print('Number is:', num_int)
print('Sequence is:', num_int, end=" ")
count = 0
large= int(num)
while True:
    if num_int%2==0: # This tests if the number is even
        num_int = int(num_int/2) 
        print(num_int, end=",")
        count += 1
        if large<num_int:
                large = num_int
    if num_int == 1:
        break
    elif num_int%2==1: # This tests if the number is odd
        num_int = int((num_int*3)+1) 
        print(num_int, end=",")
        count += 1
        if large<num_int:
                large = num_int
        
print (end="\n")
print("Length is: ", count)
print ("Largest is: ", large)

    
    
print('Thank you for playing')


