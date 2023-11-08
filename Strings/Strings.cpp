// Strings.cpp : 
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include <format>
#include <vector>
#include <cstring>


//R"(text)"

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

// json, xml, ini, csv
int main2(){
	const char strTest[] = "qw\tter ers\ner ty";
	const char src[] = "er";
	const char strTes_[]{ 'q','w','e','r','t','y'};
	
	std::cout << strTest << "\nLength: ";
	std::cout << Length(strTest) << '\n';
	std::cout << "Words: " << Words(strTest) << '\n';
	std::cout << "Find er: " << Find(strTest, src) << '\n';

	return 0;
}

int main3() {
	std::stringstream stream(text);
	std::vector<std::string> words;

	while (!stream.eof()) {
		std::string tmp;
		stream >> tmp;
		words.push_back(tmp);
	}

	std::cout << "Was found " << words.size() << " words:\n";
	for (int i = 0; i < words.size(); i++){
		std::cout << std::setw(3) << i + 1 << ": " <<
			words[i] << '\n';
	}


	return 0;
}

int main4() {
	std::stringstream stream(text);
	std::vector<std::string> lines;

	while (!stream.eof()) {
		std::string tmp;
		std::getline(stream,tmp,'\n');
		lines.push_back(tmp);
	}

	std::cout << "Was found " << lines.size() << " lines:\n";
	for (int i = 0; i < lines.size(); i++) {
		std::cout << std::setw(3) << i + 1 << ": " <<
			lines[i] << '\n';
	}

	return 0;
}

/*
	показать пользователю только уникальные слова в исходном тексте
	
	выбрать любое слово из текста, показать сколько раз оно
	встречается в каждой строке

*/

//считать текст и заменить в нём какое либо слово на другое
int main() {
	std::stringstream t_stream(text);
	std::string example{ "her" };
	std::string replace{ "HER" };

	std::string final_text;

	std::stringstream t_ostream(final_text);
	while(!t_stream.eof() ){
		std::string tmp;
		std::getline(t_stream, tmp, '\n');
		std::stringstream words(tmp);
		while (!words.eof()) {
			std::string word;
			words >> word;
			if (word == example) {
				t_ostream << replace;
			}
			else {
				t_ostream << word;
			}
			t_ostream << ' ';
		}
		t_ostream << '\n';
	}
	//t_ostream.flush();
	final_text = t_ostream.str();
	std::to_string(3.5);
	std::cout << text << "\n\n\n";
	std::cout << final_text;
	return 0;
}

const char mask[]{ 
"What answer have equation Y = K * X + C \n\
1 - X \n\
2 - A\n\
3 - B\n\
4 - Z\n" };
/*
Задача
написать программу в которой пользователь вводит сколько нужно сгенирировать 
задачь на решение линейных уравнений и макисмальные-мнимальные значения 
коэффициентов уравнения.
после чего программа выводит на экран список задачь с вариантами ответов 
согласно маске
Y, K, C - генерируется. X - расчитывается
A, B, Z - должны гарантированно отличаться от X
*/

// 24 = 8.64 - это верное равенство но почему