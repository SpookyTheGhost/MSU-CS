x = input ("please enter an integer: ")
x_int = int(x)

if x_int == 0:
    print ("your integer is 0")
elif x_int <0:
    print ("invalid: your integer is negative")
else:
    resultstring = ''
    while True:
        a = x_int/2
        b = x_int//2
        c = x_int%2
        d = c%10
        e = str(c)
        if a != 0 and c == 0 or c == 1:
           x_int = b
           
           resultstring += e  
        else:
            if a == 0:
                break
resultstring = resultstring[::-1]
print (resultstring)
count = 0
total = 0
for digit in resultstring:
    if digit == '1':
        total = total + 2**count
        count +=1
    else:
        digit = digit
        count += 1

print (total)









            

