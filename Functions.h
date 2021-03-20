#pragma once
#pragma warning(disable: 4996)

#include <windows.h>
#include <conio.h>
#include <vector>

using Points = std::vector<POINT>;

void CreateFigure(Points &);
bool CheckIntersectLines(POINT, POINT, POINT, POINT);
bool CheckIntersectFigures(Points &, Points &);