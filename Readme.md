# Лабораторные по МПО

В этом репозитории находятся исходники на языке C++ 11. В программе реализован
подсчет среднего значения в массиве заданного размера 
последовательным алгоритмом сдваивания.

* rss.hpp, profiled.hpp - реализация подсчета времени и использованной памяти,
вам в этом копаться не надо;
* logic.hpp - там функции генерации массива (вида 0 1 2 3 ... ARRAY_SIZE-1),
проверки с контрольным значением (например, для проверки среднего значения у массива
используется известная формула среднего значения для арифметической прогрессии),
а также собственно "честный" подсчет среднего значения - это место вам и предстоит менять.
* main.cpp - принимает аргументами программы количество повторений и размер массива.
Ну и вызывает все функции из logic.hpp.

Для выполнения лабораторки собираем код и вызываем получившийся бинарь с двумя аргументами:
количество повторений и размер массива.
Например, при помощи gcc это будет выглядеть так:

    $ g++ -std=c++11 main.cpp -o lab
    $ ./lab 10 20000000
    Time elapsed:	885ms
    RSS:		305M

