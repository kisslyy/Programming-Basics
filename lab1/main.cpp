#include <iostream>

using namespace std;

int main()
{
	bool Bool = true;

	short Short = 0;
	char Char = '0';
	long Long = 43;
	long long LongLong = -432;
	int Int = 645;


	unsigned short UnsignedShort = 0;
	unsigned char UnsignedChar = '0';
	unsigned long UnsignedLong = 43;
	unsigned long long UnsignedLongLong = -432;
	unsigned int UnsignedInt = 645;

	double Double = 45.435;
	float Float = 2144.13f;

	cout << "1)" << endl;
	cout << "type: bool, " << "size: " << sizeof Bool << " byte(s), " << "current value: " << Bool << ", " << "min value: " << numeric_limits<bool>::min() << ", " << "max value: " << numeric_limits<bool>::max() << "." << endl;

	cout << "type: short, " << "size: " << sizeof Short << " byte(s), " << "current value: " << Short << ", " << "min value: " << SHRT_MIN << ", " << "max value: " << SHRT_MAX << "." << endl;
	cout << "type: char, " << "size: " << sizeof Char << " byte(s), " << "current value: " << Char << ", " << "min value: " << CHAR_MIN << ", " << "max value: " << CHAR_MAX << "." << endl;
	cout << "type: long, " << "size: " << sizeof Long << " byte(s), " << "current value: " << Long << ", " << "min value: " << LONG_MIN << ", " << "max value: " << LONG_MAX << "." << endl;
	cout << "type: long long, " << "size: " << sizeof LongLong << " byte(s), " << "current value: " << LongLong << ", " << "min value: " << LLONG_MIN << ", " << "max value: " << LLONG_MAX << "." << endl;
	cout << "type: int, " << "size: " << sizeof Int << " byte(s), " << "current value: " << Int << ", " << "min value: " << INT_MIN << ", " << "max value: " << INT_MAX << "." << endl;

	cout << "type: unsigned short, " << "size: " << sizeof UnsignedShort << " byte(s), " << "current value: " << UnsignedShort << ", " << "min value: " << 0 << ", " << "max value: " << USHRT_MAX << "." << endl;
	cout << "type: unsigned char, " << "size: " << sizeof UnsignedChar << " byte(s), " << "current value: " << UnsignedChar << ", " << "min value: " << 0 << ", " << "max value: " << UCHAR_MAX << "." << endl;
	cout << "type: unsigned long, " << "size: " << sizeof UnsignedLong << " byte(s), " << "current value: " << UnsignedLong << ", " << "min value: " << 0 << ", " << "max value: " << ULONG_MAX << "." << endl;
	cout << "type: unsigned long long, " << "size: " << sizeof UnsignedLongLong << " byte(s), " << "current value: " << UnsignedLongLong << ", " << "min value: " << 0 << ", " << "max value: " << ULLONG_MAX << "." << endl;
	cout << "type: unsigned int, " << "size: " << sizeof UnsignedInt << " byte(s), " << "current value: " << UnsignedInt << ", " << "min value: " << 0 << ", " << "max value: " << UINT_MAX << "." << endl;

	cout << "type: double, " << "size: " << sizeof Double << " byte(s), " << "current value: " << Double << ", " << "min value: " << numeric_limits<double>::lowest()  << ", " << "max value: " << numeric_limits<double>::max() << "." << endl;
	cout << "type: float, " << "size: " << sizeof Float << " byte(s), " << "current value: " << Float << ", " << "min value: " << numeric_limits<float>::lowest() << ", " << "max value: " << numeric_limits<float>::max() << "." << endl;


	cout << "2)" << endl;
	int ChromosomesCount = 46;
	cout << "Chromosomes Count = " << ChromosomesCount << endl;
	ChromosomesCount++;
	cout << "Chromosomes Count = " << ChromosomesCount << endl;
}