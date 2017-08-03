# zhangke8
# Project 08
# 3/18/2013
import string
fd = '';
c_dict = {};
prefix = '' # without this, program gives an 'undefined' error
def fill_completions(c_dict,fd):
    for line in fd:
        each_line = line.split(' ')
        for word in each_line:
            if not (len(word)<1) or word.isalpha == True:
                cleanup = word.strip()
                junk_remover = cleanup.strip('\n')
                punct_remove = junk_remover.strip(string.punctuation)
                lower_case = punct_remove.lower()
                for k in lower_case:
                    key = (lower_case.find(k),k)
                    if key in c_dict:
                        c_dict[key].add(lower_case)
                    else:
                        c_dict[key] = set()
                        c_dict[key].add(lower_case)
            else:
                continue
def find_completions(prefix, c_dict):
    keys = list(enumerate(prefix))
    comple_set = c_dict[keys[0]]
    for k in keys:
        comple_set = comple_set & c_dict[k]
    return comple_set
def main():
    fd = open('ap_docs.txt','r')
    fill_completions(c_dict,fd)
    prefix = input("Please enter a prefix or '#' to quit: ")
    while (prefix != '#'):
        word_complete = find_completions(prefix, c_dict)
        if prefix == '#':
            break
        if word_complete != {}:
            for j in word_complete:
                print(j) # prints each word that completes the prompted prefix
            prefix = input("Please enter a prefix or '#' to quit: ")
        else:
            print("no completions found")
            prefix = input("Please enter a prefix or '#' to quit: ")
    fd.close() # closes file to prevent damage
main() # calls the main function
