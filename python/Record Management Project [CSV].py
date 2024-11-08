# Laptop Record Management
# [Model No, Ram, Memory Type, Memory Size]
from csv import writer, reader

HEADER = ['Model No', 'Ram', 'Memory Type', 'Memory Size']

def create():
    try:
        f = open('Laptop.csv', 'w')
        recs = writer(f, lineterminator='\n')
        recs.writerow(HEADER)

        while True:
            model = int(input('Enter Model No.: '))
            ram = int(input('Enter RAM (in GB): '))
            mem_type = input('Enter Memory Type (SSD/HDD): ').upper()
            mem_size = int(input('Enter Memory Size (in GB): '))
            print()
            data = [model, ram, mem_type, mem_size]
            recs.writerow(data)
            ask = input('Add more Records(y/n):')
            print()

            if ask in 'Nn':
                break

        print('RECORD CREATED')

    except ValueError:
        print('\nINVALID INPUT')

    f.close()

def display():
    try:
        f = open('Laptop.csv', 'r')
        recs = reader(f)
        flag = False

        for data in recs:
            print(data)
            flag = True

        print('\nALL RECORD DISPLAYED')

    except FileNotFoundError:
        print('\nNO FILE FOUND')

    if not flag:
        print('\nNO RECORD FOUND')

    f.close()


def append():
    try:
        f = open('Laptop.csv', 'a')
        recs = writer(f, lineterminator='\n')

        model = int(input('Enter Model No. : '))
        ram = int(input('Enter RAM (in GB) : '))
        mem_type = input('Enter Memory Type (SSD/HDD): ').upper()
        mem_size = int(input('Enter Memory Size (in GB): '))

        data = [model, ram, mem_type, mem_size]
        recs.writerow(data)
        f.close()
        print('\nRECORD ADDED')

    except :
        print('\nINVALID INPUT')


def search():
    try:
        f = open('Laptop.csv', 'r')
        mod = input('Enter Model no. : ')
        recs = reader(f)
        flag = False

        for data in recs:
            if data[0] == mod:
                flag = True
                print(data)
                break

    except FileNotFoundError:
        print('\nNO FILE FOUND')

    if not flag:
        print('\nNO RECORD FOUND')

    f.close()


def update():
    try:
        f = open('Laptop.csv', 'r+')
        mod = input('Enter Model no. : ')
        recs = reader(f)
        new_recs = []
        flag = False

        for data in recs:
            if data[0] == mod:
                flag = True
                ram = int(input('Enter New RAM (in GB) : '))
                mem_type = input('Enter New Memory Type (SSD/HDD): ').upper()
                mem_size = int(input('Enter New Memory Size (in GB): '))
                new_recs.append([data[0], ram, mem_type, mem_size])

            else:
                new_recs.append(data)

        f.close()

        if flag:
            f = open('Laptop.csv', 'w')
            recs = writer(f, lineterminator='\n')
            recs.writerows(new_recs)
            print('\nRECORD UPDATED')
            f.close()

        else:
            print('\nNO RECORD FOUND')
        
    except FileNotFoundError:
        print('\nNO FILE FOUND')


def delete():
    try:
        f = open('Laptop.csv', 'r')
        mod = input('Enter Model No. : ')
        recs = reader(f)
        new_recs = []
        flag = False

        for data in recs:
            if not (data[0] == mod):
                new_recs.append(data)

            else:
                print('\nRECORD DELETED')
                flag = True

        f.close()

        if flag:
            f = open('Laptop.csv', 'w')
            recs = writer(f, lineterminator='\n')
            recs.writerows(new_recs)
            f.close()
 
        else:
            print('\nNO RECORD FOUND')

    except FileNotFoundError:
        print('\nNO FILE FOUND')


while True:
    print('\n\n')
    print('\t\tMAIN MENU')
    print('*********************************************\n')
    print('1. Create Record')
    print('2. Display Record')
    print('3. Append Record')
    print('4. Search Record')
    print('5. Update Record')
    print('6. Delete Record')
    print('7. Exit from Project\n')
    print('*********************************************\n')
    choice = int(input('Enter your choice between 1 to 7 ---> '))
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
        print('EXIT SUCCESSFUL')
        break
    else:
        print('Invalid Input')