#include "Header.h"
using namespace std;

string AddStringDec(string a, string b)
{
	char chars[] = "?";
	for (unsigned int i = 0; i < strlen(chars); ++i)
	{
		a.erase(std::remove(a.begin(), a.end(), chars[i]), a.end());
	}
	for (unsigned int i = 0; i < strlen(chars); ++i)
	{
		b.erase(std::remove(b.begin(), b.end(), chars[i]), b.end());
	}
	ostringstream convert, convert2, convert3;
	int mem = 0;
	int luu = 0, luu2 = 0, sum = 0;
	string temp = "";
	string temp2 = "";
	string temp3 = "";
	string result = "", min, max;
	int len_a, len_b, len_max, len_min;
	len_a = a.length();
	len_b = b.length();
	if (len_a > len_b)
	{
		len_min = len_b;
		len_max = len_a;
		min = b;
		max = a;
	}
	else {
		len_max = len_b;
		min = a;
		max = b;
		len_min = len_a;
	}
	int j = len_min - 1;
	for (int i = len_max - 1; i >= 0; i--)
	{
		if (j >= 0) {
			convert << (max[i] - 48);
			temp = convert.str();
			luu = stoi(temp);
			convert2 << (min[j] - 48);
			temp2 = convert2.str();
			luu2 = stoi(temp2);
			sum = luu + luu2 + mem;
			if (sum > 9)
			{
				mem = 1;
				sum = sum % 10;
				convert3 << sum;
				temp3 = convert3.str();
				result.insert(0, temp3);
				convert3.str("");
				convert.str("");
				convert2.str("");
				temp = "";
				temp2 = "";
				temp3 = "";
				luu = 0;
				luu2 = 0;
			}
			else
			{
				mem = 0;
				convert3 << sum;
				temp3 = convert3.str();
				result.insert(0, temp3);
				convert3.str("");
				convert.str("");
				convert2.str("");
				temp = "";
				temp2 = "";
				temp3 = "";
				luu = 0;
				luu2 = 0;
			}
			j--;
		}
		else {
			convert << (max[i] - 48);
			temp = convert.str();
			luu = stoi(temp);
			sum = luu + mem;
			if (sum > 9)
			{
				mem = 1;
				sum = sum % 10;
				convert3 << sum;
				temp3 = convert3.str();
				result.insert(0, temp3);
				convert3.str("");
				convert.str("");
				temp = "";
				temp3 = "";
			}
			else
			{
				mem = 0;
				convert3 << sum;
				temp3 = convert3.str();
				result.insert(0, temp3);
				convert3.str("");
				convert.str("");
				temp = "";
				temp3 = "";
			}
		}
	}
	if (mem != 0)
	{
		result.insert(0, "1");
	}

	return result;
}

void writeDataToFile(string file, string data)
{
	fstream f;
	f.open(file, ios::out | ios::app);
	f << data << endl;
	f.close();
}

bool QInt::GetBit(int i)const
{
	bool temp{};
	if (i <= 128 and i > 64)
		temp = this->arrayBits[0] >> (i - 1 - 64) & 1;
	else if (0 < i and i < 65)
		temp = this->arrayBits[1] >> (i - 1) & 1;

	return temp;
}

void QInt::SetBit(int i, bool bit)
{

	QInt temp0, temp1;
	if (129 > i and i > 64)
	{
		for (int j = 128; j > 65; j--)
		{
			if (j != i)
			{
				temp0.arrayBits[0] = temp0.arrayBits[0] | this->GetBit(j);
				temp0.arrayBits[0] = temp0.arrayBits[0] << 1;
			}
			else {
				temp0.arrayBits[0] = temp0.arrayBits[0] | bit;
				temp0.arrayBits[0] = temp0.arrayBits[0] << 1;
			}
		}
		if (i == 65) {
			temp0.arrayBits[0] = temp0.arrayBits[0] | bit;
		}
		else {
			temp0.arrayBits[0] = temp0.arrayBits[0] | this->GetBit(65);
		}
		this->arrayBits[0] = temp0.arrayBits[0];

	}
	else if (65 > i and i > 0)
	{
		for (int j = 64; j > 1; j--)
		{
			if (j != i)
			{
				temp1.arrayBits[1] = temp1.arrayBits[1] | this->GetBit(j);
				temp1.arrayBits[1] = temp1.arrayBits[1] << 1;
			}
			else {
				temp1.arrayBits[1] = temp1.arrayBits[1] | bit;
				temp1.arrayBits[1] = temp1.arrayBits[1] << 1;
			}
		}
		if (i == 1) {
			temp1.arrayBits[1] = temp1.arrayBits[1] | bit;
		}
		else {
			temp1.arrayBits[1] = temp1.arrayBits[1] | this->GetBit(1);
		}
		this->arrayBits[1] = temp1.arrayBits[1];
	}
}

void QInt::Bu2() {
	for (int i = 128; i > 0; i--) {
		if (this->GetBit(i) == 1)
			this->SetBit(i, 0);
		else if (this->GetBit(i) == 0)
			this->SetBit(i, 1);
	}
	int k = this->GetBit(1) + 1;
	if (k == 2) {
		this->SetBit(1, 0);
		this->memory = 1;
	}
	else if (k == 1)
	{
		this->SetBit(1, 1);
		this->memory = 0;
	}
	for (int i = 2; i < 129; i++)
	{
		k = this->GetBit(i) + memory;
		if (k == 2)
		{
			this->memory = 1;
			this->SetBit(i, 0);
		}
		else if (k == 1)
		{
			this->memory = 0;
			this->SetBit(i, 1);
		}
		else if (k == 0)
		{
			this->memory = 0;
			this->SetBit(i, 0);
		}
	}
}

string Div2(string a)
{
	string temp = "";
	string result = "";
	string result1 = "";
	int len = a.length();
	ostringstream convert, convert1;
	for (int i = 0; i < len; i++)
	{
		convert << (a[i] - 48);
		temp = convert.str();
		if (stoi(temp) / 2 != 0)
		{
			convert1 << (stoi(temp) / 2);
			result = convert1.str();
			result1.append(result);
			convert.str("");
			convert1.str("");
			if (stoi(temp) % 2 != 0)
			{
				convert << (stoi(temp) % 2);
				temp = "";
			}
		}
		else {
			result1.append("0");
		}
	}
	return result1;
}

void QInt::DecToQInt(string a)
{
	int dau = 0;
	if (a[0] == 45)
	{
		dau = 1;
		a.erase(0, 1);
	}
	int i = 1;
	int bit = 0;
	for (int i = 1; i < 129; i++) {
		if (a == "")
			break;
		int len = a.length();
		bit = (a[len - 1] - 48) % 2;
		this->SetBit(i, bit);
		a = Div2(a);
	}
	if (dau == 1)
	{
		this->Bu2();
	}
}

void QInt::HexToQInt(string a)
{
	char temp = ' ';
	int j = 1;
	int len = a.length();
	for (int i = len - 1; i >= 0; i--)
	{
		temp = a[i];
		if (temp == '0')
		{
			this->SetBit(j, 0);
			this->SetBit(j + 1, 0);
			this->SetBit(j + 2, 0);
			this->SetBit(j + 3, 0);
			j = j + 4;
			temp = ' ';
		}
		else if (temp == '1')
		{
			this->SetBit(j, 1);
			this->SetBit(j + 1, 0);
			this->SetBit(j + 2, 0);
			this->SetBit(j + 3, 0);
			j = j + 4;
			temp = ' ';
		}
		else if (temp == '2')
		{
			this->SetBit(j, 0);
			this->SetBit(j + 1, 1);
			this->SetBit(j + 2, 0);
			this->SetBit(j + 3, 0);
			j = j + 4;
			temp = ' ';
		}
		else if (temp == '3')
		{
			this->SetBit(j, 1);
			this->SetBit(j + 1, 1);
			this->SetBit(j + 2, 0);
			this->SetBit(j + 3, 0);
			j = j + 4;
			temp = ' ';
		}
		else if (temp == '4')
		{
			this->SetBit(j, 0);
			this->SetBit(j + 1, 0);
			this->SetBit(j + 2, 1);
			this->SetBit(j + 3, 0);
			j = j + 4;
			temp = ' ';
		}
		else if (temp == '5')
		{
			this->SetBit(j, 1);
			this->SetBit(j + 1, 0);
			this->SetBit(j + 2, 1);
			this->SetBit(j + 3, 0);
			j = j + 4;
			temp = ' ';
		}
		else if (temp == '6')
		{
			this->SetBit(j, 0);
			this->SetBit(j + 1, 1);
			this->SetBit(j + 2, 1);
			this->SetBit(j + 3, 0);
			j = j + 4;
			temp = ' ';
		}
		else if (temp == '7')
		{
			this->SetBit(j, 1);
			this->SetBit(j + 1, 1);
			this->SetBit(j + 2, 1);
			this->SetBit(j + 3, 0);
			j = j + 4;
			temp = ' ';
		}
		else if (temp == '8')
		{
			this->SetBit(j, 0);
			this->SetBit(j + 1, 0);
			this->SetBit(j + 2, 0);
			this->SetBit(j + 3, 1);
			j = j + 4;
			temp = ' ';
		}
		else if (temp == '9')
		{
			this->SetBit(j, 1);
			this->SetBit(j + 1, 0);
			this->SetBit(j + 2, 0);
			this->SetBit(j + 3, 1);
			j = j + 4;
			temp = ' ';
		}
		else if (temp == 'A')
		{
			this->SetBit(j, 0);
			this->SetBit(j + 1, 1);
			this->SetBit(j + 2, 0);
			this->SetBit(j + 3, 1);
			j = j + 4;
			temp = ' ';
		}
		else if (temp == 'B')
		{
			this->SetBit(j, 1);
			this->SetBit(j + 1, 1);
			this->SetBit(j + 2, 0);
			this->SetBit(j + 3, 1);
			j = j + 4;
			temp = ' ';
		}
		else if (temp == 'C')
		{
			this->SetBit(j, 0);
			this->SetBit(j + 1, 0);
			this->SetBit(j + 2, 1);
			this->SetBit(j + 3, 1);
			j = j + 4;
			temp = ' ';
		}
		else if (temp == 'D')
		{
			this->SetBit(j, 1);
			this->SetBit(j + 1, 0);
			this->SetBit(j + 2, 1);
			this->SetBit(j + 3, 1);
			j = j + 4;
			temp = ' ';
		}
		else if (temp == 'E')
		{
			this->SetBit(j, 0);
			this->SetBit(j + 1, 1);
			this->SetBit(j + 2, 1);
			this->SetBit(j + 3, 1);
			j = j + 4;
			temp = ' ';
		}
		else if (temp == 'F')
		{
			this->SetBit(j, 1);
			this->SetBit(j + 1, 1);
			this->SetBit(j + 2, 1);
			this->SetBit(j + 3, 1);
			j = j + 4;
			temp = ' ';
		}
	}
}

void QInt::BinToQInt(string a)
{
	int len = a.length();
	int j = 1;
	for (int i = len - 1; i >= 0; i--)
	{
		this->SetBit(j, (a[i] - 48));
		j++;
	}
}

void QInt::QIntToBin(string output)
{
	ostringstream convert;
	string result = "";
	int i = 128;
	for (; i > 0; i--)
	{
		if (this->GetBit(i) == 1)
			break;
	}
	if (i == 0)
	{
		convert << 0;
	}
	for (; i > 0; i--)
	{
		convert << this->GetBit(i);
	}
	result = convert.str();
	writeDataToFile(output, result);
}

void QInt::QIntToDec(string output)
{
	string result = "0";
	if (this->GetBit(128) == 1)
	{
		for (int i = 1; i < 128; i++)
		{
			if (this->GetBit(i) == 0)
			{
				result = AddStringDec(result, haimu[i - 1]);
			}
		}
		result = AddStringDec(result, "1");
		result.insert(0, "-");
	}
	else {
		for (int i = 1; i < 129; i++)
		{
			if (this->GetBit(i) == 1)
			{
				result = AddStringDec(result, haimu[i - 1]);
			}
		}
	}
	writeDataToFile(output, result);
}

void QInt::QIntToHex(string output)
{
	int i = 128;
	ostringstream convert, convert1;
	string result = "", temp = "";
	for (; i > 0; i--)
	{
		if (this->GetBit(i) == 1)
			break;
	}
	if (i == 0)
	{
		convert1 << 0;
	}
	while ((i % 4) != 0)
	{
		i = i++;
	}
	for (; i > 0; i = i - 4)
	{
		convert.str("");
		convert << this->GetBit(i);
		convert << this->GetBit(i - 1);
		convert << this->GetBit(i - 2);
		convert << this->GetBit(i - 3);
		temp = convert.str();
		if (temp == "0000")
		{
			convert1 << 0;
		}
		else if (temp == "0001")
		{
			convert1 << 1;
		}
		else if (temp == "0010")
		{
			convert1 << 2;
		}
		else if (temp == "0011")
		{
			convert1 << 3;
		}
		else if (temp == "0100")
		{
			convert1 << 4;
		}
		else if (temp == "0101")
		{
			convert1 << 5;
		}
		else if (temp == "0110")
		{
			convert1 << 6;
		}
		else if (temp == "0111")
		{
			convert1 << 7;
		}
		else if (temp == "1000")
		{
			convert1 << 8;
		}
		else if (temp == "1001")
		{
			convert1 << 9;
		}
		else if (temp == "1010")
		{
			convert1 << 'A';
		}
		else if (temp == "1011")
		{
			convert1 << 'B';
		}
		else if (temp == "1100")
		{
			convert1 << 'C';
		}
		else if (temp == "1101")
		{
			convert1 << 'D';
		}
		else if (temp == "1110")
		{
			convert1 << 'E';
		}
		else if (temp == "1111")
		{
			convert1 << 'F';
		}
		temp = "";

	}

	result = convert1.str();
	writeDataToFile(output, result);
}

void QInt::ror()
{
	int tmpBit, tmpBit2;
	tmpBit = this->GetBit(1);
	tmpBit2 = this->GetBit(65);
	this->arrayBits[1] = this->arrayBits[1] >> 1;
	this->arrayBits[0] = this->arrayBits[0] >> 1;
	this->SetBit(128, tmpBit);
	this->SetBit(64, tmpBit2);
}
void QInt::rol()
{
	int tmpBit1, tmpBit2;
	tmpBit1 = GetBit(128);
	tmpBit2 = GetBit(64);

	this->arrayBits[1] = this->arrayBits[1] << 1;
	this->SetBit(1, tmpBit1);

	this->arrayBits[0] = this->arrayBits[0] << 1;
	this->SetBit(65, tmpBit2);


}

QInt& QInt::operator+(const QInt& a) {
	QInt kq(0, 0);
	bool carry = false;
	for (int i = 1; i <= 128; i++) {
		bool i1 = this->GetBit(i);
		bool i2 = a.GetBit(i);
		kq.SetBit(i, Adder(i1, i2, carry));
	}
	//kq.updateCount();
	return kq;
}
QInt& QInt::operator-(const QInt& a) {
	QInt kq(0, 0);
	int n;
	bool borrow = false;
	for (int i = 1; i <= 128; i++) {
		bool x = this->GetBit(i);
		bool y = a.GetBit(i);
		if (borrow) {
			if (x) {
				kq.SetBit(i, y);
				borrow = y;
			}
			else {
				kq.SetBit(i, !y);
				borrow = true;
			}
		}
		else {
			if (x) {
				kq.SetBit(i, !y);
				borrow = false;
			}
			else {
				kq.SetBit(i, y);
				borrow = y;
			}
		}
	}
	return kq;
}
QInt& QInt::operator*(const QInt& a) {
	QInt kq(0, 0);
	for (int i = 1; i <= 128; i++) {
		if (this->GetBit(i)) {
			QInt tmp = a << (i - 1);
			kq = kq + tmp;
		}
	}
	return kq;
}
QInt& QInt::operator/(const QInt& a) {
	QInt A(0, 0);
	QInt Q = *this;
	QInt M = a;
	bool sosanh = Q.GetBit(128) ^ M.GetBit(128);
	if (Q.GetBit(128) == 1) {
		A = QInt(-1, -1);
	}
	for (int i = 128; i > 0; i--) {
		bool tmp = Q.GetBit(128);
		Q = Q << 1;
		A = A << 1;
		A.SetBit(1, tmp);
		if (M.GetBit(128) == 0)
		{
			A = A - M;
		}
		else
			A = A + M;
		if (A.GetBit(128) == 1) {
			Q.SetBit(1, 0);
			if (M.GetBit(128) == 0)
			{
				A = A + M;
			}
			else
				A = A - M;
		}
		else
			Q.SetBit(1, 1);
	}
	if (sosanh) {
		Q.Bu2();
	}
	return Q;
}

QInt& QInt::operator>>(int n)const {
	QInt tmp = *this;
	int dau = this->GetBit(128);
	for (int j = 0; j < n; j++)
	{
		for (int i = 1; i < 128; i++) {
			tmp.SetBit(i, tmp.GetBit(i + 1));
			tmp.SetBit(128, dau);
		}
	}
	return tmp;
}
QInt& QInt::operator<<(int n)const {
	QInt kq = *this;
	for (int j = 0; j < n; j++)
	{
		for (int i = 128; i > 1; i--) {
			kq.SetBit(i, kq.GetBit(i - 1));
		}
		kq.SetBit(1, 0);
	}
	return kq;
}

QInt& QInt::operator&(QInt& a)const {
	QInt kq(0, 0);
	kq.arrayBits[0] = this->arrayBits[0] & a.arrayBits[0];
	kq.arrayBits[1] = this->arrayBits[1] & a.arrayBits[1];
	return kq;
}
QInt& QInt::operator^(QInt& a)const {
	QInt kq(0, 0);
	kq.arrayBits[0] = this->arrayBits[0] ^ a.arrayBits[0];
	kq.arrayBits[1] = this->arrayBits[1] ^ a.arrayBits[1];
	return kq;
}
QInt& QInt::operator|(QInt& a)const {
	QInt kq(0, 0);
	kq.arrayBits[0] = this->arrayBits[0] | a.arrayBits[0];
	kq.arrayBits[1] = this->arrayBits[1] | a.arrayBits[1];
	return kq;
}
QInt& QInt::operator~()const {
	QInt kq = *this;
	for (int i = 1; i < 129; i++) {
		bool x = kq.GetBit(i);
		kq.SetBit(i, !x);
	}
	return kq;
}

size_t split(const std::string& txt, std::vector<std::string>& strs, char ch)
{
	size_t pos = txt.find(ch);
	size_t initialPos = 0;
	while (pos != std::string::npos) {
		strs.push_back(txt.substr(initialPos, pos - initialPos));
		initialPos = pos + 1;

		pos = txt.find(ch, initialPos);
	}


	strs.push_back(txt.substr(initialPos, std::min(pos, txt.size()) - initialPos + 1));
	return strs.size();
}

void handling(vector <string> stringVector, string output)
{

	QInt tmp1(0, 0), tmp2(0, 0), tmp(0, 0);

	if (stringVector.size() == 4)
	{
		if (stringVector[0] == "2")
		{
			tmp1.BinToQInt(stringVector[1]);
			tmp2.BinToQInt(stringVector[3]);
			if (stringVector[2] == "+")
			{
				tmp = tmp1 + tmp2;
				tmp.QIntToBin(output);
			}
			else if (stringVector[2] == "-")
			{
				tmp = tmp1 - tmp2;
				tmp.QIntToBin(output);
			}
			else if (stringVector[2] == "*")
			{
				tmp = tmp1 * tmp2;
				tmp.QIntToBin(output);

			}
			else if (stringVector[2] == "/")
			{
				tmp = tmp1 / tmp2;
				tmp.QIntToBin(output);

			}
			else if (stringVector[2] == "&")
			{
				tmp = tmp1 & tmp2;
				tmp.QIntToBin(output);

			}
			else if (stringVector[2] == "|")
			{
				tmp = tmp1 | tmp2;
				tmp.QIntToBin(output);

			}
			else if (stringVector[2] == "^")
			{
				tmp = tmp1 ^ tmp2;
				tmp.QIntToBin(output);

			}
			else if (stringVector[2] == ">>")
			{
				tmp = tmp1 >> stoi(stringVector[3]);
				tmp.QIntToBin(output);

			}
			else if (stringVector[2] == "<<")
			{
				tmp = tmp1 << stoi(stringVector[3]);
				tmp.QIntToBin(output);

			}


		}
		else if (stringVector[0] == "10")
		{
			tmp1.DecToQInt(stringVector[1]);
			tmp2.DecToQInt(stringVector[3]);
			if (stringVector[2] == "+")
			{
				tmp = tmp1 + tmp2;
				tmp.QIntToDec(output);

			}
			else if (stringVector[2] == "-")
			{
				tmp = tmp1 - tmp2;
				tmp.QIntToDec(output);

			}
			else if (stringVector[2] == "*")
			{
				tmp = tmp1 * tmp2;
				tmp.QIntToDec(output);

			}
			else if (stringVector[2] == "/")
			{
				tmp = tmp1 / tmp2;
				tmp.QIntToDec(output);

			}
			else if (stringVector[2] == "&")
			{
				tmp = tmp1 & tmp2;
				tmp.QIntToDec(output);

			}
			else if (stringVector[2] == "|")
			{
				tmp = tmp1 | tmp2;
				tmp.QIntToDec(output);

			}
			else if (stringVector[2] == "^")
			{
				tmp = tmp1 ^ tmp2;
				tmp.QIntToDec(output);

			}
			else if (stringVector[2] == ">>")
			{
				tmp = tmp1 >> stoi(stringVector[3]);
				tmp.QIntToDec(output);

			}
			else if (stringVector[2] == "<<")
			{
				tmp = tmp1 << stoi(stringVector[3]);
				tmp.QIntToDec(output);
			}
		}
		else if (stringVector[0] == "16")
		{
			tmp1.HexToQInt(stringVector[1]);
			tmp2.HexToQInt(stringVector[3]);
			if (stringVector[2] == "+")
			{
				tmp = tmp1 + tmp2;
				tmp.QIntToHex(output);
			}
			else if (stringVector[2] == "-")
			{
				tmp = tmp1 - tmp2;
				tmp.QIntToHex(output);

			}
			else if (stringVector[2] == "*")
			{
				tmp = tmp1 * tmp2;
				tmp.QIntToHex(output);

			}
			else if (stringVector[2] == "/")
			{
				tmp = tmp1 / tmp2;
				tmp.QIntToHex(output);

			}
			else if (stringVector[2] == "&")
			{
				tmp = tmp1 & tmp2;
				tmp.QIntToHex(output);

			}
			else if (stringVector[2] == "|")
			{
				tmp = tmp1 | tmp2;
				tmp.QIntToHex(output);

			}
			else if (stringVector[2] == "^")
			{
				tmp = tmp1 ^ tmp2;
				tmp.QIntToHex(output);

			}
			else if (stringVector[2] == ">>")
			{
				tmp = tmp1 >> stoi(stringVector[3]);
				tmp.QIntToHex(output);

			}
			else if (stringVector[2] == "<<")
			{
				tmp = tmp1 << stoi(stringVector[3]);
				tmp.QIntToHex(output);

			}
		}
	}
	if (stringVector.size() == 3)
	{
		if (stringVector[0] == "2")
		{
			tmp.BinToQInt(stringVector[2]);
			if (stringVector[1] == "ror")
			{
				tmp.ror();
				tmp.QIntToBin(output);

			}
			else if (stringVector[1] == "rol")
			{
				tmp.rol();
				tmp.QIntToBin(output);
			}
			else if (stringVector[1] == "~")
			{
				tmp = ~tmp;
				tmp.QIntToBin(output);
			}
			else
			{
				if (stringVector[1] == "2")
				{
					tmp.QIntToBin(output);

				}
				else if (stringVector[1] == "10")
				{
					tmp.QIntToDec(output);
				}
				else if (stringVector[1] == "16")
				{
					tmp.QIntToHex(output);
				}
			}

		}
		else if (stringVector[0] == "10")
		{
			tmp.DecToQInt(stringVector[2]);
			if (stringVector[1] == "ror")
			{
				tmp.ror();
				tmp.QIntToDec(output);

			}
			else if (stringVector[1] == "rol")
			{
				tmp.rol();
				tmp.QIntToDec(output);
			}
			else if (stringVector[1] == "~")
			{
				tmp = ~tmp;
				tmp.QIntToDec(output);
			}
			else
			{
				if (stringVector[1] == "2")
				{
					tmp.QIntToBin(output);
				}
				else if (stringVector[1] == "10")
				{
					tmp.QIntToDec(output);
				}
				else if (stringVector[1] == "16")
				{
					tmp.QIntToHex(output);

				}
			}

		}
		else if (stringVector[0] == "16")
		{
			tmp.HexToQInt(stringVector[2]);
			if (stringVector[1] == "ror")
			{
				tmp.ror();
				tmp.QIntToHex(output);

			}
			else if (stringVector[1] == "rol")
			{
				tmp.rol();
				tmp.QIntToHex(output);

			}
			else if (stringVector[1] == "~")
			{
				tmp = ~tmp;
				tmp.QIntToHex(output);
			}
			else
			{
				if (stringVector[1] == "2")
				{
					tmp.QIntToBin(output);
				}
				else if (stringVector[1] == "10")
				{
					tmp.QIntToDec(output);

				}
				else if (stringVector[1] == "16")
				{
					tmp.QIntToHex(output);
				}
			}
		}
	}
}

void readAndHandling(string input, string output)
{
	ifstream myfile;
	string line;
	vector <string> stringVector;
	myfile.open(input);

	if (!myfile.is_open()) {
		perror("Error open");
		exit(EXIT_FAILURE);
	}

	while (std::getline(myfile, line)) {
		split(line, stringVector, ' ');
		handling(stringVector, output);
		stringVector.clear();
	}

	myfile.close();
}

void main(int argc, char* argv[])
{
	string input = argv[1];
	string output = argv[2];
	readAndHandling(input, output);
}