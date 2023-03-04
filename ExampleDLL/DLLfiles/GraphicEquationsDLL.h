//GraphicEquationsDLL.h - contains declarations of polynomial line graphing equations

#pragma once
#ifdef GRAPHICEQUATIONSDLL_EXPORTS
#define GRAPHICEQUATIONSDLL_API __declspec(dllexport)
#else
#define GRAPHICEQUATIONSDLL_API __declspec(dllimport)
#endif
#include <tuple>
using namespace std;

extern "C" GRAPHICEQUATIONSDLL_API std::string LineType1(double px0, double py0, double px1, double py1);

extern "C" GRAPHICEQUATIONSDLL_API std::string LineType2(double px0, double py0, double px1, double py1, double px2, double py2);

extern "C" GRAPHICEQUATIONSDLL_API std::string LineType3(double px0, double py0, double xtp, double ytp);

extern "C" GRAPHICEQUATIONSDLL_API std::string LineType4(double px0, double py0, double px1, double py1, double px2, double py2, double px3, double py3);

extern "C" GRAPHICEQUATIONSDLL_API std::string LineType5(double px0, double py0, double xtp1, double ytp1, double xtp2, double ytp2);

extern "C" GRAPHICEQUATIONSDLL_API std::string LineType6(double px0, double py0, double xtp1, double ytp1, double xtp2, double ytp2, double xtp3, double ytp3);

extern "C" GRAPHICEQUATIONSDLL_API std::string LineType7(double px0, double py0, double px1, double py1, double px2, double py2, double px3, double py3);