for x in range(2,10):
    for y in range(2,10):
        if (x%y==0) and (x!=y):
            continue
        print(x)