# logic program to build a kbc game in python


iq = [
    {
        "question": "What is the next number in the sequence: 1, 4, 9, 16, ...?",
        "answer": 25
    },
    {
        "question": "Which word in the English language is spelled incorrectly in every dictionary?",
        "answer": "Incorrectly"
    },
    {
        "question": "If you rearrange the letters 'CIFAIPC,' you would get the name of a(n):",
        "answer": "Ocean"
    },
    {
        "question": "How many triangles are in the following image? (Assume all lines are straight)",
        "answer": 24
    },
    {
        "question": "A farmer has 17 sheep, and all but 9 die. How many sheep are left?",
        "answer": 9
    }
]
print("Lets start the game KBC.....!!!!!")
amount=0
print(" ")
print("You will get one $1000 for each questions right....!!!!!")

print("Lets start")
for x in range(0,len(iq)):
    print(x+1,".",iq[x]["question"])
    ans = input("Enter your answer: ")
    if str(ans).lower() == str(iq[x]["answer"]).lower():
        print("Correct...!!!!")
        amount+=1000 
    else:
        print("Wrong answer!!!!!")
        break

print("Your total money winner is : $",amount)
    