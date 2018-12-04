#include <iostream>
#include <iomanip>
class TMacierz
{
private:
	double **_m;
	double *_x;
	int _rozmiar;
public:
	TMacierz(int rozmiar);
	~TMacierz();
	void WczytajDane();
	void Gauss_proste();
	void Gauss_odwrotne();
	void WyswietlWyniki();
	void WyswietlMacierz();
	void test();


};

int main()
{	
	std::cout << "Podaj rozmiar macierzy (bez wektora): ";
	int rozmiar;
	std::cin >> rozmiar;
	TMacierz a(rozmiar);
	a.WczytajDane();
	//do uzywania testu trzeba ustawic rozmiar na 4
	//a.test();
	//std::cout << "Wczytano wyniki\n";
	//a.WyswietlMacierz();
	a.Gauss_proste();
	//std::cout << "Wyliczono macierz\n";
	//a.WyswietlMacierz();
	a.Gauss_odwrotne();
	//std::cout << "Wyliczono wyniki\n";
	a.WyswietlWyniki();
	return 0;
}


TMacierz::TMacierz(int rozmiar) : _rozmiar(rozmiar) {
	_m = new double*[_rozmiar];
	for (int i = 0; i < _rozmiar; i++) {
		_m[i] = new double[_rozmiar + 1];
	}
	_x = new double[_rozmiar];
}
TMacierz::~TMacierz() {
	delete[] _m;
	delete[] _x;
}

void TMacierz::WczytajDane() {
	for (int i = 0; i < _rozmiar; i++)
		for (int j = 0; j < _rozmiar; j++) {
			std::cout << "Podaj w(" << i + 1 << ',' << j + 1 << "):";
			std::cin >> _m[i][j];
		}
	std::cout << "Podaj wektor: \n";
	for (int i = 0; i < _rozmiar; i++) {
		std::cout << "Podaj w(" << i << ',' << _rozmiar << "):";
		std::cin >> _m[i][_rozmiar];
	}

}
void TMacierz::Gauss_proste() {
	double mianownik;
	double licznik;
	
	for (int k = 0; k < _rozmiar-1; k++) {
		mianownik = _m[k][k];
		for (int i = k+1; i < _rozmiar; i++) {
			licznik = _m[i][k];
			for (int j = 0; j < _rozmiar + 1; j++) {
				_m[i][j] -= _m[k][j] * (licznik / mianownik);
			}
		}
		
	}


}
void TMacierz::Gauss_odwrotne() {
	_x[_rozmiar-1] = (_m[_rozmiar-1][_rozmiar] / _m[_rozmiar-1][_rozmiar-1]);

	for (int i = _rozmiar - 2; i >= 0; i--) {
		int j;
		for (j = _rozmiar-1; j > i; j--) {
			_m[i][_rozmiar] -= _m[i][j] * _x[j];
		}
		_x[i] = _m[i][_rozmiar] / _m[i][j];
	}
	
	
}

void TMacierz::WyswietlWyniki()
{
	std::cout << "wyniki:\n";
	std::cout << "x = [";
	for (int i = 0; i < _rozmiar; i++)
	{
		std::cout  << _x[i] << ' ';
	}
	std::cout << "]\n";
}

void TMacierz::WyswietlMacierz()
{
	for (int i = 0; i < _rozmiar; i++) {
		for (int j = 0; j < _rozmiar+1; j++) {
			std::cout << std::setw(5) << _m[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

void TMacierz::test()
{
	_m[0][0] = 2;
	_m[0][1] = 4;
	_m[0][2] = 2;
	_m[0][3] = 0;
	_m[0][4] = 4;
	_m[1][0] = 1;
	_m[1][1] = 0;
	_m[1][2] = -1;
	_m[1][3] = 1;
	_m[1][4] = 2;
	_m[2][0] = 0;
	_m[2][1] = 1;
	_m[2][2] = 3;
	_m[2][3] = -1;
	_m[2][4] = 0;
	_m[3][0] = 2;
	_m[3][1] = 1;
	_m[3][2] = 2;
	_m[3][3] = 1;
	_m[3][4] = 6;

}
