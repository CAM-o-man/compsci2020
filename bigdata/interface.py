from typing import Union
from typing import Optional

def acquire_user_request() -> str:
    print("Please input the data you need.\nWould you like to know:\n"
          + "1. \tThe most popular name overall?\n"
          + "2. \tThe most popular name of a specific gender?\n"
          + "3. \tThe least popular name?\n"
          + "4. \tHow popular a specific name is?\n"
          + "5. \tExit")
    usr: str = input("Please enter your choice's number: ")

    return usr

def return_request(request: Union[int, str]) -> Optional[str]:
    print(request)
    # Continue from here TODO: configure request and pseudoshell system
