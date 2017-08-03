# zhangke8
# Project 04
# 2/4/2013
while True:
        check = 0
        check1 = 0
        check2 = 0
        Match = 0
        Mismatch = 0
        s1_count = 0
        s2_count = 0
        ss1 = ""
        ss2 = ""
        s1 = input("String 1: ")
        s2 = input("String 2: ")
        string1_lower = s1.lower()
        string1_upper = s1.upper()
        string2_lower = s2.lower()
        string2_upper = s2.upper()
        b = len(string1_lower)
        c = len(string2_lower)
        print("Command menu: ")
        print("""   'a' (add)\n
   'd' (delete)\n
   's' (score)\n
   'q' (quit) """)
        x = input("Please choose a command: ")
        if x == 'q':
            print("Quiting program")
            break
        else:
                if x == 'a':
                        y = input("Which string do you wish to change? (1 or 2): ") # prompts user for string to change
                        if y == '1':
                                index_str1 = input("Add before what index?: ") # prompts user to choose index
                                index_str1_int = int(index_str1)
                                if index_str1_int < 0 or index_str1_int > b:
                                        print ("Index is out of range") #can't calculate, index is out of range    
                                else:
                                        print(string1_lower[:index_str1_int] + "-" + string1_lower[index_str1_int:])
                        if y == '2':
                                index_str2 = input("Add before what index?: ") # prompts user to choose index
                                index_str2_int = int(index_str2)
                                if index_str2_int < 0 or index_str2_int > c:
                                        print ("Index is out of range") #can't calculate, index is out of range 
                                else:
                                        print(string2_lower[:index_str2_int] + "-" + string2_lower[index_str2_int:])
                        if y != '1' and y != '2':
                                print ("invalid string choice")                               
                if x == 'd':                       
                        while check1 < b:
                                if string1_lower[check] == "-":
                                        s1_count +=1
                                check1 += 1
                        while check2 < c:
                                if string2_lower[check] == "-":
                                        s2_count += 1
                                check2 +=1
                        if s1_count == 0 and s2_count == 0:
                                print("Unable to delete character in either string")                                 
                        z = input("Which string do you wish to change? (1 or 2): ") # prompts user for string to change
                        if z == '1' and s1_count == 0:
                                print("No indel exists in string 1")
                        if z  == '2' and s2_count == 0:
                                print("No indel exists in string 2")            
                        if z == '1' and s1_count != 0:
                                delete_str1 = input("Delete what index?: ") # prompts user to choose index
                                delete_str1_int = int(delete_str1)
                                if delete_str1_int < 0 or delete_str1_int > b:
                                        print("Index is out of range") #can't calculate, index is out of range
                                else:
                                        if string1_lower[delete_str1_int] == "-":
                                                delete1 = (string1_lower[:delete_str1_int] + string1_lower[delete_str1_int+1:])
                                                print(delete1)                                
                                        else:
                                                print("Unable to delete character in string 1")                               
                        if z == '2' and s2_count != 0:
                                delete_str2 = input("Delete what index?: ") # prompts user to choose index
                                delete_str2_int = int(delete_str2)
                                if  delete_str2_int < 0 or delete_str2_int > c:
                                        print("Index is out of range") #can't calculate, index is out of range
                                else:
                                        if string2_lower[delete_str2_int] == "-":
                                                delete2 = (string2_lower[:delete_str2_int] + string2_lower[delete_str2_int+1:])
                                                print(delete2)                                
                                        else:
                                                print("Unable to delete character in string 1")                                   
                        if z != '1' and z != '2':
                                print ("invalid string choice")                                
                if x == 's':
                        while (b < c):
                                string1_lower = string1_lower + "-"
                                string1_upper = string1_upper + "-"
                                b += 1
                        while (c < b):
                                string2_lower = string2_lower + "-"
                                string2_upper = string2_upper + "-"
                                c += 1        
                        while (b > check):
                                if string1_lower[check] == string2_lower[check]:
                                        Match += 1
                                        ss1 = ss1 + string1_lower[check]
                                        ss2 = ss2 + string2_lower[check]
                                else:
                                        Mismatch += 1
                                        ss1 = ss1 + string1_upper[check]
                                        ss2 = ss2 + string2_upper[check]
                                check += 1
                        print("Matches: ", Match, "Mismatches: ",Mismatch)
                        print("String 1: ", ss1, "String 2: ", ss2)                  
