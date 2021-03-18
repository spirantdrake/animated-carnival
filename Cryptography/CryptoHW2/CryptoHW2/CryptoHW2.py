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


#Takes in PL and splits the two characters into separate ones and returns it
def string_split(PL, value, placement):
    word = PL[value]
    a = word[placement]
    return (a)


#This function takes in a 2d list KM and a 1d list PL and then encrypts the PL using the KM list then returning the CT
def Enc(KM, PL):
    #variables for workflow
    CT = ""
    index1_x = 0
    index1_y = 0
    index2_x = 0
    index2_y = 0
    #print(f"KM = {KM}")
    #print(f"PL = {PL}")

    #loop to iterate through values of PL
    for x in range(len(PL)):
        #Calls string_split function to separate PL values into two separate strings
        first = string_split(PL, x, 0)
        second = string_split(PL, x, 1)
        #uses the values from the splits and finds their index location in list KM
        location1 = index(KM, first)
        location2 = index(KM, second)
        #through control flow and logical operators, the loop then encrypts the characters following the method of Playfair cipher encryption.
        if (location1[1] == location2[1]):
            if (location1[0] == 5):
                index1_x = 0
            elif (location2[0] == 5):
                index1_x = 0
            else:
                index1_x = location1[0] + 1
                index2_x = location2[0] + 1
            index1_y = location1[1]
            index2_y = location2[1]
        elif (location1[0] == location2[0]):
            index1_y = location1[1]
            index2_y = location2[1]
            if (location1[0] == 5 or location2[0] == 5):
                index1_x = 0
                index2_x = 0
            else:
                index1_x = location1[0] + 1
                index2_x = location1[0] + 1
        elif(first+second == "xx"):
            index1_x = location1[0]
            index1_y = location1[1]
            index2_x = location2[0]
            index2_y = location2[1]
        else:
            index1_x = location1[0]
            index1_y = location2[1]
            index2_x = location2[0]
            index2_y = location1[1]
        CT += str(KM[index1_x][index1_y]) + str(KM[index2_x][index2_y])
    return(CT)

        
def __main__():
    k = input("Enter the key for your Playfair cipher: \n")
    KM =key(k.lower())
    P = input("Enter your plaintext you wish to encode: \n")
    PL = Pre(P.lower())
    Encrypted_CT = Enc(KM, PL)
    CT = input("Enter the Ciphertext that you would like to decrypt. \n")

__main__()