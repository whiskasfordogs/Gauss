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


};

int main()
{
	TMacierz a(4);
	a.WczytajDane();
	a.Gauss_proste();
	a.Gauss_odwrotne();
	a.WyswietlWyniki();
	return 0;
}


TMacierz::TMacierz(int rozmiar) : _rozmiar(rozmiar) {
	_m = new double*[_rozmiar + 1];
	for (int i = 0; i < _rozmiar + 1; i++) {
		_m[i] = new double[_rozmiar];
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
	double podstawa;
	for (int i = 0; i < _rozmiar; i++) {
		podstawa = _m[i][i];

		if (podstawa != 0) {
			for (int j = i + 1; j < _rozmiar; j++) {
				for (int k = 0; k < _rozmiar + 1; k++)
					_m[j][k] -= _m[j - 1][k] * (_m[j][k] / _m[j - 1][k]);
			}

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
