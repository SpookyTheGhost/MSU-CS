# zhangke8
# Project 07
# 3/11/2013
import random, string
file_name_str = '';word_str = '';line_str = '' # without this, program gives an 'undefined' error
def open_read_file(file_name_str):
    file_name = input("Please enter the file name: ")
    opened_file = False
    while (not opened_file):
        try:
            file_object1 = open(file_name,'r')
            opened_file = True # executed only after file opens   
        except IOError:
            file_name = input("What file?: ") # reprompting user for legal file name
    else:
        return file_object1
def write_file():
    file_name = input("What file would you like to write to?: ")
    opened_file = False
    while (not opened_file):
        try:
            file_object2 = open(file_name,'w')
            opened_file = True # executed only after file opens   
        except IOError:
            file_name = input("What file?: ") # reprompting user for legal file name
    else:
        return file_object2
def word_scramble(word_str):
    word_list = list(word_str) # turns string to list format
    while not(len(word_str) <= 3 or word_str.isdigit()):
        word_result = []
        for character in word_list:
            if character in string.punctuation:
                punctuation = word_str.find(character)
                word_result = word_str[punctuation+2:len(word_str)-2]
                wordlist = list(word_result)
                random.shuffle(wordlist)#1
                string1 = ''.join(wordlist) # joins the list back to string
                word1 = word_str[:punctuation+2]+string1+word_str[(len(word_str)-2):] # concatenates word back together
                return word1
            if character not in string.punctuation:
                word_result2 = word_str[1:len(word_str)-1]
                wordlist2 = list(word_result2)
                random.shuffle(wordlist2)#2
                string2 = ''.join(wordlist2) # joins the list back to string
                word2 = word_str[0]+string2+word_str[(len(word_str)-1):] # concatenates word back together
            return word2
    else:
        list_to_string = ''.join(word_list) # Waste of time to scramble words of length 3 or shorter, don't scramble numbers
        return list_to_string
def line_scramble(line_str):
    each_line = ''
    for line in line_str:
        single_word = line.split(' ')
        for word in single_word:
            word_str = str(word)
            scramble = word_scramble(word_str) # calls scramble function
            string = str(scramble)
            if word == '\n':
               each_line = ''
            else:
                each_line = each_line+string+' '
    return each_line
def main():
    file_input = open_read_file(file_name_str) # opens the file
    scramble = line_scramble(file_input)
    file_output = write_file()
    file_output.write(scramble)
    file_output.write('\n')
    file_input.close() # closes file to prevent damage
    file_output.close() # closes file to prevent damage
main() # calls the main function
