# figures
:hammer_and_wrench:Check intersection of figures 
# Результат работы:
![1](https://user-images.githubusercontent.com/17510024/111867736-fab94180-8986-11eb-8fa2-ce0733974e39.jpg)
## Немного о ![CheckIntersectLines](https://github.com/AlekseyShashkov/figures/blob/main/Functions.cpp)
- Находим определитель:
    ```c++
    determinant = (_Point4.y - _Point3.y) * (_Point1.x - _Point2.x)
                - (_Point4.x - _Point3.x) * (_Point1.y - _Point2.y);
    ```
- Определитель равный 0 указывает на то, что отрезки располагаются на параллельных прямых или, в частном случае, на одной и той же прямой. Если отрезки расположены на одной прямой, то проверяем лежит ли вершина одного отрезка на другом. Если лежит - отрезки пересекаются, если нет- не пересекаются: 
    ```c++
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
    ```
- Если определитель не равен 0, применяем метод Крамера:
    ```c++
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
    ```
