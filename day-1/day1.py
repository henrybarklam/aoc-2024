
list1, list2 = [], []

with open('day1_1_input.txt') as file:
    for line in file:
        split_line = line.split()
        list1.append(split_line[0])
        list2.append(split_line[1])

list1.sort()
list2.sort()

total = 0

for i in range(len(list1)):
    total += abs(int(list1[i]) - int(list2[i]))

print(total)