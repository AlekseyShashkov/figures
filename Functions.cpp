#include "Functions.h"

void CreateFigure(Points &_Figure)
{
    POINT buffPoint;
    char c;

    while (true) {
        scanf("%d", &buffPoint.x);
        scanf("%d", &buffPoint.y);
        _Figure.push_back(buffPoint);

        printf("Press 'n' to stop input or other button for continue:\n");
        c = getch();
        if (c != 'n') {
            printf("Enter vertices of figure:\n");
        } else {
            break;
        }
    }
}

bool CheckIntersectLines(POINT _Point1, POINT _Point2,
                        POINT _Point3, POINT _Point4)
{
    double parameterU, parameterV;
    double numeratorParamU, numeratorParamV;
    double determinant;

    determinant = (_Point4.y - _Point3.y) * (_Point1.x - _Point2.x)
                - (_Point4.x - _Point3.x) * (_Point1.y - _Point2.y);

    if (determinant == 0) {
        bool isFirstEquation = (_Point1.x * _Point2.y - _Point2.x * _Point1.y)
            * (_Point4.x - _Point3.x)
            - (_Point3.x * _Point4.y - _Point4.x * _Point3.y)
            * (_Point2.x - _Point1.x) == 0;
        bool isSecondEquation = (_Point1.x * _Point2.y - _Point2.x * _Point1.y)
            *(_Point4.y - _Point3.y)
            - (_Point3.x * _Point4.y - _Point4.x * _Point3.y)
            * (_Point2.y - _Point1.y) == 0;

        if (isFirstEquation && isSecondEquation) {
            return true;
        } else {
            return false;
        }

    } else {
        numeratorParamU = (_Point4.x - _Point2.x) * (_Point4.y - _Point3.y)
            - (_Point4.x - _Point3.x) * (_Point4.y - _Point2.y);
        numeratorParamV = (_Point1.x - _Point2.x) * (_Point4.y - _Point2.y)
            - (_Point4.x - _Point2.x) * (_Point1.y - _Point2.y);
        parameterU = numeratorParamU / determinant;
        parameterV = numeratorParamV / determinant;

        bool inLimitationU = parameterU >= 0 && parameterU <= 1;
        bool inLimitationV = parameterV >= 0 && parameterV <= 1;

        if (inLimitationU && inLimitationV) {
            return true;
        } else {
            return false;
        }
    }
}

bool CheckIntersectFigures(Points &_FirstFigure, Points &_SecondFigure)
{
    for (size_t i = 0; i < _FirstFigure.size(); ++i)
    {
        for (size_t ii = i + 1; ii < _FirstFigure.size(); ++ii)
        {
            for (size_t j = 0; j < _SecondFigure.size(); ++j)
            {
                for (size_t jj = j + 1; jj < _SecondFigure.size(); ++jj)
                {
                    if (CheckIntersectLines(_FirstFigure[i], _FirstFigure[ii],
                                        _SecondFigure[j], _SecondFigure[jj])) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}