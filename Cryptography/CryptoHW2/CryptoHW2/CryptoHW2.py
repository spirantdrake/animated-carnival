from itertools import chain
import math


def key(k):
    # replaces the j to i so there is only one of the two, creates a temp list and creates an english alphabet string
    temp_key = k.replace("j", "i")
    temp = []
    alphabet = "abcdefghiklmnopqrstuvwxyz"

    #splits the list of characters
    for x in chain(temp_key, alphabet):
        if not x in temp: temp.append(x)

    #creates a matrix using the list slices
    KM = [temp[y:y+5] for y in range(0, 25, 5)]
    #print(KM)
    return(KM)


def Pre(P):
    #variables for manipulating data and the strings
    PL = []
    y = 0 
    z = 1
    word_length = int(math.ceil(len(P)/2))
    repitition = False

    # loops through the given plaintext and places the letters into a list 2 at a time
    for x in range(word_length):
        if(z < len(P)):
            if(P[y] == P[z]): #checks to see if two side by side letters are the same and inserts an x if they are
                PL.append(P[y]+"x")
                y -= 1
                z -= 1
                repitition = True
            else: #adds both characters into the list
                PL.append(P[y]+P[z])
        else: #if the list is an odd number it adds an x as the last character to make it even
            PL.append(P[y]+"x")
        y += 2
        z += 2
    #edge case rule for catching even numbered plaintext that contain repititive letters
    if (len(P)%2 == 0 and repitition == True):
        PL.append(P[y] + "x")
    #print(PL)
    return(PL)


#This function finds the index of a value in a multidimensional list KM
def index(KM, value):
    index_x = 0
    index_y = 0

    for x in range(5):
        for y in range(5):
            if (KM[x][y] == value):
                index_x = x
                index_y = y
                break

    return (index_x, index_y)


def Enc(KM, PL):
    location = index(KM, 'o')
    
    print(f"The index of the value is [{location}].")


def __main__():
    k = input("Enter the key for your Playfair cipher: \n")
    KM =key(k.lower())
    P = input("Enter your plaingtext you wish to encode: \n")
    PL = Pre(P.lower())
    Enc(KM, PL)

__main__()