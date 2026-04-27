counter = 100;
selected = []
while counter <= 150:
    if (counter%5==0) and (counter%7==0):
        counter+=1
        continue
    selected.append(counter)
    counter+=1
print(selected)