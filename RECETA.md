# Receta: Ticket de compra

<!-- Escribe aquí tus recetas en pseudocódigo, ANTES de programar.
     Primero la receta del programa principal (main) y después una receta corta para cada módulo que vas a escribir tú.
     El primer paso de main es solo un ejemplo del formato; el resto es tuyo.
     Si las corriges después de probarlas a mano, deja aquí la versión final. -->

## Receta del programa principal (`main`)

<!-- Debe leerse casi igual que tu árbol de análisis descendente (sección 6 del README). -->

```text
1. MOSTRAR "Bienvenido a mi programa"

2. PEDIR LOS DATOS
   2.1 nombre ← leerCadena("Nombre del producto: ")
       (leerCadena ya se encarga de que el nombre no quede vacío)

   2.2 precio ← leerDecimal("Precio: ")
       MIENTRAS precio <= 0 HACER
           MOSTRAR "El precio debe ser mayor que 0"
           precio ← leerDecimal("Precio: ")
       FIN MIENTRAS

   2.3 cantidad ← leerEntero("Cantidad: ")
       MIENTRAS cantidad <= 0 HACER
           MOSTRAR "La cantidad debe ser un numero entero mayor que 0"
           cantidad ← leerEntero("Cantidad: ")
       FIN MIENTRAS

   2.4 descuentoPorcentaje ← leerDecimal("Descuento (0 a 100): ")
       MIENTRAS descuentoPorcentaje < 0 O descuentoPorcentaje > 100 HACER
           MOSTRAR "El descuento debe estar entre 0 y 100"
           descuentoPorcentaje ← leerDecimal("Descuento (0 a 100): ")
       FIN MIENTRAS

3. CALCULAR LOS IMPORTES
   3.1 subtotal       ← calcularSubtotal(precio, cantidad)
   3.2 descuentoMonto ← calcularDescuento(subtotal, descuentoPorcentaje)
   3.3 baseIVA        ← subtotal - descuentoMonto
       (el IVA se cobra sobre lo que queda después del descuento)
   3.4 iva            ← calcularIVA(baseIVA)
   3.5 total          ← baseIVA + iva

4. IMPRIMIR EL TICKET
   LLAMAR imprimirTicket(nombre, precio, cantidad, subtotal,
                         descuentoMonto, iva, total)

5. TERMINAR el programa (return 0)

```

## Recetas de los módulos

<!-- Para cada módulo: qué recibe, qué hace y qué devuelve. -->

### `calcularIVA`

```text
MODULO calcularIVA(baseIVA)
     Recibe: el importe sobre el que se cobra el IVA (subtotal menos descuento)
     Hace: calcula el 16 % de ese importe
     Devuelve: cuántos pesos de IVA se cobran

    TASA_IVA ← 16        (constante: nunca cambia mientras corre el programa)
    iva ← baseIVA * TASA_IVA / 100
    DEVOLVER iva
FIN MODULO
```

### `imprimirTicket`

```text
MODULO imprimirTicket(nombre, precio, cantidad, subtotal, descuentoMonto, iva, total)
    Recibe: los datos del producto y los importes ya calculados
    Hace: muestra el ticket en pantalla, alineado
    Devuelve: nada (es un procedimiento, solo muestra texto)

    VENDEDOR ← "tu nombre"   (constante)
    ANCHO ← 36               (constante)

    PONER los números con 2 decimales
    MOSTRAR una línea de ANCHO signos "="
    MOSTRAR "TICKET DE COMPRA"
    MOSTRAR una línea de ANCHO signos "="
    MOSTRAR "Producto:",  nombre
    MOSTRAR "Precio:",    precio
    MOSTRAR "Cantidad:",  cantidad
    MOSTRAR una línea de ANCHO guiones "-"
    MOSTRAR "Subtotal:",  subtotal
    MOSTRAR "Descuento:", descuentoMonto
    MOSTRAR "IVA (16%):", iva
    MOSTRAR una línea de ANCHO guiones "-"
    MOSTRAR "TOTAL:",     total
    MOSTRAR una línea de ANCHO guiones "-"
    MOSTRAR "Le atendio:", VENDEDOR
    MOSTRAR una línea de ANCHO signos "="
FIN MODULO
```

### `calcularPorcentaje` (Fase 4)

```text
MODULO calcularPorcentaje(cantidad, porcentaje)
    Recibe: una cantidad de dinero y un porcentaje (10 significa 10 %)
    Hace: calcula esa parte de la cantidad
    Devuelve: el resultado en pesos
    Sirve para el descuento y para el IVA, porque los dos son
    "un porcentaje de algo"

    resultado ← cantidad * porcentaje / 100
    DEVOLVER resultado
FIN MODULO
```

### Otros módulos que agregues (por ejemplo, para tu reto)

```text

MODULO leerDecimalEnRango(mensaje, minimo, maximo)
     Recibe: el mensaje a mostrar y los límites válidos
     Hace: pide un número hasta que esté entre minimo y maximo
     Devuelve: ese número válido

    numero ← leerDecimal(mensaje)
    MIENTRAS numero < minimo O numero > maximo HACER
        MOSTRAR "Dato fuera de rango, intenta de nuevo"
        numero ← leerDecimal(mensaje)
    FIN MIENTRAS
    DEVOLVER numero
FIN MODULO

```
