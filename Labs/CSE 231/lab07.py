def process_file(process_file): # calls read_student(), writes output to file
    read_student(student_line)
    my_list = []
    for line in lines:
        my_list = my_list.append()
    return my_list

def read_student(student_line): # gets name, count the number of scores, calculates average of scores
    file_open = open('scores.txt','r')
    lines = file_open.readlines()
    junk_remover = lines.strip()
    item_split = lines.split()
    name = " "
    while True:
        for index in file_obj:
            if index not in range(1,10):
                name = name.append()
    count = 0 # counts the number of scores
    while True:
        for index in file_obj:
            if index >=0 or index<=10: # need to test each index value
                count += 1       
    list_sort = my_list.sort()
    reverse_list = list_sort[::-1]
    average_scores = sum(scores)/count # finds average of scores
    average_float = round(average_scores, 2) # reducing average to 2 decimal places
    return 
    
def main(): # prompts for file input, runs process function
    opened_file_bool = False
    while (not opened_file_bool):
        try:
            file_obj = open('scores.txt','r')
            opened_file_bool = True   # only executed after file opens
        except IOError:
            print("Bad file name, try again ")
            file_name_str = input("What file???") #reprompt, bad file
    else:
        return(file_obj)
    lines = file_obj.readlines()
    printfile(file_obj)
    printLines(lines)
    process_file('scores.txt','r') #calls the process function
main()
