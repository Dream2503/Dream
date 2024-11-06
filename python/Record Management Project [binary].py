# Laptop Record Management
# [Model No, Ram, Memory Type, Memory Size]
from pickle import load, dump

def create():
    f = open("Laptop.dat", "wb")

    try:
        while True:
            model = int(input("Enter Model No.: "))
            ram = int(input("Enter RAM (in GB): "))
            mem_type = input("Enter Memory Type (SSD/HDD): ").upper()
            mem_size = int(input("Enter Memory Size (in GB): "))
            data = [model, ram, mem_type, mem_size]
            dump(data, f)
            ask = input("\nAdd more Records(y/n): ")
            print()

            if ask in "Nn":
                break

        print("RECORD CREATED")

    except ValueError:
        print("\nINVALID INPUT")

    f.close()

def display():
    try:
        f = open("Laptop.dat", "rb")
        flag = False

        while True:
            data = load(f)
            print(data)
            flag = True

    except FileNotFoundError:
        print("\nNO FILE FOUND")
    except EOFError:
        print("\nALL RECORD DISPLAYED")
        f.close()

        if not flag:
            print("\nNO RECORD FOUND")

def append():
    try:
        f = open("Laptop.dat", "ab")
        model = int(input("Enter Model No. : "))
        ram = int(input("Enter RAM (in GB) : "))
        mem_type = input("Enter Memory Type (SSD/HDD): ").upper()
        mem_size = int(input("Enter Memory Size (in GB): "))
        data = [model, ram, mem_type, mem_size]
        dump(data, f)
        f.close()
        print("\nRECORD ADDED")

    except ValueError:
        print("\nINVALID INPUT")

def search():
    try:
        f = open("Laptop.dat", "rb")
        mod = int(input("Enter Model no. : "))

        while True:
            data = load(f)

            if data[0] == mod:
                print(data)
                break


    except FileNotFoundError:
        print("\nNO FILE FOUND")
    except EOFError:
        print("\nNO RECORD FOUND")

    f.close()


def update():
    try:
        f = open("Laptop.dat", "rb+")
        mod = int(input("Enter Model no. : "))
        cursor = 0

        while True:
            data = load(f)

            if data[0] == mod:
                f.seek(cursor)
                data[1] = int(input("Enter New RAM (in GB) : "))
                data[2] = input("Enter New Memory Type (SSD/HDD): ").upper()
                data[3] = int(input("Enter New Memory Size (in GB): "))
                dump(data, f)
                print("\nRECORD UPDATED")
                break

            else:
                cursor = f.tell()

    except FileNotFoundError:
        print("\nNO FILE FOUND")
    except EOFError:
        print("\nNO RECORD FOUND")

    f.close()


def delete():
    try:
        f = open("Laptop.dat", "rb")
        mod = int(input("Enter Model No. : "))
        L = []

        while True:
            data = load(f)

            if not (data[0] == mod):
                L.append(data)

            else:
                print("RECORD DELETED")

    except FileNotFoundError:
        print("\nNO FILE FOUND")
    except EOFError:
         f.close()
         f = open("Laptop.dat", "wb")

         for i in L:
             dump(i, f)

         f.close()


while True:
    print("\n\n")
    print("\t\tMAIN MENU")
    print("*****************************************\n")
    print("1. Create Record")
    print("2. Display Record")
    print("3. Append Record")
    print("4. Search Record")
    print("5. Update Record")
    print("6. Delete Record")
    print("7. Exit from Project\n")
    print("*****************************************\n")
    choice = int(input("Enter your choice between 1 to 7 ---> "))
    print()

    if choice == 1:
        create()
    elif choice == 2:
        display()
    elif choice == 3:
        append()
    elif choice == 4:
        search()
    elif choice == 5:
        update()
    elif choice == 6:
        delete()
    elif choice == 7:
        print("EXIT SUCCESSFUL")
        break
    else:
        print("Invalid Input")