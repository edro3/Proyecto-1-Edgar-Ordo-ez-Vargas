#include <iostream> // Para la entrada y salida de datos
#include <string>   // Para usar cadenas de texto (como 'S' o 'N')
#include <limits>   // Para el manejo de errores en la entrada de datos

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// Función para verificar si un número es primo
bool esPrimo(int numero) {
    if (numero <= 1) {
        return false;
    }
    for (int i = 2; i * i <= numero; ++i) {
        if (numero % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv) { // Este es el esqueleto de main que proporcionaste
    // --- Variables para las estadísticas generales ---
    int numeroMayorIngresado = 0;
    int posicionNumeroMayor = 0;
    int contadorNumerosIngresados = 0;

    int cantidadPrimos = 0;
    long long sumatoriaPrimos = 0;
    double promedioPrimos = 0.0;

    int cantidadNoPrimos = 0;
    long long sumatoriaNoPrimos = 0;
    double promedioNoPrimos = 0.0;

    char quiereContinuar = 'S';

    // --- Bucle principal: Leer N números hasta que el usuario desee salir ---
    while (quiereContinuar == 'S' || quiereContinuar == 's') {
        std::cout << "\n============================================\n";
        std::cout << "      ANALIZADOR DE NUMEROS PRIMOS         \n";
        std::cout << "============================================\n";

        int numeroIngresado;
        contadorNumerosIngresados++;

        std::cout << "Por favor, ingresa el numero entero #" << contadorNumerosIngresados << ": ";
        while (!(std::cin >> numeroIngresado)) {
            std::cout << "Entrada invalida. Por favor, ingresa un numero entero: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (esPrimo(numeroIngresado)) {
            std::cout << "-> El numero " << numeroIngresado << " ES un Numero Primo.\n";
            cantidadPrimos++;
            sumatoriaPrimos += numeroIngresado;
        } else {
            std::cout << "-> El numero " << numeroIngresado << " NO ES un Numero Primo.\n";
            cantidadNoPrimos++;
            sumatoriaNoPrimos += numeroIngresado;
        }

        if (contadorNumerosIngresados == 1 || numeroIngresado > numeroMayorIngresado) {
            numeroMayorIngresado = numeroIngresado;
            posicionNumeroMayor = contadorNumerosIngresados;
        }

        std::cout << "\n¿Deseas ingresar otro numero? (S para Si / N para No): ";
        std::cin >> quiereContinuar;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } // --- Fin del bucle principal ---

    // --- Calcular promedios (manejar división por cero) ---
    if (cantidadPrimos > 0) {
        promedioPrimos = static_cast<double>(sumatoriaPrimos) / cantidadPrimos;
    }
    if (cantidadNoPrimos > 0) {
        promedioNoPrimos = static_cast<double>(sumatoriaNoPrimos) / cantidadNoPrimos;
    }

    // --- Mostrar estadísticas finales ---
    std::cout << "\n\n============================================\n";
    std::cout << "         ESTADISTICAS FINALES               \n";
    std::cout << "============================================\n";

    std::cout << "\n--- Resumen de Todos los Numeros ---\n";
    std::cout << "Numero Mayor Ingresado: " << numeroMayorIngresado
              << " en la posicion " << posicionNumeroMayor << ".\n";
    std::cout << "--------------------------------------------\n";

    std::cout << "\n--- Estadisticas de Numeros Primos ---\n";
    std::cout << "Cantidad de Numeros Primos: " << cantidadPrimos << ".\n";
    std::cout << "Sumatoria de Numeros Primos: " << sumatoriaPrimos << ".\n";
    std::cout << "Promedio de Numeros Primos: " << promedioPrimos << ".\n";
    std::cout << "--------------------------------------------\n";

    std::cout << "\n--- Estadisticas de Numeros NO Primos ---\n";
    std::cout << "Cantidad de Numeros NO Primos: " << cantidadNoPrimos << ".\n";
    std::cout << "Sumatoria de Numeros NO Primos: " << sumatoriaNoPrimos << ".\n";
    std::cout << "Promedio de Numeros NO Primos: " << promedioNoPrimos << ".\n";
    std::cout << "============================================\n";

	return 0; // Este return 0 es el que estaba en el esqueleto.
}
