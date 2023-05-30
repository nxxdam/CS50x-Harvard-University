def main():
    owed = get_owed()
    coins = calculate_coins(owed)
    print(f"{coins}")

def get_owed():
    while True:
        try:
            owed = float(input("Cash owed?: "))
            if owed > 0:
                break
        except ValueError:
            None
    return owed

def calculate_coins(owed):
    pennies = round(owed * 100)
    coins = 0
    
    while pennies > 0:
        if pennies >= 25:
            pennies -= 25
        elif pennies >= 10:
            pennies -= 10
        elif pennies >= 5:
            pennies -= 5
        else:
            pennies -= 1
        coins += 1
    return coins

main()
