def get_and_strip_number(s):
    index = s.find(' ')
    number = s[:index]
    number_int = int(number)
    text = s[index+1:]
    return number_int, text

def get_and_strip_word(s):
    index = s.find(' ')
    word = s[:index]
    text = s[index:]
    return word, text
    """Requires:
       -- string s has no leading spaces, and is either empty or
          consists of one or more words, each separated from the next by a single space
       Returns:
       -- first word of s, and
       -- the "rest" of s, i.e. what is left after stripping off the word and, if
          there is one, the space following the word"""
    # replace this comment and the next statement with your function body
    return '', ''
    
def pad_words(s, num_words, final_len):
    """Requires:
       -- final_len > len(s)
       -- string s consists of num_words words, each separated by a single space
       Returns:
       -- string r, containing the words in s evenly padded with spaces to make
          len(r) == final_len"""
    if num_words <= 1:      # best we can do is fill out the line with spaces
        return s + ((final_len - len(s))*' ')

    # there are at least 2 words, so at least one pigeon hole to fill (with spaces)
    num_pigeon_holes = num_words - 1                        # the buckets (pigeon holes) are between words
    num_pigeons = final_len - (len(s) - num_pigeon_holes)   # my pigeons are spaces
    pad_num = num_pigeons // num_pigeon_holes
    extra_num = num_pigeons % num_pigeon_holes              # number of holes that get an extra pigeon
    working_str = ''
    
    # take care of the first num_pigeon_holes - extra_num holes
    for i in range(num_pigeon_holes - extra_num):
        word, s = get_and_strip_word(s)
        working_str += word + (pad_num * ' ')   # insert pad_num spaces

    # take care of the last extra_num holes
    for i in range(extra_num):
        word, s = get_and_strip_word(s)
        working_str += word + ((pad_num + 1) * ' ')

    working_str += s
    return working_str

def main():
    """Main program for testing some text formatting functions."""
    file_name = input("Enter the name of the input file: ")
    file_obj = open(file_name, "r")

    print("Line length should be as long as the longest line to print, or longer.") 
    line_len = int(input("Enter the desired line length: "))
    print()

    for line in file_obj:
        line = line.strip()                   # strip the trailing '\n'
        n, words = get_and_strip_number(line)
        print(pad_words(words, n, line_len))

    file_obj.close()

    
          
