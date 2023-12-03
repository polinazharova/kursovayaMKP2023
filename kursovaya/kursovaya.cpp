#include <iostream>
#include <math.h>
#include <fstream>

#define PI 3.14159265359

int main()
{
	double R0 = 6378.1; //ekvatorial'niy radius Earth
	double grav = 398600.4415;
	double Vc, Vi;


	std::ofstream fout;

	try {
		fout.open("Hc_Vc.txt");
	}
	catch (std::exception& ex) {
		std::cout << "File opening error!";
		fout.close();
		return 0;
	}


	for (double Hc{ 0 }; Hc <= 60000; Hc += 100) {

		Vc = sqrt((grav / (R0 + Hc)));
		Vi = Vc / cos(PI/4);
		std::cout << Vi << std::endl;
		fout << Hc << "\t" << Vc;
		fout << "\t" << Vi << std::endl;

	}

	std::cout << "Data was succesfully written.";


	fout.close();
	return 0;

}

