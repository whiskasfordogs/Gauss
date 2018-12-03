#include <iostream>
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


};

int main()
{
	TMacierz a(4);
	a.WczytajDane();
	std::cout << "Wczytano wyniki\n";
	a.WyswietlMacierz();
	a.Gauss_proste();
	std::cout << "Wyliczono macierz\n";
	a.WyswietlMacierz();
	a.Gauss_odwrotne();
	std::cout << "Wyliczono wyniki\n";
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
		for (int j = 0; j < _rozmiar + 1; j++) {
			std::cout << "Podaj w(" << i + 1 << ',' << j + 1 << "):";
			std::cin >> _m[i][j];
		}

}
void TMacierz::Gauss_proste() {
	double mianownik;
	double licznik;
	
	for (int k = 1; k < _rozmiar; k++) {
		for (int i = k; i < _rozmiar; i++) {
			for (int j = 0; j < _rozmiar + 1; j++)
				_m[i][j] -= (_m[i][k] / _m[k][k]) * _m[k][j];
		}
		
	}


}
void TMacierz::Gauss_odwrotne() {
	_x[_rozmiar] = (_m[_rozmiar + 1][_rozmiar] / _m[_rozmiar][_rozmiar]);
	int i;
	for (i = _rozmiar - 1; i >= 0; i--) {
		int j;
		for (j = _rozmiar; j > i; j--)
			_m[_rozmiar + 1][i] -= _m[j][i];
		_x[j] = (_m[_rozmiar + 1][i] / _m[j][i]);
	}
	
}

void TMacierz::WyswietlWyniki()
{
	std::cout << "wyniki:\n";
	for (int i = 0; i < _rozmiar; i++)
	{
		std::cout << "x" << i + 1 << " = " << _x[i] << '\n';
	}
}

void TMacierz::WyswietlMacierz()
{
	for (int i = 0; i < _rozmiar; i++) {
		for (int j = 0; j < _rozmiar+1; j++) {
			std::cout << _m[i][j] << ' ';
		}
		std::cout << '\n';
	}
}
