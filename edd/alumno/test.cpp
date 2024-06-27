#include <iostream>
#include <chrono>
//18.1687 endl
//17.3946 \n
/*
0.0031461 segundos
0.0114786 segundos

0.0185653 segundos
0.0263625 segundos

0.195365 segundos
0.179812 segundos
*/
int main() {
    // Usando std::endl
    int n=10;
    auto start_endline = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; ++i) {
        std::cout << "Linea " << i << std::endl;
    }
    auto end_endline = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds_endline = end_endline - start_endline;
    std::cout << "Tiempo usando std::endl: " << elapsed_seconds_endline.count() << " segundos\n";
    system("pause");
    // Usando '\n'
    auto start_newline = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; ++i) {
        std::cout << "Linea " << i << '\n';
    }
    auto end_newline = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds_newline = end_newline - start_newline;
    std::cout << "Tiempo usando '\\n': " << elapsed_seconds_newline.count() << " segundos\n";

    return 0;
}
