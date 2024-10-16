with open("map.txt", "r") as fh:

    text = fh.read().splitlines()

    i=0
    for line in text:
        text[i] = line.replace("#", "1").replace("*", "0")
        text[i] = int(text[i],2)
        i += 1
    t=[]
    idx = 0
    while idx < len(text):
        t.append(f'0x{text[idx]:02x}{text[idx+1]:02x}')
        idx += 2

    idx = 0
    for i in t:
        print(f'm.bitmap[{idx}] = {i};')
        idx += 1