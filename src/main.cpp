#include <iostream>
#include <string>

#include "utilerias.h"
#include "ticket.h"

int main() {
    std::string nombre = "";
    double precio = 0.0;
    int cantidad = 0;
    double descuentoPorcentaje = 0.0;
    double descuentoMonto = 0.0;
    double baseIV
    double iva = 0.0;
    double total = 0.0;

    std:: cout << "Bienvenido al ticket\n";

    nombre = leerCadena("Ingrese el nombre del producto: ");

    precio = leerDecimal("Precio: ");
        while (precio <=0){
            std::cout << "El precio debe ser mayor que 0\n";
            precio = leerDecimal("Precio: ");
        }

        cantidad = leerEntero ("Cantidad: ");
        while (cantidad<= 0) {
            std::cout << "la candidad debe ser mayor que 0\n";
            cantidad = leerEntero ("Cantidad: ");
        }

        descuentoPorcentaje = leerDecimal ("Descuento (0 a 100):") ;
        while (descuentoPorcentaje <0 || descuentoPorcentaje > 100) {
            std::cout << "el descuento debe estar entre 0 y 100\n";
            descuentoPorcentaje = leerDecimal ("Descuento (0 a 100):") ;

        }

        subtotal = calcularSubtotal(precio, cantidad);
        descuentoMonto = calcularDescuento(subtotal, descuentoPorcentaje);
        baseIVA = subtotal - descuentoMonto;
        iva = calcularIVA(baseIVA);
        total = baseIVA + iva;
        
    
    return 0;
}
