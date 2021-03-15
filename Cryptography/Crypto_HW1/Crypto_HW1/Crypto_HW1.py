def function1():
    print("Function 1\n")
    selection = input("Do you wish to input a string or list of characters?\n")
    if (selection == "string"):
        word = input("Enter a string:\n")
        length = len(word)
        list_of_characters = []
        for x in range(length):
            list_of_characters.append(word[x])
        print(list_of_characters)
    elif (selection == "list of characters"):
        list_of_characters = input("Enter elements of a list separated by ,\n")
        temp = list_of_characters.split(", ")
        word = ""
        for x in temp:
            word += x
        print(word)


def function2():
    print("Function 2\n")
    selection = input("Do you wish to input a list of characters or ASCII?\n")
    if (selection == "list of characters"):
        list_of_characters = input("Enter elements of a list separated by ,\n")
        temp_list = list_of_characters.split(", ")
        ascii_list = []
        for x in temp_list:
            ascii_list.append(ord(x))
        print(ascii_list)
    elif (selection == "ASCII"):
        ascii_list = input("Enter elements as ASCII characters separated by ,\n")
        temp_list = ascii_list.split(", ")
        list_of_characters = []
        for x in temp_list:
            list_of_characters.append(chr(int(x)))
        print(list_of_characters)


def function3():
    print("Function 3\n")
    selection = input("Do you wish to input ASCII or Binary?\n")
    if (selection == "ASCII"):
        ascii_list = input("Enter elements as ASCII characters separated by ,\n")
        temp_list = ascii_list.split(", ")
        binary_list = []
        for x in temp_list:
            binary_list.append(f'{int(x):08b}')
        print(binary_list)
    elif (selection == "Binary"):
        binary_list = input("Enter elements as Binary numbers separated by ,\n")
        temp_list = binary_list.split(", ")
        ascii_list = []
        for x in temp_list:
            ascii_list.append(int(x, 2))
        print(ascii_list)


# function1()
# function2()
# function3()

