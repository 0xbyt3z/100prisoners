import random

# create a sorted list from 0 -99
l = [x for x in range(0, 100)]

#  reversing the list may increase the randomness
l.reverse()

#shuffles the list
random.shuffle(l)

# file for the c++ program
with open("list.txt", "w") as file:
    for i in l:
        s = f"{i}\n"
        file.write(s)

# file to map prisoners and boxes to 0th index
with open("ref.txt", "w") as file:
    counter = 0
    for i in l:
        # prisoner : box
        s = f"{counter} : {i}\n"
        counter += 1
        file.write(s)
