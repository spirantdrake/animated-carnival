from itertools import chain



def key(k):
    # replaces the j to i so there is only one of the two, creates a temp list and creates an english alphabet string
    temp_key = k.replace("j", "i")
    temp = []
    alphabet = "abcdefghijklmnopqrstuvwxyz"

    #splits the list of characters
    for x in chain(temp_key, alphabet):
        if not x in temp: temp.append(x)

    #creates a matrix using the list slices
    KM = [temp[y:y+5] for y in range(0, 25, 5)]
    #print(KM)
    return(KM)


def Pre(P):
    #P.split()
    PL = []
    y = 0 
    z = 1
    for x in range(len(P)):
        if(y == 0):
            PL.append(P[y])
        elif(P[y] != P[y-1]):
            PL.append(P[y])
        else:
            PL.append("x")
            x -= 1
        y += 1
    print(PL)


def __main__():
    #k = input("Enter the key for your Playfair cipher: \n")
    #key(k.lower())
    P = input("Enter your plaingtext you wish to encode: \n")
    Pre(P.lower())


__main__()