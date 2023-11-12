
#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>

int main()
{
	std::vector <double> Hc;

	int eps = 100;
	for (int i{ 0 }; i <= 60000; i += eps) {
		Hc.push_back(i);
	}

	double R0 = 6371;
	double grav = 398600.4;
	double Vc;

	
	std::ofstream fout;

	try {
		fout.open("Hc_Vc.txt");
		for (auto& HIGH : Hc) {
			Vc = sqrt((grav / (R0 + HIGH)));
			fout << HIGH << "\t" << Vc << std::endl;
		}
		std::cout << "Data was succesfully written.";
		fout.close();
		return 0;
	}
	
	catch (std::exception& ex) {
		std::cout << "File opening error!";
		fout.close();
		return 0;
	}

}

