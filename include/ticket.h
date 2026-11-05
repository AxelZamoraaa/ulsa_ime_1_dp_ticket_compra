#pragma once

#include <iostream>
#include <string>
#include <iomanip>

const double TASA_IVA = 16.0;

inline double calcularSubtotal(double precio, int cantidad) {
    return precio * cantidad;
}

inline double calcularDescuento(double subtotal, double porcentaje) {
    return subtotal * porcentaje;
}


inline double calcularIVA(double base) {
    return base * (TASA_IVA / 100.0);
}

inline void imprimirTicket (std:: string nombre, double precio, int cantidad, double subtotal, double descuentoMonto, double iva, double total) {
    
    const int ANCHO_TICKET = 36;
    const std::string VENDEDOR = "Axel";

    std::cout << std::fixed << std::setprecision(2) << std::left;

    std::cout << std::string(ANCHO_TICKET, '=') << "\n";
    std::cout << "TICKET DE COMPRA\n";
    std::cout << std::string(ANCHO_TICKET, '=') << "\n";
    std::cout << std::setw(12) << "Producto:" << nombre << "\n";
    std::cout << std::setw(12) << "Precio:" << "$" << precio << "\n";
    std::cout << std::setw(12) << "Cantidad:" << cantidad << "\n";
    std::cout << std::string(ANCHO_TICKET, '-') << "\n";
    std::cout << std::setw(12) << "Subtotal:" << "$" << subtotal << "\n";
    std::cout << std::setw(12) << "Descuento:" << "$" << descuentoMonto << "\n";
    std::cout << std::setw(12) << "IVA (16%):" << "$" << iva << "\n";
    std::cout << std::string(ANCHO_TICKET, '-') << "\n";
    std::cout << std::setw(12) << "TOTAL:" << "$" << total << "\n";
    std::cout << std::string(ANCHO_TICKET, '-') << "\n";
    std::cout << std::setw(12) << "Le atendio:" << VENDEDOR << "\n";
    std::cout << std::string(ANCHO_TICKET, '=') << "\n";
}