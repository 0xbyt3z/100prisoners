import random

l = [x for x in range(1, 101)]

random.shuffle(l)

with open("list.txt", "w") as file:
    for i in l:
        s = f"{i}\n"
        file.write(s)
