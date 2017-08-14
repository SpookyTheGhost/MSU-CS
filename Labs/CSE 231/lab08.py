def height():
    triangle_height = input("Please enter a height: ")
    while not triangle_height.isdigit() or int(triangle_height) <= 0:
        print("Please enter an integer, please try again")
        triangle_height = input("Please enter a height: ")
        continue
    triangle_height_int = int(triangle_height)
    return  triangle_height_int

old_row = [1,1]
def make_new_row(old_row):
    if old_row == []:
        return[1]
    if old_row == [1]:
        return [1,1]
    newlist = [1]
    for i in range(len(old_row)):
        if (i+1) >= len(old_row):
            newlist.append(1)
            break
        else:
            newlist.append(old_row[i]+old_row[i+1])#
    return newlist

def main():
    triangle_height = height()
    original = [1]
    master_list = [[1]]
    for row in range(triangle_height-1):
        new_row = make_new_row(original)#
        original = new_row
        master_list.append(new_row)
    for k in range(len(master_list)):
        item = master_list[k]
        print(item)
main()
