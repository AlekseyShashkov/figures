#include "Functions.h"

int main()
{
    std::vector<POINT> firstFigure;
    std::vector<POINT> secondFigure;

    printf("----- Enter vertices of first figure:\n");
    CreateFigure(firstFigure);

    printf("\n----- Enter vertices of second figure:\n");
    CreateFigure(secondFigure);

    if (CheckIntersectFigures(firstFigure, secondFigure)) {
        printf("\n----- Figures are intersect! -----\n");
    } else {
        printf("\n----- Figures are not intersect! -----\n");
    }

    firstFigure.clear();
    secondFigure.clear();

    return 0;
}