#include <iostream>
using namespace std;

class bidangDatar {
private:
	int x, y; // variabel untuk menyimpan input dari lingkaran dan persegi panjang
public:
	bidangDatar() { //constructor
		x = 0;
		y = 0;
	}

	virtual void input() {} //Fungsi yang menerima dan mengirim input melalui fungsi setX untuk disimpan di X
	virtual float Luas(int a) { return 0; } //Fungsi untuk menghitung luas
	virtual float Keliling(int a) { return 0; } //Fungsi untuk menghitung keliling
	virtual void cekUkuran() { } //Fungsi untuk mengecek dari nilai yang sudah diinput

	void setX(int a) { //fungsi untuk memberi/mengirim nilai pada X
		this->x = a;
	}
	void setY(int b) {
		this->y = b;
	}
	int getX() { //fungsi untuk membaca/mengambil nilai dalam X
		return x;
	}
	int getY() {
		return y;
	}
};

class Lingkaran :public bidangDatar {
public:
	void input() {
		cout << "Lingkaran dibuat" << endl;
		cout << "Masukkan jejari : ";
		int r;
		cin >> r;
		setX(r);
	}
	float Luas(int r) {
		return 3.14 * r * r;
	}
	float Keliling(int r) {
		return 2 * 3.14 * r;
	}

	void cekUkuran() {
		float keliling = Keliling(getX());
		if (keliling > 40)
			cout << "Ukuran lingkaran adalah Besar" << endl;
		else if (keliling < 20)
			cout << "Ukuran lingkaran adalah Sedang" << endl;
		else if (keliling < 10)
			cout << "Ukuran lingkaran adalah Kecil" << endl;
	}

};

class Persegipanjang :public bidangDatar {
public:
	void input() {
		cout << "Persegipanjang dibuat" << endl;
		cout << "Masukkan panjang : ";
		int p;
		cin >> p;
		cout << "Masukkan lebar : ";
		int l;
		cin >> l;
		setX(p);
		setY(l);
	}
	float Luas(int p) {
		return p * getY();
	}
	float Keliling(int p) {
		return 2 * (p + getY());
	}

	void cekUkuran() {
		float keliling = Keliling(getX());
		if (keliling > 40)
			cout << "Ukuran Persegi Panjang adalah Besar" << endl;
		else if (keliling < 20)
			cout << "Ukuran Persegi Panjang adalah Sedang" << endl;
		else if (keliling < 10)
			cout << "Ukuran Persegi Panjang adalah Kecil" << endl;
	}
};
int main() {
	char repeat;
	do {
		Lingkaran lingkaran;
		lingkaran.input();
		int r = lingkaran.getX();
		cout << "Luas Lingkaran = " << lingkaran.Luas(r) << endl;
		cout << "Keliling Lingkaran = " << lingkaran.Keliling(r) << endl;
		lingkaran.cekUkuran();

		Persegipanjang persegi;
		persegi.input();
		int p = persegi.getX();
		cout << "Luas Persegipanjang = " << persegi.Luas(p) << endl;
		cout << "Keliling Persegipanjang = " << persegi.Keliling(p) << endl;
		persegi.cekUkuran();

		cout << "Apakah Anda ingin mengulang program? (Y/N): ";
		cin >> repeat;
	} while (repeat == 'Y' || repeat == 'y');

	return 0;}