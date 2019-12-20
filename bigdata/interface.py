from typing import Union
from typing import Optional
import name_parser


def acquire_user_request() -> int:
    print("Please input the data you need.\nWould you like to know:\n"
          + "1. \tThe most popular name overall?\n"
          + "2. \tThe most popular name of a specific gender?\n"
          + "3. \tThe least popular name?\n"
          + "4. \tHow popular a specific name is?\n"
          + "5. \tExit")
    usr: int = int(input("Please enter your choice's number: "))

    return usr


def fulfill():
    usr: int = acquire_user_request() - 1  # subtracting one ensures the request is 0-indexed
    print(name_parser.run(usr))


if __name__ == "__main__":
    fulfill()
