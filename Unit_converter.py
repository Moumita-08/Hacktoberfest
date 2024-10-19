def km_to_miles(km):
    return km * 0.621371

def miles_to_km(miles):
    return miles / 0.621371

def main():
    print("Unit Converter")
    print("1. Kilometers to Miles")
    print("2. Miles to Kilometers")
    choice = input()

    if choice == '1':
        km = float(input())
        print(f"{km} kilometers is {km_to_miles(km)} miles")
    elif choice == '2':
        miles = float(input())
        print(f"{miles} miles is {miles_to_km(miles)} kilometers")
    else:
        print("Invalid choice")

if __name__ == "__main__":
    main()
