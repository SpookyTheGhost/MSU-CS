import string
def open_file():
    file_name_str = input("Please enter a file name: ")
    opened_file_bool = False
    while (not opened_file_bool):
        try:
            file_obj = open(file_name_str, 'r')
            opened_file_bool = True   # only executed after file opens
        except IOError:
            print("Bad file name, try again ")
            file_name_str = input("What file???") #reprompt, bad file
    else:
        return file_obj
file_open1 = '';file_open2 = ''
def print_index(file_open1):
    dictionary = {}
    count = 0
    for line in file_open1:
        word_list = line.split(' ')
        count+=1
        for item in word_list:
            punct_remove = item.strip(string.punctuation)
            lower = punct_remove.lower()
            if lower in dictionary:
                dictionary[lower].add(count)
            else:
                dictionary[lower] = set()
                dictionary[lower].add(count)
            print(dictionary)
    
##def compare_files(file_open1,file_open2):
##    pass
##def main():
##    file_open1 = open_file()
##    file_open2 = open_file()
##    index = print_index(file_open1,file_open2)
##    compare = compare_files()
##main()
##
