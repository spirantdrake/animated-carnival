alphabet = {
    'a' : 1,
    'b' : 2,
    'c' : 3,
    'd' : 4,
    'e' : 5,
    'f' : 6,
    'g' : 7,
    'h' : 8,
    'i' : 9,
    'j' : 9,
    'k' : 10,
    'l' : 11,
    'm' : 12,
    'n' : 13,
    'o' : 14,
    'p' : 15,
    'q' : 16,
    'r' : 17,
    's' : 18,
    't' : 19,
    'u' : 20,
    'v' : 21,
    'w' : 22,
    'x' : 23,
    'y' : 24,
    'z' : 25
}


def key(k):
    
    matrix = [[],[],[],[],[]]
    number = 1
    count = 0

    for x in range(5):
        for y in range(5):
            if (count < len(k)):
                matrix[x].extend([alphabet[k[count]]])
            else:
                matrix[x].extend([number])
                number+=1
            count += 1

    print(matrix)
    print(k)


def Pre(P):
    print("Hello World!")


def __main__():
    k = input("Enter the key for your Playfair cipher: \n")
    key(k.lower())


__main__()