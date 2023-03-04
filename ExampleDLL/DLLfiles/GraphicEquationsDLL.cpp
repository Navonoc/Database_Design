#include "pch.h"
#include <iostream>
#include <string>
#include <cmath>
#include "GraphicEquationsDLL.h"
using namespace std;

//neil scholthorpe - soft eng



std::string LineType1(double px0, double py0, double px1, double py1) //y = mx+c from 2 standard points
{
	// to return M = Gradient & C = Constant
	double M = (py1 - py0) / (px1 - px0);
	double C = (py0 - M * px0);
	std::string grad = std::to_string(M);
	std::string constant = std::to_string(C);
	string s = "Gradient M: " + grad + "Constant C: " + constant;
	return s;
}

std::string LineType2(double px0, double py0, double px1, double py1, double px2, double py2) // y = Ax^2 + Bx + C from 3 standard points
{
	// to return A = x^2 coefficent / B = x coefficient / C = constant
	// R is the ratio used internally
	double R = (px0 - px1)/(px2 - px1);
	double A = (((py0 - py1) - ((py2 - py1) * R)) / (((px0 * px0) - (px1 * px1)) - (((px2 * px2) - (px1 * px1)) * R)));
	double B = ((py0 - py1) - A * ((px0 * px0) - (px1 * px1))) / (px0 - px1);
	double C = (py0 - A * (px0 * px0) - B * (px0));
	std::string Astr = std::to_string(A);
	std::string Bstr = std::to_string(B);
	std::string Cstr = std::to_string(C);
	std::string Rstr = std::to_string(R);
	string s = " R value: " + Rstr + " X^2 coefficient: " + Astr + "X coefficient: " + Bstr + "constant: " + Cstr;
	return s;
}
std::string LineType3(double px0, double py0, double xtp, double ytp) // y = Ax^2 + Bx + C from 1 standard point and 1 turning point
{
	double ATop = py0 - ytp;
	double ABot = ((pow(px0,2)-pow(xtp,2)) - 2 * xtp * (px0 - xtp));

	double A = ATop / ABot;

	double B = -2*A*xtp;

	double C = py0 - ((A*pow(px0,2)) + (B*px0));

	std::string Astr = std::to_string(A);
	std::string Bstr = std::to_string(B);
	std::string Cstr = std::to_string(C);
	string s = " X^2 coefficient: " + Astr + " X coefficient: " + Bstr + " constant: " + Cstr;
	return s;
}

std::string LineType4(double px0, double py0, double px1, double py1, double px2, double py2, double px3, double py3) // y = Ax^3 + Bx^2 + Cx + D from 4 standard points
{
	double R1 = (px2 - px0) / (px1 - px0);
	double R2 = (px3 - px0) / (px1 - px0);

	double R3Top = (pow(px3, 2) - pow(px0, 2)) - R2 * (pow(px1, 2) - pow(px0, 2));
	double R3Bot = (pow(px2, 2) - pow(px0, 2)) - R1 * (pow(px1, 2) - pow(px0, 2));
	double R3 = R3Top / R3Bot;

	//split A into 4 vars
	double ATL = ((py3 - py0) - R2 * (py1 - py0));
	double ATR = R3 * ((py2 - py0) - R1 * (py1 - py0));
	double ABL = ((pow(px3, 3) - pow(px0, 3)) - R2 * (pow(px1, 3) - pow(px0, 3)));
	double ABR = R3 * ((pow(px2, 3) - pow(px0, 3)) - R1 * (pow(px1, 3) - pow(px0, 3)));

	double A = (ATL - ATR) / (ABL - ABR);

	double B = (((py2 - py0) - R1 * (py1 - py0)) - A * ((pow(px2, 3) - pow(px0, 3)) - R1 * (pow(px1, 3) - pow(px0, 3)))) / ((pow(px2, 2) - pow(px0, 2)) - R1 * (pow(px1, 2) - pow(px0, 2)));

	double C = ((py1 - py0) - (A * (pow(px1, 3) - pow(px0, 3)) + B * (pow(px1, 2) - pow(px0, 2)))) / (px1 - px0);

	double D = py0 - (A * pow(px0, 3) + B * pow(px0, 2) + C * px0);

	std::string Astr = std::to_string(A);
	std::string Bstr = std::to_string(B);
	std::string Cstr = std::to_string(C);
	std::string Dstr = std::to_string(D);
	string s = " A value: " + Astr + " B value: " + Bstr + " C value: " + Cstr + " D value: " + Dstr;
	return s;
}

std::string LineType5(double px0, double py0, double xtp1, double ytp1, double xtp2, double ytp2) // y = Ax^3 + Bx^2 + Cx + D from 1 standard point and 2 turning points
{
	double R1 = (xtp1 - px0) / (xtp2 - px0);
	std::cout <<(std::to_string(R1));
	std::cout << endl;
	double ATop = ((ytp1 - py0) - (R1 * (ytp2 - py0)));
	std::cout << (std::to_string(ATop));
	std::cout << endl;
	double AMid = ((pow(xtp1, 3) - pow(px0, 3)) - R1 * (pow(xtp2, 3) - pow(px0, 3)));
	std::cout << (std::to_string(AMid));
	std::cout << endl;
	double ALowTop = 3.0f * (pow(xtp1,2)-pow(xtp2, 2)) * ((pow(xtp1,2)-pow(px0,2)) - R1*(pow(xtp2,2)-pow(px0,2)));
	std::cout << (std::to_string(ALowTop));
	std::cout << endl;
	double ALowBot = 2.0f * (xtp1 - xtp2);
	std::cout << (std::to_string(ALowBot));
	std::cout << endl;

	double A = ATop / (AMid - (ALowTop / ALowBot));
	std::cout << (std::to_string(A));
	std::cout << endl;
	double BTop = -3 * A * (pow(xtp1, 2) - pow(xtp2, 2));

	double BBot = 2 * (xtp1 - xtp2);

	double B = BTop / BBot;

	double C = (-3.0f * A * pow(xtp1, 2)) - (2 * B * xtp1);

	double D = py0 - A * (pow(px0, 3)) - B * (pow(px0, 2)) - C * px0;

	std::string Astr = std::to_string(A);
	std::string Bstr = std::to_string(B);
	std::string Cstr = std::to_string(C);
	std::string Dstr = std::to_string(D);
	string s = " A value: " + Astr + " B value: " + Bstr + " C value: " + Cstr + " D value: " + Dstr;
	return s;
}

std::string LineType6(double px0, double py0, double xtp1, double ytp1, double xtp2, double ytp2, double xtp3, double ytp3) // y = Ax^4 + Bx^3 + Cx^2 + Dx + E from 1 standard point and 3 turning points
{
	double R1 = (xtp2 - px0) / (xtp1 - px0);
	double R2 = (xtp3 - px0) / (xtp1 - px0);

	double R3Top = (pow(xtp3, 2) - pow(px0, 2)) - R2 * (pow(xtp1, 2) - pow(px0, 2));
	double R3Bot = (pow(xtp2, 2) - pow(px0, 2)) - R1 * (pow(xtp1, 2) - pow(px0, 2));
	double R3 = R3Top / R3Bot;

	double R4 = (xtp3 - xtp1) / (xtp2 - xtp1);

	double BaTop = -4 * ((pow(xtp3, 3) - pow(xtp1, 3)) - R4 * (pow(xtp2, 3) - pow(xtp1, 3)));
	double BaBot = 3 * ((pow(xtp3, 2) - pow(xtp1, 2)) - R4 * (pow(xtp2, 2) - pow(xtp1, 2)));
	double Ba = BaTop / BaBot;

	double ATop = ((ytp3 - py0) - R2 * (ytp1 - py0)) - R3 * ((ytp2 - py0) - R1 * (ytp1 - py0));
	double ABot1stTerm = (((pow(xtp3, 4) - pow(px0, 4)) - R2 * (pow(xtp1, 4) - pow(px0, 4))) - R3 * ((pow(xtp2, 4) - pow(px0, 4)) - R1 * (pow(xtp1, 4) - pow(px0, 4))));
	double ABot2ndTerm = Ba * (((pow(xtp3, 3) - pow(px0, 3)) - R2 * (pow(xtp1, 3) - pow(px0, 3))) - R3 * ((pow(xtp2, 3) - pow(px0, 3)) - R1 * (pow(xtp1, 3) - pow(px0, 3))));

	double A = ATop / (ABot1stTerm + ABot2ndTerm);

	double B = A*Ba;

	double C =  (-4 * A * (pow(xtp2, 3) - pow(xtp1, 3)) -3 * B * (pow(xtp2, 2) - pow(xtp1, 2)))/(2*(xtp2-xtp1));

	double D = -(4 * A * pow(xtp1, 3) + 3 * B * pow(xtp1, 2) + 2 * C * xtp1);

	double E = py0 - (A * pow(px0, 4) + B * pow(px0, 3) + C * pow(px0, 2) + D * px0);

	std::string Astr = std::to_string(A);
	std::string Bstr = std::to_string(B);
	std::string Cstr = std::to_string(C);
	std::string Dstr = std::to_string(D);
	std::string Estr = std::to_string(E);
	string s = " A value: " + Astr + " B value: " + Bstr + " C value: " + Cstr + " D value: " + Dstr + " E value: " + Estr;
	return s;
}

