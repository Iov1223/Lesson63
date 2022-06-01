#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define chui(ch) (unsigned int)ch
// Задача 1
string tobinary(char num) {
	string res;
	for (int i = 7; i >= 0; i--)
		res += to_string((num >> i) & 1);
		return res;
}
string tobinary(short num) {
	string res;
	for (int i = 15; i >= 0; i--)
		res += to_string((num >> i) & 1);
	return res;
}
string tobinary(int num) {
	string res;
	for (int i = 31; i >= 0; i--)
		res += to_string((num >> i) & 1);
	return res;
}

int tohex(string bin) {
	
	int res = 0;
	for (int i = bin.size() - 1; i >= 0; i--) {
		if (bin[i] != '0' && bin[i] != '1')
			throw invalid_argument("not binary");
		int tmp = bin[i] - '0';
		tmp = tmp * pow(2, bin.size() - i - 1);
		res += tmp;
	}
	return res;
}

int main() {
	setlocale(LC_ALL, "ru");

	//unsigned char n, m;
	// Битовые сдвиги
	/*n = 34;     // 00100010
	n <<= 2;    // 10001000 - 136
	cout << chui(n) << endl;

	n = 200;   // 110001000
	n >>= 4;    // 00001100 - 12
	cout << chui(n) << endl;*/

	// Дополнение (инверсия)
	/*n = 4; // 00000100
	n = ~n; // 11111011 - 251
	cout << chui(n) << endl;

	unsigned int x = 4; // 00000000000000000000000000000100
	x = ~x;             // 11111111111111111111111111111011
	cout << x << endl;*/


	// Задача 1
	cout << "Задача 1.\n";
	char z1ch = 77;    // 1001101
	short z1sh = 1555; // 11000010011
	int z1i = 88000;   // 10101011111000000
	cout << chui(z1ch) << " = " << tobinary(z1ch) << endl;
	cout << z1sh << " = " << tobinary(z1sh) << endl;
	cout << z1i << " = " << tobinary(z1i) << endl;

	// Задача 1
	try {
		cout << "Задача 1.\nВведите двоичный код:";
		string bin;
		cin >> bin;
		cout << bin << " = " << tohex(bin) << endl;
	}
	catch (const invalid_argument& ex) {
		cout << "Ошибка: " << ex.what() << endl;
	}

		return 0;
}