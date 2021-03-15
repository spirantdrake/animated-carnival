#Example 1
#var = "Hello"
#print(var[0])

#Example 2
#print(type(var))
#a = str(123)
#print(type(a))

#Exercise 2-1
#initial_value = input("Enter a two digit number:\n")
#first_num = int(initial_value[0])
#second_num = int(initial_value[1])
#print(first_num + second_num)

#Exercise 2-2
#height = float(input("Enter your height in m:\n"))
#weight = float(input("Enter your weight in kg:\n"))
#bmi = int(weight / (height**2))
#print(bmi)

#Example 3
#print(round(8 / 3, 2))
#print(8 // 3)
#print(8 % 3)
#f-string
#score = 0
#print(f"your score is {score}")

#Exercise 2-3
#age = int(input("Enter your age:\n"))
#remaining_age = 90 - age
#days = remaining_age * 365
#weeks = remaining_age * 52
#months = remaining_age * 12
#print(f"You have {days} days, {weeks} weeks, and {months} months left until you turn 90.")

#Day 2 Project
print("Welcome to the tip calculator.")
total_bill = float(input("What was the total bill? $"))
tip_percent = int(input("What percentage tip would you like to give? 10, 12, or 15? "))
split = int(input("How many people to split the bill? "))

tip_amount = total_bill * (tip_percent / 100)
bill_and_tip = total_bill +tip_amount
individual = round(bill_and_tip / split, 2)

print(f"Each person should pay: ${individual}")