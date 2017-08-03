print ("Guess a value for Slayer so that the following equation is true: \
SLAYER + SLAYER + SLAYER = LAYERS.\
 Each letter in SLAYER stands for a digit")
num = float(input("please enter a value for SLAYER: "))
a =(num%10)
b = (num//10)%10
c = (num//100)%10
d = (num//1000)%10
e = (num//10000)%10
f = (num//100000)%10
SLAYER= 100000*f+10000*e+1000*d+100*c+10*b+a
LAYERS = 100000*e+10000*d+1000*c+100*b+10*a+f