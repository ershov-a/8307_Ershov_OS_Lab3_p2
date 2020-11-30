#include <iostream>
#include <cmath>
#include <iomanip>
#include <chrono>

// Размер блока - 10*номерСтудБилета = 830704*10 = 8307040
#define BLOCK_SIZE 8307040

// Точность - 100000000 по заданию (количество итераций)
#define N 100000000

volatile double pi = 0;

void calculatePiOpenMP() {
    /*
     * Получаем количество потоков/
     * */
    int numberOfThreads;
    std::cout << "Enter number of threads" << std::endl;
    std::cin >> numberOfThreads;

    // Начинаем замерять время выполнения.
    auto start = std::chrono::high_resolution_clock::now();

    /*
     *  Директивы, говорящие что данный цикл нужно выполнять параллельно,
     *  распределяя итерации цикла между numberOfThreads числом потоков
     * */
    #pragma omp parallel for schedule(dynamic,BLOCK_SIZE) num_threads(numberOfThreads) reduction(+:pi) default(none)
    for (int i = 0; i < N; i++)
        pi += (4 / (1 + pow((0.5 + i) / N, 2)));

    // Досчитываем Пи
    pi = pi / N;

    // Заканчиванием замерять время выполнения.
    auto end = std::chrono::high_resolution_clock::now();
    // Подсчитываем затраченное время.
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    // Выводим результат и затраченное время.
    std::cout << "Pi = " << std::setprecision(N) << pi << std::endl
              << "Not all decimal digits are shown due to system limitations" << std::endl
              << "Time elapsed: " << time << " ms"
              << std::endl;
}

int main() {
    calculatePiOpenMP();
    system("pause");
    return 0;
}