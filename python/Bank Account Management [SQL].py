from mysql.connector import connect, ProgrammingError, DatabaseError
from typing import Literal

def login_database() -> dict:
    """establishes the connection between sql and python and returns a dict containing the connection objects"""

    while True:
        print("Please input your MySQL login credentials in order to use the database.")
        host = input("Enter host name: ")
        username = input("Enter username: ")
        password = input("Enter password: ")

        try:
            db = connect(host=host, username=username, password=password)
            cursor = db.cursor()
            print("MySQL Login Successful.")
            return {"db": db, "cursor": cursor}
        
        except ProgrammingError:
            print("Incorrect Login Credentials. Try Again...")

def check_database() -> None:
    """checks for the existence of the database and the required table"""

    try:
        DATABASE["cursor"].execute("CREATE DATABASE bank_management")

    except DatabaseError:
        pass

    DATABASE["cursor"].execute("USE bank_management")
    create_table = '''CREATE TABLE bank_details
        (account_no INTEGER PRIMARY KEY,
        username VARCHAR(40),
        password VARCHAR(32),
        name VARCHAR(50),
        gender CHAR(1),
        phone_no CHAR(10),
        balance FLOAT)
    '''
    
    try:
        DATABASE["cursor"].execute(create_table)
        DATABASE["cursor"].execute("INSERT INTO bank_details VALUES (1000, 'admin', '2503', 'dream', 'M', '12345', 10000.00)")

    except ProgrammingError:
        pass

    DATABASE["db"].commit()

def enter_specific(itype: Literal["password", "phone no."]) -> str:
    """accepts the specific type of input from the user\n
    password type --> accepts a password with specific requirements\n
    phone no. type --> accepts a phone number with specific requirements"""

    if itype == "password":
        special_characters = "!#$%&( )*+,-./:;<=>?@[]^_`{|}~"
        valid = [False, False, False]

        while True:
            print("\nThe password must at least be 8 character long and must contain one alphabet, number and special symbol")
            password = input("Enter password: ")

            for ch in password:
                if ch.isalpha():
                    valid[0] = True

                elif ch.isdigit():
                    valid[1] = True

                elif ch in special_characters:
                    valid[2] = True

            if valid == [True, True, True]:
                conform_password = input("Confirm password: ")

                if password == conform_password:
                    print("Password Accepted!\n")
                    return password

                else:
                    print("Incorrect Password. Try Again...")
                    return enter_specific("password")

            else:
                print("Invalid Password. Try Again...\n")

    elif itype == "phone no.":
        while True:
            ph_no = input("Enter phone no.: ")

            if not (ph_no.isnumeric() and len(ph_no) == 10):
                print("Enter only '10 DIGIT PHONE NUMBER'.\n")

            else:
                return ph_no

def create_account() -> None:
    """creates a new account and updates the sql database"""

    print("\nCreating Account")
    name = input("Enter name: ").title()

    while True:
        gender = input("Enter gender(M/F): ").upper()

        if not (len(gender) == 1 and gender in "MF"):
            print("Choose either 'M' or 'F'.\n")

        else:
            break

    ph_no = enter_specific("phone no.")

    while True:
        username = input("Enter a unique username: ")

        if check_username(username):
            print("Username already taken. Try Again...\n")

        else:
            break
            
    password = enter_specific("password")
    DATABASE["cursor"].execute("SELECT account_no FROM bank_details")
    from random import randint

    while True:
        rand_ac_no = randint(1001, 9999)

        for ac_no in DATABASE["cursor"]:
            if rand_ac_no == ac_no[0]:
                break

        else:
            break
                
    user_details = (rand_ac_no, username, password, name, gender, ph_no, 0.00)
    DATABASE["cursor"].execute(f"INSERT INTO bank_details VALUES{user_details}")
    DATABASE["db"].commit()
    display_account()

def login_account() -> str:
    """logins the account and returns the logged-in username"""

    global LOGGED_IN
    print("\nLogging In Account")
    username = input("Enter username: ")
    DATABASE["cursor"].execute("SELECT username, password FROM bank_details")

    for details in DATABASE["cursor"]:
        if details[0] == username:
            while True:
                password = input("Enter password: ")

                if details[1] == password:
                    print("\nLogin Successful!")
                    input("press enter to continue...")
                    LOGGED_IN = True
                    return details[0]

                else:
                    print("Incorrect password, try again\n")

    else:
        while not LOGGED_IN:
            inp = input("Press '1' to create an account or '2' to try again: ")

            if inp == '1':
                return create_account()

            elif inp == '2':
                return login_account()

            else:
                print("Invalid Input.\n")

def reset_database(mode: Literal["silent", "loud"]) -> None:
    """resets the configuration of the database to default\n
    silent mode --> doesn't display the reset successful message\n
    loud mode --> shows the reset successful message"""
    
    DATABASE["cursor"].execute("DROP TABLE bank_details")
    check_database()

    if mode == "loud":
        print("\nData Successfully Reset!!")

def display_database() -> None:
    """displays all details contained in the database"""

    DATABASE["cursor"].execute("SELECT * FROM bank_details")

    for detail in DATABASE["cursor"]:
        print(detail)

def delete_database() -> None:
    """deletes the sql database\n\nTHE DELETED DATA ARE NOT RECOVERABLE ANYMORE!"""

    DATABASE["cursor"].execute("DROP DATABASE bank_management")
    DATABASE["db"].commit()
    DATABASE["cursor"].close()
    DATABASE["db"].close()
    print("\nData Successfully Deleted")

def display_account() -> None:
    """displays all the details of the logged in account"""

    header = ("account no.", "username", "password", "name", "gender", "phone no." ,"balance")
    print("Account Details\n")
    DATABASE["cursor"].execute(f"SELECT * FROM bank_details WHERE username = {ACTIVE}")

    for head, body in zip(header, DATABASE["cursor"].fetchone()):
        if head == "password":
            print(f"{head} --> {"*" * len(body)}")

        else:
            print(f"{head} --> {body}")
    
    input("\npress enter to continue...")

def edit_account() -> None:
    """edits the account of the username provided and updates the database """

    edit_menu = '''
1. Name
2. Password
3. Phone Number
'''
    print("\nEditing Account Details")
    print(edit_menu)

    while True:
        inp = input("Select what to edit --> ")

        if inp == '1':
            new_name = input("Enter new name: ")
            DATABASE["cursor"].execute(f"UPDATE bank_details SET name = '{new_name}' WHERE username = '{ACTIVE}'")
            print("\nSuccessfully New Name Updated.")

        elif inp == "2":
            new_password = enter_specific("password")
            DATABASE["cursor"].execute(f"UPDATE bank_details SET password = '{new_password}' WHERE username = '{ACTIVE}'")
            print("Successfully New Password Updated.")

        elif inp == "3":
            new_ph_no = enter_specific("phone no.")
            DATABASE["cursor"].execute(f"UPDATE bank_details SET phone_no = '{new_ph_no}' WHERE username = '{ACTIVE}'")
            print("\nSuccessfully New Phone Number Updated")

        else:
            print("Enter Valid Input. Try Again...\n")
            continue

        input("press enter to continue...")
        return DATABASE["db"].commit()

def accept_amount() -> float:
    """accepts amount from user, validates and returns it"""

    while True:
        try:
            res = float(input("\nEnter amount: "))

            if res < 0:
                raise ValueError

        except ValueError:
            print("Input Valid Number. Try Again...")

        else:
            return res

def transaction(itype: Literal["deposit", "withdraw"], iamount: float) -> None:
    """deposits or withdraws the amount of money from the username provided"""

    if itype == "deposit":
        DATABASE["cursor"].execute(f"UPDATE bank_details SET balance = balance + {iamount} WHERE username = '{ACTIVE}'")

    elif itype == "withdraw":
        DATABASE["cursor"].execute(f"UPDATE bank_details SET balance = balance - {iamount} WHERE username = '{ACTIVE}'")
    
    print("\nTransaction Completed Successfully!!")
    input("press enter to continue...")
    return DATABASE["db"].commit()

def check_username(username: str) -> bool:
    """checks the existence of the username in database and returns a boolean value"""

    DATABASE["cursor"].execute("SELECT username FROM bank_details")

    for user in DATABASE["cursor"]:
        if user[0] == username:
            return True
    
    return False

def pay(ireceiver: str, iamount: float) -> None:
    """pays the amount to the username from the username provided """

    DATABASE["cursor"].execute(f"UPDATE bank_details SET balance = balance - {iamount} WHERE username = '{ACTIVE}'")
    DATABASE["cursor"].execute(f"UPDATE bank_details SET balance = balance + {iamount} WHERE username = '{ireceiver}'")
    print("Transaction Completed Successfully!")
    input("\npress enter to continue...")
    return DATABASE["db"].commit()

def delete_account() -> None:
    """deletes the logged in account from the database"""

    global LOGGED_IN, ACTIVE
    print("\nDeleting Account.")

    while True:
        password1 = input("Enter password: ")
        password2 = input("Enter password again: ")
        DATABASE["cursor"].execute(f"SELECT password FROM bank_details WHERE username = '{ACTIVE}'")

        if DATABASE["cursor"].fetchone()[0] == password1 == password2:
            while True:
                conformation = input("\nDO YOU REALLY WANT TO DELETE YOUR ACCOUNT. TYPE 'YES' TO CONTINUE OR 'NO' TO ABORT: ").upper()

                if conformation == "YES":
                    DATABASE["cursor"].execute(f"DELETE FROM bank_details WHERE username = '{ACTIVE}'")
                    print("Account Successfully Deleted!")
                    LOGGED_IN = False
                    del ACTIVE
                    return DATABASE["db"].commit()

                elif conformation == "NO":
                    print("Account Deletion Unsuccessful!")
                    break

                else:
                    print("Invalid Input. Try Again...")

            break

        else:
            print("Incorrect Password. Try Again...\n")

def get_balance() -> float:
    DATABASE["cursor"].execute(f"SELECT balance FROM bank_details WHERE username = '{ACTIVE}'")
    return DATABASE["cursor"].fetchone()[0]

MAIN_MENU1 = '''
    MAIN MENU   
1. Create Account
2. Login Account
3. Quit'''

MAIN_MENU2 = '''
    MAIN MENU   
1. Account Details
2. Edit Details
3. Deposit
4. Withdraw
5. Pay
6. Balance Enquiry
7. Delete Account
8. Log Out'''

LOGGED_IN = False





#MAIN CODE LOOP
DATABASE = login_database()
check_database()

while True:
    if not LOGGED_IN:
        print(MAIN_MENU1)
        check = input("\nEnter your choice: ")

        if check == '1':
            create_account()

        elif check == '2':
            if LOGGED_IN:
                print("\nAlready Logged In")

            else:
                ACTIVE = login_account()
                print(ACTIVE)

        elif check == '3':
            print("\nThank you for using!")
            break

        elif check == "reset":
            reset_database("loud")

        elif check == "inspect":
            display_database()

        elif check == "delete":
            delete_database()
            break

        else:
            print("Invalid Input. Try Again...")

    else:
        print(MAIN_MENU2)
        check = input("\nEnter your choice: ")

        if check == '1':
            display_account()

        elif check == '2':
            edit_account()
        
        elif check == '3':
            print("\nInitiating Transaction.", end="")
            amount = accept_amount()
            transaction("deposit", amount)

        elif check == '4':
            print("\nInitiating Transaction.", end="")
            amount = accept_amount()
            balance = get_balance()

            if balance < amount:
                print("Insufficient Balance.")
                print(f"Available Balance --> {balance} and Requested Amount ---> {amount}") 
                input("press enter to continue...")

            else:
                transaction("withdraw", amount)

        elif check == '5':
            receiver = input("Enter Receiver's username: ")

            if check_username(receiver):
                amount = accept_amount()
                balance = get_balance()

                if balance < amount:
                    print("Insufficient Balance.")
                    print(f"Available Balance --> {balance} and Requested Amount ---> {amount}") 
                    input("press enter to continue...")

                else:
                    pay(receiver, amount)

            else:
                print("username doesn't exist")
                input("press enter to continue...")

        elif check == "6":
            print("\nYour Current Balance is", get_balance)
            input("press enter to continue...")

        elif check == "7":
            delete_account()

        elif check == "8":
            LOGGED_IN = False
            del ACTIVE

        elif check == "inspect":
            display_database()

        else:
            print("Invalid Input. Try Again...")