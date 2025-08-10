# SPDX-License-Identifier: MIT
# Copyright (c) 2025 Your Name

import json
import os
from phonebook import Phonebook

DATA_FILE = "contacts.json"

def load_contacts(pb):
    if os.path.exists(DATA_FILE):
        with open(DATA_FILE, "r") as f:
            data = json.load(f)
            for name, number in data.items():
                pb.add_contact(name, number)

def save_contacts(pb):
    with open(DATA_FILE, "w") as f:
        json.dump(pb.get_AllContacts(), f, indent=2)

def main():
    pb = Phonebook()
    load_contacts(pb)

    while True:
        print("\n1. Add contact")
        print("2. Remove contact")
        print("3. Get number")
        print("4. List all")
        print("5. Exit")
        choice = input("Enter choice: ")

        if choice == "1":
            name = input("Name: ")
            number = int(input("Number: "))
            pb.add_contact(name, number)
            save_contacts(pb)
            print("Contact added.")

        elif choice == "2":
            name = input("Name: ")
            if pb.remove_contact(name):
                save_contacts(pb)
                print("Removed.")
            else:
                print("Not found.")

        elif choice == "3":
            name = input("Name: ")
            print("Number:", pb.get_number(name))

        elif choice == "4":
            for name, number in pb.get_AllContacts().items():
                print(f"{name}: {number}")

        elif choice == "5":
            save_contacts(pb)
            print("Goodbye!")
            break

        else:
            print("Invalid choice.")

if __name__ == "__main__":
    main()
