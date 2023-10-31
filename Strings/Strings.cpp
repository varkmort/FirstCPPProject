// Strings.cpp : 
#include <iostream>
#include <sstream>
#include <format>

#include <cstring>

const char text[]{ R"(My mistress' eyes are nothing like the sun,
Coral is far more red, than her lips red,
If snow be white, why then her breasts are dun:
If hairs be wires, black wires grow on her head:
I have seen roses damasked, red and white,
But no such roses see I in her cheeks,
And in some perfumes is there more delight,
Than in the breath that from my mistress reeks.
I love to hear her speak, yet well I know,
That music hath a far more pleasing sound:
I grant I never saw a goddess go,
My mistress when she walks treads on the ground.
And yet by heaven I think my love as rare,
As any she belied with false compare.)" };

int Length(const char* str) {
	int length{};
	while (str[length] != '\0') {
		length += 1;
	}
	//while (str[length++]);
	return length;
}

int Words(const char* str) {
	int length{};
	int count{};
	while (str[length] != '\0') {
		if (str[length] == ' ') {
			count += 1;
		}
		length += 1;
	}
	return count+1;
}

int Find(const char* str, const char* fnd) {
	int length{};
	int count{};
	while (str[length] != '\0') {
		bool flag{false};
		for (int j{ 0 }; fnd[j] != '\0'; j += 1) {
			if (str[length + j] == fnd[j]) {
				flag = true;
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag) {
			return count+1;
		}
		if (str[length] == ' ') {
			count += 1;
		}
		length += 1;
	}
	return count + 1;

}

int main(){
	const char strTest[] = "qw\tter ers\ner ty";
	const char src[] = "er";
	const char strTes_[]{ 'q','w','e','r','t','y'};
	
	std::cout << strTest << "\nLength: ";
	std::cout << Length(strTest) << '\n';
	std::cout << "Words: " << Words(strTest) << '\n';
	std::cout << "Find er: " << Find(strTest, src) << '\n';

	return 0;
}