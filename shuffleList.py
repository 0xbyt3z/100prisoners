import random

l = [x for x in range(0, 100)]
l.reverse()
random.shuffle(l)

with open("list.txt", "w") as file:
    for i in l:
        s = f"{i}\n"
        file.write(s)

with open("ref.txt", "w") as file:
    counter = 0
    for i in l:
        # prisoner : box
        s = f"{counter} : {i}\n"
        counter += 1
        file.write(s)
