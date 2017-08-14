octpch1 = input ("Please enter an octpch pair: ")
octpch1_float = float(octpch1)
octpch2 = input ("Please enter an octpch pair: ")
octpch2_float = float(octpch2)
octpch3 = input ("Please enter an octpch pair: ")
octpch3_float = float(octpch3)
o1 = int(octpch1_float)
o1_float = float(o1)
o2 = int(octpch2_float)
o2_float = float(o2)
o3 = int(octpch3_float)
o3_float = float(o3)
m1 = (octpch1_float - o1_float)*10
m2 = (octpch2_float - o2_float)*10
m3 = (octpch3_float - o3_float)*10

Hertz1 = 440*2**((o1-4)+(m1-9)/12)
Hertz2 = 440*2**((o2-4)+(m2-9)/12)
Hertz3 = 440*2**((o3-4)+(m3-9)/12)

if octpch1_float<0:
    print ("Please run the program again and enter a non-negative value")
elif m1<1:
    print ("invalid input")
elif m1>12:
    print ("Please run the program again and enter a pitch value less than 12")
elif Hertz1<32:
    print ("Hertz is out of range")
elif Hertz1>32676:
    print ("Hertz is out of range")
else:
    print ('The Hertz value of the octpch value is: ', Hertz1)
if octpch2_float<0:
    print ("Please run the program again and enter a non-negative value")
elif m2<1:
    print ("invalid input")
elif m2>12:
    print ("Please run the program again and enter a pitch value less than 12")
elif Hertz2<32:
     print ("Hertz is out of range")
elif Hertz2>32676:
     print ("Hertz is out of range")
else:
    print ('The Hertz value of the octpch value is: ', Hertz2)
if octpch3_float<0:
    print ("Please run the program again and enter a non-negative value")
elif m3<1:
    print ("invalid input")
elif m3>12:
    print ("Please run the program again and enter a pitch value less than 12")
elif Hertz3<32:
    print ("Hertz is out of range")
elif Hertz3>32676:
    print ("Hertz is out of range")
else:
    print ('The Hertz value of the octpch value is: ', Hertz3)



  




