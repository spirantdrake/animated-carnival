#Example 1
#print("Welcome to the rollercoaster!")
#height = int(input("What is your height in cm? "))

#if height >= 120:
#    print("You can ride the rollercoaster!")
#    age = int(input("What is your age? "))
#    if age < 12:
#        print("Please pay $5.")
#    elif age <= 18:
#        print("Please pay $7. ")
#    else:
#        print("Please pay $12. ")
#else:
#    print("Sorry, you have to grow taller before you can ride.")

#Exercise 3-1
#Odd or even number
#number = int(input("Which number do you want to check? "))
#if (number % 2) == 0:
#    print("This is an even number.")
#else:
#    print("This is an odd number.")

#Exercise 3-2
#height = float(input("Enter your height in m: "))
#weight = float(input("Enter your weight in kg: "))
#bmi = round(weight / (height ** 2))

#if bmi < 18.5:
#    print(f"Your bmi is {bmi}, you are underweight.")
#elif bmi < 25:
#    print(f"Your bmi is {bmi}, you have a normal weight.")
#elif bmi < 30:
#    print(f"Your bmi is {bmi}, you are overweight.")
#elif bmi < 35:
#    print(f"Your bmi is {bmi}, you are obese.")
#else:
#    print(f"Your bmi is {bmi}, you are clinically obese.")

#Exercise 3-3
#year = int(input("Which year do you want to check? "))

#if year % 400 == 0:
#    print("Leap year")
#elif year % 4 == 0 and year % 100 != 0:
#    print("Leap year")
#else:
#    print("Not Leap year")

#Exercise 3-4
#print("Welcome to Python Pizza Deliveries!")
#size = input("What size pizza do you want? S, M, or L ")
#add_pepperoni = input("Do you want pepperoni? Y or N ")
#extra_cheese = input("Do you want extra cheese? Y or N ")

#price = 0

#if extra_cheese == "Y":
#    price += 1
#if size == "S":
#    price += 15
#    if add_pepperoni == "Y":
#        price += 2
#elif size == "M":
#    price += 20
#    if add_pepperoni == "Y":
#        price += 3
#elif size == "L":
#    price += 25
#    if add_pepperoni == "Y":
#        price += 3
#print(f"Your final bill is: ${price}.")

# Exercise 3-5
print("Welcome to the Love Calculator!")
name1 = input("What is your name? \n")
name2 = input("What is their name? \n")

lower_case1 = name1.lower()
lower_case2 = name2.lower()

true_score = 0
love_score = 0

true_score += lower_case1.count("t")
true_score += lower_case1.count("r")
true_score += lower_case1.count("u")
true_score += lower_case1.count("e")

true_score += lower_case2.count("t")
true_score += lower_case2.count("r")
true_score += lower_case2.count("u")
true_score += lower_case2.count("e")

love_score += lower_case1.count("l")
love_score += lower_case1.count("o")
love_score += lower_case1.count("v")
love_score += lower_case1.count("e")

love_score += lower_case2.count("l")
love_score += lower_case2.count("o")
love_score += lower_case2.count("v")
love_score += lower_case2.count("e")

total_score = str(true_score) + str(love_score)

if(int(total_score) < 10 or int(total_score) > 90):
    print("Your score is "+total_score+", you go together like coke and mentos.")
elif(int(total_score) > 40 and int(total_score) < 50):
    print("Your score is "+total_score+", you are alright together.")
else:
    print("Your score is "+total_score+".")