class Caesar:

    @staticmethod
    def cipher(plain: str, s: int) -> str:
        result = ""
        for char in plain:

            if char.isupper():
                result += chr((ord(char) + s - 65) % 26 + 65)
            else:
                result += chr((ord(char) + s - 97) % 26 + 97)
        return result

    @staticmethod
    def decipher(encrypted: str, s: int) -> str:
        result = ""
        for char in encrypted:
            if char.isupper():
                result += chr((ord(char) - s - 65) % 26 + 65)
            else:
                result += chr((ord(char) - s - 97) % 26 + 97)

        return result

    # def brute(self, encrypted: str) -> list:
    #     result: str = ""
    #     LETTERS = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
    #                'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
    #                's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ']
    #     for key in range(len(LETTERS)):
    #         for symbol in encrypted:
    #             if symbol.isupper():
    #                 TODO: Return to bruteforce at a later date



cipherer = Caesar()
print(cipherer.cipher("test string", 4))
print(cipherer.decipher(cipherer.cipher("test string", 4), 4))
