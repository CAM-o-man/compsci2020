from reverser import reverse
from repeat_checker import check_repeat
from anti_fraud import ssid_checker
from caser import swap_case
from len_avg import find_average_len
from repeater import if_letter_repeat
from pairer import find_pairs
from vowel_finder import find_vowel
from augustus import Caesar

if __name__ == "__main__":
    print(reverse("fn ln"))
    print(check_repeat("lolololololololol", "lol"))
    print(ssid_checker("1111-1111-1111-1111-1111-1111-1111-1111"))
    print(swap_case("all_lowercase", True))
    print(find_average_len(("a string", "a second string")))
    print(if_letter_repeat("sssnakes talk like thisssss"))
    print(find_pairs("There are no repeats here."))
    print(find_vowel("help"))
    print(Caesar.cipher("This is a secret message", 4))
    print(Caesar.decipher(Caesar.cipher("This is a secret message", 4), 4))
