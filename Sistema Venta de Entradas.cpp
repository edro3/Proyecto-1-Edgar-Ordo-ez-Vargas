#include <iostream>  // Entrada/salida (cout, cin)
#include <string>    // Uso de strings
#include <limits>    // std::numeric_limits
#include <iomanip>   // Formato de salida (decimales)
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


// Función para determinar si un número es primo (no usada en este programa, pero incluida previamente)
bool esPrimo(int numero) {
    if (numero <= 1) return false;
    for (int i = 2; i * i <= numero; ++i) {
        if (numero % i == 0) return false;
    }
    return true;
}

int main() {
    // Variables de estadísticas acumuladas
    int entradasGaleriaVendidas = 0;
    double dineroGaleriaGanado = 0.0;
    int entradasPalcoVendidas = 0;
    double dineroPalcoGanado = 0.0;
    int totalEntradasVendidas = 0;
    double totalDineroGanado = 0.0;
    double sumaTodosLosTotalesAPagar = 0.0;
    int cantidadDeVentasHechas = 0;

    int numeroFactura = 1; // Contador de factura
    char deseaContinuar = 'S'; // Control del ciclo de ventas

    // Bucle principal de ventas
    while (deseaContinuar == 'S' || deseaContinuar == 's') {
        std::cout << "\n=======================================================\n";
        std::cout << "      SISTEMA DE GESTION DE VENTAS DE ENTRADAS         \n";
        std::cout << "=======================================================\n";

        // Variables de la transacción actual
        std::string cedulaCliente;
        std::string nombreCliente;
        int tipoCliente;
        int tipoTiquete;
        int cantidadTiquetes;
        double montoUnitario = 0.0;
        double montoVenta = 0.0;
        double descuento = 0.0;
        double subtotal = 0.0;
        double impuestoVenta = 0.0;
        double totalAPagar = 0.0;

        // Solicitud y validación de datos
        std::cout << "Numero de Factura: " << numeroFactura << "\n";
        std::cout << "Ingrese la cedula del cliente: ";
        std::cin.ignore();
        std::getline(std::cin, cedulaCliente);

        std::cout << "Ingrese el nombre completo del cliente: ";
        std::getline(std::cin, nombreCliente);

        do {
            std::cout << "\nTipo de cliente (1=Nino o adulto mayor, 2=Adulto): ";
            while (!(std::cin >> tipoCliente)) {
                std::cout << "Entrada invalida. Ingrese 1 o 2: ";
                std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            if (tipoCliente < 1 || tipoCliente > 2) std::cout << "Opcion no valida. Elija 1 o 2.\n";
        } while (tipoCliente < 1 || tipoCliente > 2);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        do {
            std::cout << "\nTipo de tiquete (1=Galeria - C6000, 2=Palco - C12000): ";
            while (!(std::cin >> tipoTiquete)) {
                std::cout << "Entrada invalida. Ingrese 1 o 2: ";
                std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            if (tipoTiquete < 1 || tipoTiquete > 2) std::cout << "Opcion no valida. Elija 1 o 2.\n";
        } while (tipoTiquete < 1 || tipoTiquete > 2);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        do {
            std::cout << "Cantidad de tiquetes (minimo 1): ";
            while (!(std::cin >> cantidadTiquetes)) {
                std::cout << "Entrada invalida. Ingrese un numero positivo: ";
                std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            if (cantidadTiquetes <= 0) std::cout << "La cantidad debe ser al menos 1.\n";
        } while (cantidadTiquetes <= 0);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Cálculos de la transacción
        if (tipoTiquete == 1) { // Galería
            montoUnitario = 6000.0;
            entradasGaleriaVendidas += cantidadTiquetes;
        } else { // Palco
            montoUnitario = 12000.0;
            entradasPalcoVendidas += cantidadTiquetes;
        }
        montoVenta = cantidadTiquetes * montoUnitario;

        if (tipoCliente == 1) descuento = montoVenta * 0.30; // 30% descuento
        else descuento = 0.0;

        subtotal = montoVenta - descuento;
        impuestoVenta = subtotal * 0.13; // 13% impuesto
        totalAPagar = subtotal + impuestoVenta;

        // Actualización de estadísticas generales
        totalEntradasVendidas += cantidadTiquetes;
        totalDineroGanado += totalAPagar;
        sumaTodosLosTotalesAPagar += totalAPagar;
        cantidadDeVentasHechas++;

        // Presentación del recibo
        std::cout << "\n==========================================\n";
        std::cout << "      RECIBO DE COMPRA DE ENTRADAS        \n";
        std::cout << "==========================================\n";
        std::cout << "Numero de Factura: " << numeroFactura << "\n";
        std::cout << "Cedula Cliente: " << cedulaCliente << "\n";
        std::cout << "Nombre Cliente: " << nombreCliente << "\n";
        std::cout << "Tipo de Cliente: " << (tipoCliente == 1 ? "Nino o Adulto Mayor" : "Adulto") << "\n";
        std::cout << "Tipo de Tiquete: " << (tipoTiquete == 1 ? "Galeria" : "Palco") << "\n";
        std::cout << "Cantidad de Tiquetes: " << cantidadTiquetes << "\n";
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Monto Unitario: C" << montoUnitario << "\n";
        std::cout << "Monto de Venta: C" << montoVenta << "\n";
        std::cout << "Descuento: C" << descuento << "\n";
        std::cout << "Subtotal: C" << subtotal << "\n";
        std::cout << "Impuesto (13%): C" << impuestoVenta << "\n";
        std::cout << "TOTAL A PAGAR: C" << totalAPagar << "\n";
        std::cout << "==========================================\n";

        numeroFactura++; // Incrementa factura

        // Preguntar si desea continuar
        std::cout << "\n¿Desea registrar otra venta? (S para Si / N para No): ";
        std::cin >> deseaContinuar;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } // Fin del bucle de ventas

    // Cálculo y presentación de estadísticas finales
    double promedioGeneralVentas = 0.0;
    if (cantidadDeVentasHechas > 0) {
        promedioGeneralVentas = sumaTodosLosTotalesAPagar / cantidadDeVentasHechas;
    }

    std::cout << "\n\n=======================================================\n";
    std::cout << "         ESTADISTICAS FINALES DE VENTAS                \n";
    std::cout << "=======================================================\n";
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "\n--- Resumen de Tiquetes de Galeria ---\n";
    std::cout << "Cantidad de entradas Galeria: " << entradasGaleriaVendidas << " unidades.\n";
    std::cout << "Dinero total por Galeria: C" << dineroGaleriaGanado << ".\n";
    std::cout << "--------------------------------------------\n";

    std::cout << "\n--- Resumen de Tiquetes de Palco ---\n";
    std::cout << "Cantidad de entradas Palco: " << entradasPalcoVendidas << " unidades.\n";
    std::cout << "Dinero total por Palco: C" << dineroPalcoGanado << ".\n";
    std::cout << "--------------------------------------------\n";

    std::cout << "\n--- RESUMEN GENERAL DE TODAS LAS VENTAS ---\n";
    std::cout << "Cantidad General de Entradas: " << totalEntradasVendidas << " unidades.\n";
    std::cout << "Dinero General Total Recaudado: C" << totalDineroGanado << ".\n";
    std::cout << "Promedio General por Venta: C" << promedioGeneralVentas << ".\n";
    std::cout << "=======================================================\n";

    return 0; // Finalización exitosa del programa
}















