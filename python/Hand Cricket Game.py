from random import choice

PLAYABLES = ("bat", "bowl")
CHOOSABLES = ("odd", "even")
SCOREABLES = (1, 2, 3, 4, 5, 6)

def toss():
    toss_won = False

    while True:
        user_choice = input("Choose odd/even: ").lower()
        print()

        if user_choice in CHOOSABLES:
            break

        else:
            print("Choose 'even' or 'odd' only!")

    while True:
        try:
            user_toss = int(input("Enter toss (1-6): "))

            if user_toss in SCOREABLES:
                break

            else:
                print("Enter number from 1 to 6 only!")

        except ValueError:
            print("Enter number from 1 to 6 only!")

    comp_toss = choice(SCOREABLES)
    print(f"Computer choose {comp_toss}")

    if ((user_toss + comp_toss) % 2 == 0 and user_choice == CHOOSABLES[1]) or\
        ((user_toss + comp_toss) % 2 == 1 and user_choice == CHOOSABLES[0]):
        toss_won = True
        print("You won the toss\n")

        while True:
            user_des = input("Choose bat/bowl: ").lower()
            print()

            if user_des in PLAYABLES:
                break

            else:
                print("Choose 'bat' or 'bowl' only!")

    else:
        comp_des = choice(PLAYABLES)
        print(f"Computer won the toss and chooses to {comp_des}\n")

    if toss_won:
        if user_des == PLAYABLES[0]:
            comp_des = PLAYABLES[1]

        else:
            comp_des = PLAYABLES[0]

    else:
        if comp_des == PLAYABLES[0]:
            user_des = PLAYABLES[1]

        else:
            user_des = PLAYABLES[0]

    return {"user_des": user_des, "comp_des": comp_des}

def user_scoring(game):
    while True:
        try:
            if game == PLAYABLES[0]:
                user_score = int(input("Score a Run (1-6): "))

            else:
                user_score = int(input("Throw a ball (1-6): "))

            if user_score in SCOREABLES:
                return user_score

            else:
                print("Enter number from 1 to 6 only!")

        except ValueError:
            print("Enter number from 1 to 6 only!")

def comp_scoring(game):
    comp_score = choice(SCOREABLES)

    if game == PLAYABLES[0]:
        print(f"Computer scores {comp_score}")

    else:
        print(f"Computer bowls {comp_score}")

    return comp_score


total_score = 0
innings1, innings2 = True, False
D = toss()

while innings1:
    if D["user_des"] == PLAYABLES[0]:
        user_batting_score, comp_bowling_score = user_scoring(PLAYABLES[0]), comp_scoring(PLAYABLES[1])

        if user_batting_score == comp_bowling_score:
            print("\nUser OUT!!")
            print(f"Total run scored by User: {total_score}\n")
            print("Now User bowls and Computer bats")
            print(f"Computer needs {total_score + 1} runs to win\n")
            innings1, innings2 = False, True
            break

        else:
            total_score += user_batting_score
            print(f"Total user score {total_score}\n")

    elif D["user_des"] == PLAYABLES[1]:
        user_bowling_score, comp_batting_score = user_scoring(PLAYABLES[1]), comp_scoring(PLAYABLES[0])

        if user_bowling_score == comp_batting_score:
            print("\nComputer OUT!!")
            print(f"Total run scored by Computer: {total_score}\n")
            print("Now User bats and Computer bowls")
            print(f"User needs {total_score + 1} runs to win\n")
            innings1, innings2 = False, True
            break

        else:
            total_score += comp_batting_score
            print(f"Total computer score {total_score}\n")

while innings2:
    if D["user_des"] == PLAYABLES[0]:
        user_bowling_score, comp_batting_score = user_scoring(PLAYABLES[1]), comp_scoring(PLAYABLES[0])

        if user_bowling_score == comp_batting_score:
            print("Computer OUT!!")

            if total_score > 0:
                print(f"User won the match by {total_score} runs!!")

            else:
                print("Computer won the match")

            innings2 = False
            break

        else:
            total_score -= comp_batting_score

            if total_score <= 0:
                print("Computer won the match")
                break

            print(f"Computer needs more {total_score} to win\n")

    elif D["user_des"] == PLAYABLES[1]:
        user_batting_score, comp_bowling_score = user_scoring(PLAYABLES[0]), comp_scoring(PLAYABLES[1])
    
        if user_batting_score == comp_bowling_score:
            print("User OUT!!")

            if total_score > 0:
                print(f"Computer won the match by {total_score} runs!!")

            else:
                print("User won the match")

            innings2 = False
            break

        else:
            total_score -= user_batting_score

            if total_score <= 0:
                print("User won the match")
                break

            print(f"User needs more {total_score} to win\n")