#pragma once
#include<iostream>
#include<limits>
#include<math.h>
#include<sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;
class QInt {
private:
	long long arrayBits[2];
	int memory;
	int count;

public:
	//Constructor
	QInt()
	{
		this->arrayBits[1] = 0;
		this->arrayBits[0] = 0;
		this->memory = 0;
		this->count = 0;
	}
	QInt(long long i1, long long i2) {
		arrayBits[0] = i1;
		arrayBits[1] = i2;
		this->memory = 0;
		count = 0;
		(i1 != 0) ? count += (int)log2(i1) + 1 : count;
		(i2 != 0) ? count += (int)log2(i2) + 1 : count;
	}
	//Destructor
	~QInt() {};

	static bool Adder(bool i1, bool i2, bool& carry) {
		bool sum = (i1 ^ i2) ^ carry;
		carry = (i1 && i2) || (i1 && carry) || (i2 && carry);
		return sum;
	}//Add bit
	static bool Subtract(bool i1, bool i2, bool& borrow) {
		bool diff;
		if (borrow) {
			diff = !(i1 ^ i2);
			borrow = !i1 || (i1 && i2);
		}
		else {
			diff = i1 ^ i2;
			borrow = !i1 && i2;
		}
		return diff;
	}//Sub bit

	void Bu2(); //Số bù hai
	bool GetBit(int i)const; //Lấy bit ở vị trí i
	void SetBit(int i, bool bit);//Set giá trị cho bit tại vị trí i

	void DecToQInt(string a);//Chuyển từ 10->QInt
	void HexToQInt(string a);//Chuyển từ 16->QInt
	void BinToQInt(string a);//Chuyển từ 2->QInt
	void QIntToDec(string ouput);//Chuyển từ QInt->10 và xuất ra file.txt
	void QIntToHex(string ouput);//Chuyển từ QInt->16 và xuất ra file.txt
	void QIntToBin(string ouput);//Chuyển từ QInt->2 và xuất ra file.txt

	void ror();//Xoay phải
	void rol();//Xoay trái

	QInt& operator&(QInt& a) const;//AND
	QInt& operator^(QInt& a) const;//XOR
	QInt& operator|(QInt& a) const;//OR
	QInt& operator~() const;//NOT

	QInt& operator+(const QInt&);
	QInt& operator-(const QInt&);
	QInt& operator*(const QInt&);
	QInt& operator/(const QInt&);

	QInt& operator>>(int n)const;//Dịch phải
	QInt& operator<<(int n)const;//Dịch trái

	bool operator>=(const QInt& a) {
		for (int i = 128; i >= 1; i--) {
			bool x = this->GetBit(i);
			bool y = a.GetBit(i);
			if (x != y) {
				return x;
			}
		}
		return true;
	}

	void updateCount() {
		count = 0;
		long long tmp = arrayBits[0];
		while (tmp != 0) {
			count++;
			tmp >>= 1;
		}
		tmp = arrayBits[1];
		while (tmp != 0) {
			count++;
			tmp >>= 1;
		}
	}
	int get_count() const {
		return count;
	}
};

void handling(vector <string> stringVector, string output);//Hàm chạy từng dòng và xuất kết quả 

void readAndHandling(string input, string output);//Hàm đọc file input và xuất kết quả ra output

size_t split(const std::string& txt, std::vector<std::string>& strs, char ch);//Hàm tách từng chuỗi ký tự trong một dòng

string Div2(string a);//Hàm chia 2 chuỗi thập phân

void writeDataToFile(string file, string data);//Hàm in ra output

string AddStringDec(string a, string b);//Hàm cộng chuỗi thập phân

string haimu[128] = {
	"1",
	"2",
	"4",
	"8",
	"16",
	"32",
	"64",
	"128",
	"256",
	"512",
	"1024",
	"2048",
	"4096",
	"8192",
	"16384",
	"32768",
	"65536",
	"131072",
	"262144",
	"524288",
	"1048576",
	"2097152",
	"4194304",
	"8388608",
	"16777216",
	"33554432",
	"67108864",
	"134217728",
	"268435456",
	"536870912",
	"1073741824",
	"2147483648",
	"4294967296",
	"8589934592",
	"17179869184",
	"34359738368",
	"68719476736‬",
	"137438953472‬",
	"274877906944‬",
	"549755813888‬",
	"1099511627776",
	"2199023255552‬",
	"4398046511104‬",
	"8796093022208‬",
	"17592186044416",
	"‭35184372088832‬",
	"70368744177664‬",
	"‭140737488355328‬",
	"‭281474976710656‬",
	"‭562949953421312‬",
	"‭1125899906842624‬",
	"‭2251799813685248‬",
	"‭4503599627370496‬",
	"‭9007199254740992‬",
	"‭18014398509481984‬",
	"‭36028797018963968‬",
	"‭72057594037927936‬",
	"‭144115188075855872‬",
	"‭288230376151711744‬",
	"‭576460752303423488‬",
	"‭1152921504606846976‬",
	"‭2305843009213693952‬",
	"‭4611686018427387904‬",
	"‭9223372036854775808‬",
	"‭18446744073709551616‬",
	"‭36893488147419103232‬",
	"‭73786976294838206464‬",
	"‭147573952589676412928‬",
	"‭295147905179352825856‬",
	"‭590295810358705651712‬",
	"‭1180591620717411303424‬",
	"‭2361183241434822606848‬",
	"‭4722366482869645213696‬",
	"‭9444732965739290427392‬",
	"‭18889465931478580854784‬",
	"‭37778931862957161709568‬",
	"‭75557863725914323419136‬",
	"‭151115727451828646838272‬",
	"‭302231454903657293676544‬",
	"‭604462909807314587353088‬",
	"‭1208925819614629174706176‬",
	"‭2417851639229258349412352‬",
	"‭4835703278458516698824704‬",
	"‭9671406556917033397649408‬",
	"‭19342813113834066795298816‬",
	"‭38685626227668133590597632‬",
	"‭77371252455336267181195264‬",
	"‭154742504910672534362390528‬",
	"‭309485009821345068724781056‬",
	"‭618970019642690137449562112‬",
	"‭1237940039285380274899124224‬",
	"‭2475880078570760549798248448‬",
	"‭4951760157141521099596496896‬",
	"‭9903520314283042199192993792‬",
	"‭19807040628566084398385987584‬",
	"‭39614081257132168796771975168‬",
	"‭79228162514264337593543950336‬",
	"‭158456325028528675187087900672‬",
	"‭316912650057057350374175801344‬",
	"‭633825300114114700748351602688‬",
	"‭1267650600228229401496703205376‬",
	"‭2535301200456458802993406410752‬",
	"‭5070602400912917605986812821504‬",
	"‭10141204801825835211973625643008‬",
	"‭20282409603651670423947251286016‬",
	"‭40564819207303340847894502572032‬",
	"81129638414606681695789005144064‬",
	"162259276829213363391578010288128",
	"324518553658426726783156020576256",
	"649037107316853453566312041152512",
	"1298074214633706907132624082305024",
	"2596148429267413814265248164610048",
	"5192296858534827628530496329220096",
	"10384593717069655257060992658440192",
	"20769187434139310514121985316880384",
	"41538374868278621028243970633760768",
	"83076749736557242056487941267521536",
	"166153499473114484112975882535043072",
	"332306998946228968225951765070086144",
	"664613997892457936451903530140172288",
	"1329227995784915872903807060280344576",
	"2658455991569831745807614120560689152",
	"5316911983139663491615228241121378304",
	"10633823966279326983230456482242756608‬",
	"21267647932558653966460912964485513216‬",
	"‭‭42535295865117307932921825928971026432‬",
	"‭‭85070591730234615865843651857942052864‬",
	"‭170141183460469231731687303715884105728‬",
}; //Mảng lũy thừa của 2 (từ 0->127)