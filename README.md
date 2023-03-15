# eccentricity_for_every_vertex


Ищет эксцентриситеты вершин на основе алгоритма DFS. 
запуск:

Клонирование репозитория
git clone https://github.com/elizabetinka/eccentricity_for_every_vertex

building on Linux or Mac:
make eccentricity

Запуск
./eccentricity [inputFile]

Формат файла(список смежности):

Вначале количество строк(вершин).Каждая следующая строка имееет структуру:

x y n a_1 a_2 ... a_n

Где  x-это номер вершины, у - второе название для вершины(может быть числом), n - количество вершин, смежнных с данной, далее n чисел через пробел -- номера смежных вершин.

Пример:

10
0 Armenia 2 16 45
1 Albania 4 17 22 30 32
2 Andorra 2 14 42
3 Austria 8 10 15 18 21 24 40 41 44
4 Belarus 5 23 25 34 37 46
5 Belgium 4 14 15 26 31
6 Herzegovina 3 8 30 39
7 Bulgaria 5 17 32 36 39 45
8 Croatia 5 6 18 30 39 41
9 Cyprus 0

