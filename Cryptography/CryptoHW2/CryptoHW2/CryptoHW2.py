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
    print(KM)


def Pre(P):
    print("Hello World!")


def __main__():
    k = input("Enter the key for your Playfair cipher: \n")
    key(k.lower())


__main__()