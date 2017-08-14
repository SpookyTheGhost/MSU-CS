import random 
import cardsBasic
def card_print():
    print(playcard_hand1)
    print(playcard_hand2)
    return 
my_deck = cardsBasic.Deck()
print(my_deck)

my_deck.shuffle()
hand1_list = []
hand2_list = []
for item in range(10):
    hand1_list.append(my_deck.deal())
    hand2_list.append(my_deck.deal())
                      
    
print (hand1_list)
while len(hand1_list) >0 and  len(hand2_list) > 0: 
    stop = input('press N to quit: ')
    if stop == 'N' or stop== 'n':
        break
        
    playcard_hand1 = hand1_list.pop(0)
    playcard_hand2 = hand2_list.pop(0)

    card_print()
    
    if playcard_hand1.equal_rank(playcard_hand2):
        print(playcard_hand1, playcard_hand2, ' are equal')
        tie_list1 = []
        tie_list2 = []
        tie_list1.append(playcard_hand1)
        tie_list2.append(playcard_hand2)


        tie_list1.append(hand1_list.pop(0))
        tie_list2.append(hand1_list.pop(0))
        tie_list1.append(hand1_list.pop(0))
        tie_list2.append(hand2_list.pop(0))
        value_test1 = tie_list1.pop()
        value_test2 = tie_list2.pop()
        # need to take this and make a while loop for the tie if it ties again. 
        print(tie_list1, tie_list2)
        break 
    elif playcard_hand1.get_rank() > playcard_hand2.get_rank() :
        print('Player 1 is higher')
        hand1_list.append(playcard_hand1)
        hand1_list.append(playcard_hand2)
    else:
        print('player 2 is higher')
        hand2_list.append(playcard_hand1)
        hand2_list.append(playcard_hand2)

if len(hand1_list) == 0:
    print('Player Two wins')
else:
    print('Player One wins.')

def add_card_toList():
    playcard_hand1 = hand1_list.pop(0)
    playcard_hand2 = hand2_list.pop(0)
    return


##def main():
##    stop = input("Enter 'N' or 'n' to quit, enter to continue: ")
##    while True:
##        if stop != 'n' or stop != 'N':
##            continue
##            stop = input("Enter 'N' or 'n' to quit, enter to continue: ")
##
##        else:
##        
##            break
##    print('quit')
##
##
##main()
