
#print ("Hello World!\n")

#Exercise 1-1
#print("Day 1 - Python Print Function")
#print("The function is declared like this:")
#print("print('what to print')\n")

#Example 1
#print("Hello World!\nHello World!\nHello World!")
#print("Hello "+"Angela\n")

#Exercise 1-2
#print("Day 1 - String Manipulation")
#print('String Concatenation is done with the "+" sign.')
#print('e.g. print("Hello " + "world")')
#print("New lines can be created with a backslash and n.\n")

#Example 2
#print("Hello "+ input("What is your name? ")+"!\n")

#Exercise 1-3
#name_length = len(input("What is your name? "))
#print(name_length)

#Example 3
#name = "Jack"
#print(name)
#name = "Angela"
#print(name)

#Exercise 1-4
#a = input("Enter a value for a: ")
#b = input("Enter a value for b: ")
#change = b
#b = a
#a = change
#print("a: " + a)
#print("b: " + b)

#Day 1 Project
#Takes in city you grew up in, and pet name. Then combines them to create band name.
print("Welcome to the band name generator.")
city = input("What is the name of the city that you grew up in?\n")
pet = input("What is the name of your favorite pet?\n")
band_name = city + " " + pet
print("Your band name is: " + band_name)
