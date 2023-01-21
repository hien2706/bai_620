#include <iostream>
using namespace std;

struct DATE
{
	int d;
	int m;
	int y;
};
struct DAILY
{
	char code[5];
	char ten[30];
	int sdt;
	DATE ngay_tiep_nhan;
	char dia_chi[50];
	char e_mail[50];
};
bool kt_nam_nhuan(int year);
void input(DAILY& dl);
void input_ngay(DATE& date);
void output(DAILY dl);
int main() {
	DAILY dl{};
	input(dl);
	output(dl);
	return 0;
}
bool kt_nam_nhuan(int year)
{
	if (year % 400 == 0)
		return true;
	if (year % 4 == 0 && year % 100 != 0)
		return true;
	return false;
}
void input(DAILY& dl) {
	cout << "nhap ma dai ly(khong qua 4 ky tu): "; cin.getline(dl.code, 5);
	cout << "nhap ten: "; cin.getline(dl.ten, 30);
	cout << "nhap sdt: "; cin >> dl.sdt;
	cout << "nhap ngay: " << endl; input_ngay(dl.ngay_tiep_nhan);
	cout << "nhap dia chi: "; cin.ignore(); cin.getline(dl.dia_chi, 50);
	cout << "nhap email: "; cin.getline(dl.e_mail, 50);
}
void input_ngay(DATE& date)
{
	cout << "---------------------------" << endl;
	do {
		cout << "Nhap nam: "; cin >> date.y;
	} while (date.y < 0 && cout << "khong hop le, nhap lai" << endl);
	do
	{
		cout << "Nhap thang: "; cin >> date.m;
	} while (date.m < 1 || date.m > 12 && cout << "khong hop le, nhap lai" << endl);

	switch (date.m) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		do {
			cout << "Nhap ngay: "; cin >> date.d;

		} while (date.d < 1 || date.d > 31 && cout << "khong hop le, nhap lai" << endl);

		break;
	case 4:
	case 6:
	case 9:
	case 11:
		do {
			cout << "Nhap ngay: "; cin >> date.d;

		} while (date.d < 1 || date.d > 30 && cout << "khong hop le, nhap lai" << endl);
		break;
	case 2:
		if (kt_nam_nhuan(date.y))
		{
			do {
				cout << "Nhap ngay: "; cin >> date.d;

			} while (date.d < 1 || date.d > 29 && cout << "khong hop le, nhap lai" << endl);
		}
		else
		{
			do {
				cout << "Nhap ngay: "; cin >> date.d;

			} while (date.d < 1 || date.d > 28 && cout << "khong hop le, nhap lai" << endl);
		}
	}
	cout << "---------------------------" << endl;
}
void output(DAILY dl)
{
	cout << "ma dai ly:" << dl.code << endl;
	cout << "ten: " << dl.ten << endl;
	cout << "sdt: " << dl.sdt << endl;
	cout << "ngay: " << dl.ngay_tiep_nhan.d << "/" << dl.ngay_tiep_nhan.m << "/" << dl.ngay_tiep_nhan.y << endl;
	cout << "dia chi: " << dl.dia_chi << endl;
	cout << "email: " << dl.e_mail << endl;

}







