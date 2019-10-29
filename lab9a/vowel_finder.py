def vowel(c: chr) -> bool:
	vowels = {
		'a',
		'e',
		'i',
		'o',
		'u',
		'y'
	}
	return c in vowels


def find_vowel(s: str) -> bool:
	return True if vowel(s[0]) is True else False
