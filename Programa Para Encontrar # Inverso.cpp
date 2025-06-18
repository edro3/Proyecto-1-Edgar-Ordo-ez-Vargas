#include <iostream> // Para hablar con la pantalla (cout) y el teclado (cin)
#include <limits>   // Para limpiar la entrada si hay un error

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
    // Variables para el número y su inverso
    int numeroOriginal = 0;
    int numeroInverso = 0;
    int digito; // Para guardar cada número que saco

    // Pedir el número (solo hasta 5 dígitos)
    do {
        std::cout << "Dame un numero entero (maximo 5 digitos, o sea, hasta 99999): ";
        // Validar que sea un numero
        while (!(std::cin >> numeroOriginal)) {
            std::cout << "¡No es un numero! Ingresa uno: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        // Validar que este en el rango correcto
        if (numeroOriginal < 0 || numeroOriginal > 99999) {
            std::cout << "Ese numero no sirve. Debe ser entre 0 y 99999.\n";
        }
    } while (numeroOriginal < 0 || numeroOriginal > 99999);

    // Para invertir el numero matematicamente
    int tempNumero = numeroOriginal; // Copio el numero para no perderlo

    while (tempNumero > 0) {
        digito = tempNumero % 10;        // Saco el ultimo digito (el "resto" de dividir entre 10)
        numeroInverso = numeroInverso * 10 + digito; // Pego el digito al inverso
        tempNumero = tempNumero / 10;    // Quito el ultimo digito del numero original
    }

    // Mostrar los resultados
    std::cout << "\nEl numero que ingresaste es: " << numeroOriginal << "\n";
    std::cout << "El numero al reves es: " << numeroInverso << "\n";

    return 0; // Termino el programa
}

