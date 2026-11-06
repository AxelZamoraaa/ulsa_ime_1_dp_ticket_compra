# Práctica: Ticket de compra

> Llena cada sección en la fase que se indica. Las instrucciones completas están en `PRACTICA.md`.
> Si una pregunta no aplica (por ejemplo, no hiciste el Experimento C o no tuviste dudas), escribe `No aplica`. Si te sobran filas en una tabla, bórralas.

## 1. Descripción del problema (Fase 1)

Es un programa en C++ que pide el nombre, el precio, la cantidad y el porcentaje de descuento de un producto. Con esos datos calcula el subtotal, el descuento, el IVA (16 %) y el total, y los muestra en forma de ticket. Serviría en una papelería o tienda para generar el ticket de una compra

## 2. Entradas y salidas (Fase 1)

**Entradas:**

| Entrada | Tipo de dato | Función de utilerias.h |
|---|---|---|
| Nombre del producto | std::string | leerCadena |
| Precio | double | leerDecimal |
| Cantidad | int | leerEntero |
| Descuento (%) | double | leerDecimal |

**Salida** (¿qué datos muestra el ticket?):
El nombre del producto, el precio, la cantidad, el subtotal, el descuento en pesos, el IVA (16 %), el total y la línea "Le atendio" con el nombre de quien atiende

**¿El IVA se calcula sobre el subtotal o sobre lo que queda después del descuento? ¿Por qué?**
Sobre lo que queda después del descuento (subtotal menos descuento). El descuento baja el precio de venta, y el IVA se cobra sobre lo que realmente se vende. Así coinciden los resultados esperados de la tabla de pruebas, por ejemplo 14.40 en el caso 2

## 3. Restricciones e invariante (Fases 1 y 2)

**Restricciones** (¿qué debe cumplirse?):

| Dato | ¿Qué valores son válidos? | ¿Por qué? |
|---|---|---|
| Nombre del producto | Texto no vacío; puede tener espacios | Un ticket sin nombre no identifica el producto. `leerCadena` ya revisa que no esté vacío |
| Precio | Número mayor que 0 | Un precio de 0 o negativo no tiene sentido en una venta |
| Cantidad | Entero mayor que 0 | No se pueden comprar 0, negativas ni medias piezas |
| Descuento (%) | De 0 a 100 | Menos de 0 sería un aumento, y más de 100 dejaría el total negativo |

**¿Qué hace mi programa si el usuario escribe un dato fuera de rango?**
Muestra un mensaje de error y vuelve a pedir el dato con un ciclo while. Lo repite hasta que el dato sea válido, y el programa no termina.

**¿Puede el total salir negativo? ¿Por qué?**
No. Como el descuento está entre 0 y 100 %, el descuento nunca es mayor que el subtotal, así que subtotal menos descuento es siempre 0 o más. El IVA tampoco es negativo, por lo que el total es 0 o más

**Invariante 1** (después del ciclo que valida el precio, ¿qué es siempre cierto sobre precio?):
Que `precio` es mayor que 0

**Invariante 2** (¿qué relación se cumple siempre entre el subtotal, el descuento, el IVA y el total?):
total = subtotal - descuento + IVA, donde el descuento está entre 0 y el subtotal, y el IVA es el 16 % de (subtotal - descuento)

## 4. Casos resueltos a mano (Fase 1)

| Caso | Nombre | Precio | Cantidad | Descuento (%) | Subtotal | Descuento ($) | IVA | Total |
|---|---|---|---|---|---|---|---|---|
| 1 (sin descuento) | Caja de colores | 25 | 4 | 0 | 100.00 | 0.00 | 16.00 | 116.00 |
| 2 (con descuento) | Cuaderno | 50 | 2 | 10 | 100.00 | 10.00 | 14.40 | 104.40 |
| 3 (precio con centavos) | Pluma | 19.99 | 1 | 0 | 19.99 | 0.00 | 3.20 | 23.19 |

## 5. Tipo de dato abstracto (Fase 1)

| TDA | Datos (¿qué tiene?) | Operaciones (¿qué se puede hacer con él?) |
|---|---|---|
| Producto | nombre (texto), precio (decimal), cantidad (entero) | calcular su subtotal |
| Ticket | producto, porcentaje de descuento, subtotal, descuento en pesos, IVA, total, nombre de quien atiende | calcular el descuento, calcular el IVA, calcular el total, imprimirse |

**Jerarquías:** una tienda vende productos por pieza (un cuaderno) y productos por peso (un kilo de tortillas). ¿Los dos son productos? ¿Qué datos tienen en común y cuál cambia?
Sí, los dos son productos. Tienen en común el nombre y el precio. Lo que cambia es la cantidad: por pieza es un número entero, y por peso es un decimal (por ejemplo 1.5 kilos), y además el precio es por pieza o por kilo.

## 6. Análisis descendente (Fase 2)

```
Generar ticket de compra
1. Mostrar bienvenida
2. Pedir los datos
    2.1 Pedir el nombre del producto (ya existe: leerCadena)
    2.2 Pedir el precio (y validar que sea mayor que 0) (ya existe: leerDecimal)    2.3 Pedir la cantidad (y validar que sea un entero mayor que 0) (ya existe: leerEntero)
    2.4 Pedir el descuento (y validar que esté entre 0 y 100) (ya existe: leerDecimal)
3. Calcular los importes
    3.1 Calcular el subtotal (ya existe: calcularSubtotal)
    3.2 Calcular el descuento (ya existe: calcularDescuento)
    3.3 Calcular la base del IVA (subtotal menos descuento)
    3.4 Calcular el IVA
    3.5 Calcular el total
 4. Imprimir el ticket
```

**Análisis ascendente: ¿qué partes del árbol ya estaban resueltas por una función que existe? ¿Cuáles?**
Pedir el nombre, el precio, la cantidad y el descuento ya estaban resueltos por leerCadena, leerDecimal y leerEntero de utilerias.h. Calcular el subtotal y el descuento ya estaban resueltos por calcularSubtotal y calcularDescuento de ticket.h

**¿Alguna parte del árbol hacía más de una cosa? ¿Cómo la dividiste?**
"Pedir los datos" hacía cuatro cosas, así que la dividí en pedir el nombre, el precio, la cantidad y el descuento. "Calcular el IVA" también hacía dos cosas (restar el descuento y sacar el 16 %), y la dividí en calcular la base del IVA y calcular el IVA

## 7. Módulos y receta (Fase 2)

| Módulo | ¿Qué recibe? | ¿Qué devuelve? | ¿Función o procedimiento? |
|---|---|---|---|
| calcularSubtotal | precio, cantidad | el subtotal | Función |
| calcularDescuento | subtotal, porcentaje | el monto del descuento | Función |
| calcularIVA | la base del IVA (subtotal menos descuento) | el monto del IVA | Función |
| imprimirTicket | nombre, precio, cantidad, subtotal, descuento, IVA, total | nada | Procedimiento |
| calcularPorcentaje | una cantidad y un porcentaje | esa parte de la cantidad | Función |

**¿Probé mi receta a mano con mis 3 casos?** Sí
**¿Tuve que corregirla? ¿Qué cambié?** No tuve que corregirla.

## 8. Cómo compilar y ejecutar (Fase 3)

Compilar (desde la carpeta del proyecto):

```bash
g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o ticket
```

Ejecutar en macOS:

```bash
./ticket
```

Ejecutar en Windows:

```bash
.\ticket.exe
```

**¿En qué sistema operativo trabajé?** Windows

## 9. Ejemplo de ejecución (Fase 3)

Bienvenido al ticket
Ingrese el nombre del producto: papel
Precio: 100
Cantidad: 2
Descuento del 0 al 1 (decimales ejemplo: 0.5 = 50%):0.2
====================================
TICKET DE COMPRA
====================================
Producto:   papel
Precio:     $100.00
Cantidad:   2
------------------------------------
Subtotal:   $200.00
Descuento:  $40.00
IVA (16%):  $25.60
------------------------------------
TOTAL:      $185.60
------------------------------------
Le atendio: Axel
====================================

## 10. De la receta al código (Fase 3)

| Paso de la receta | Módulo o instrucción de C++ que lo implementa |
|---|---|
| 1. Mensaje de bienvenida | std::cout << "Bienvenido al ticket\n"; en main |
| 2.1 Pedir el nombre | nombre = leerCadena(...) |
| 2.2 Pedir y validar el precio | leerDecimal(...) con while (precio <= 0) |
| 2.3 Pedir y validar la cantidad | leerEntero(...) con while (cantidad <= 0) |
| 2.4 Pedir y validar el descuento | leerDecimal(...) con while (descuentoPorcentaje < 0 \|\| descuentoPorcentaje > 100) |
| 3.1 Calcular el subtotal | calcularSubtotal(precio, cantidad) |
| 3.2 Calcular el descuento | calcularDescuento(subtotal, descuentoPorcentaje) |
| 3.3 Calcular la base del IVA | baseIVA = subtotal - descuentoMonto; |
| 3.4 Calcular el IVA | calcularIVA(baseIVA) |
| 3.5 Calcular el total | total = baseIVA + iva; |
| 4. Imprimir el ticket | imprimirTicket(...) |
| 5. Terminar el programa | return 0; |

**¿Hubo algún paso de mi receta que me costó traducir a C++? ¿Cuál y por qué?**
Más que traducir la receta, me costó escribir sin errores de sintaxis: me faltó un ;, escribí mal el nombre de una variable (desucentoMonto) y la constante TASA_IVA con espacio y dos puntos en lugar de =. Aprendí a leer el archivo y la línea que marca el compilador.

**Formato del ticket: ¿qué ancho usé en std::setw y por qué? ¿Qué pasa si uso un número menor que el largo de la etiqueta más larga?**
Usé 12. La etiqueta más larga es "Le atendio:" con 11 caracteres, y le sumo un espacio para separarla del valor. Si uso un número menor que 11, la etiqueta no cabe, ocupa más espacio del reservado y el valor queda pegado a ella y desalineado de las demás líneas

**¿Convertí el ancho de las líneas del ticket (36) en una constante? ¿Cómo la llamé? Si no, ¿por qué?**
Sí, la llamé ANCHO_TICKET. Así, si quiero cambiar el ancho, lo cambio en un solo lugar

## 11. Experimentos y depuración (Fase 3)

**Experimento A: depuración de calcularDescuento**

| Paso de depuración | Lo que hice o encontré |
|---|---|
| 1. Reproduce: ¿con qué datos falló? | Con precio 100, cantidad 2 y descuento 90 %. El ticket mostró un descuento de $18000.00 y un total negativo (-20648.00). Con 0 % no fallaba. |
| 2. Aísla: ¿qué valor intermedio estaba mal? (salidas [DEBUG]) | descuentoMonto salía como 18000 en lugar de 180. El subtotal (200) y el porcentaje (90) llegaban bien, así que el error estaba en calcularDescuento. |
| 3. Explica: ¿cuál era la causa? | La función multiplicaba el subtotal por el porcentaje (200 × 90) sin dividir entre 100. |
| 4. Corrige: ¿qué cambiaste? | Cambié la fórmula a subtotal * porcentaje / 100. |
| 5. Limpia: ¿comentaste tus salidas [DEBUG]? | no. |

**La prueba con 0 % pasó aunque la función tenía un error. ¿Qué me enseña eso sobre elegir mis casos de prueba?**
Con 0 % cualquier fórmula que multiplique da 0, así que el error no se notaba. Me enseña que debo probar con valores distintos de 0, valores normales (como 10 % o 90 %) y valores límite (100 %), y no solo el caso más fácil

**Experimento B: al cambiar el IVA a 8 %, ¿cuántas líneas tuve que cambiar? ¿Qué mejoraría?**
Cambié 1 línea: la constante TASA_IVA en ticket.h. Mejoraría hacer que el texto del ticket tome el porcentaje de la constante

**¿Mi ticket seguía diciendo IVA (16%)? ¿Qué hice al respecto?**
Sí, seguía diciendo IVA (16%) porque ese texto lo escribí a mano en imprimirTicket. La mejora sería construir la etiqueta usando TASA_IVA. Al terminar regresé la tasa a 16 %

**Experimento C (opcional): al cambiar el parámetro dentro de calcularIVA, ¿cambió la variable de main()? ¿Por qué?**
No lo hice

## 12. La constante "Le atendio" (Fase 3)

**¿Dónde definí la constante con mi nombre?** (marca una)
- [x] Constante local dentro de imprimirTicket
- [ ] Constante a nivel de la librería, en ticket.h
- [ ] Función que siempre devuelve la misma cadena

**¿Por qué elegí esa opción?**
Porque por ahora solo imprimirTicket usa el nombre, y así el dato queda en un solo lugar, junto a donde se usa, sin exponerlo al resto del programa

**¿Qué otras partes del programa podrían necesitar el nombre de quien atiende? (un mensaje de bienvenida, un ticket de devolución...)**
El mensaje de bienvenida, un ticket de devolución o un reporte de ventas del día

**Si mañana atiende otra persona, ¿en cuántos lugares tengo que cambiar el nombre?**
En 1 lugar: la constante dentro de imprimirTicket

**Si el nombre se leyera del teclado o de un archivo, ¿cuánto código tendría que cambiar con mi opción?**
Habría que cambiar imprimirTicket para que reciba el nombre como parámetro y también la llamada en main. Con una constante local no puedo cambiarlo sin tocar la función

## 13. Tabla de pruebas (Fase 4)

| # | Caso | Esperado (subtotal / descuento / IVA / total) | Obtenido | ¿Pasó? |
|---|---|---|---|---|
| 1 | Sin descuento | 100.00 / 0.00 / 16.00 / 116.00 | COMPLETAR | COMPLETAR |
| 2 | Con descuento | 100.00 / 10.00 / 14.40 / 104.40 | COMPLETAR | COMPLETAR |
| 3 | Descuento de 15 % | 600.00 / 90.00 / 81.60 / 591.60 | COMPLETAR | COMPLETAR |
| 4 | Precio con centavos | 19.99 / 0.00 / 3.20 / 23.19 | COMPLETAR | COMPLETAR |
| 5 | Descuento total | 90.00 / 90.00 / 0.00 / 0.00 | COMPLETAR | COMPLETAR |
| 6 | Precio inválido | vuelve a pedir el precio dos veces; 40.00 / 0.00 / 6.40 / 46.40 | COMPLETAR | COMPLETAR |
| 7 | Cantidad inválida | vuelve a pedir la cantidad dos veces; 20.00 / 0.00 / 3.20 / 23.20 | COMPLETAR | COMPLETAR |
| 8 | Descuento inválido | vuelve a pedir el descuento dos veces; 100.00 / 20.00 / 12.80 / 92.80 | COMPLETAR | COMPLETAR |
| 9 | Texto en el precio | vuelve a pedir el precio una vez; 100.00 / 0.00 / 16.00 / 116.00 | COMPLETAR | COMPLETAR |
| 10 | Nombre con espacios | muestra el nombre completo; 25.50 / 0.00 / 4.08 / 29.58 | COMPLETAR | COMPLETAR |
| 11 | Nombre vacío | vuelve a pedir el nombre una vez; 12.00 / 0.00 / 1.92 / 13.92 | COMPLETAR | COMPLETAR |
| 12 | Caso propio 1: Lápiz, precio 7.50, cantidad 10, descuento 20 % | 75.00 / 15.00 / 9.60 / 69.60 | COMPLETAR | COMPLETAR |
| 13 | Caso propio 2: Borrador, precio 3, cantidad 1, descuento 50 % | 3.00 / 1.50 / 0.24 / 1.74 | COMPLETAR | COMPLETAR |

**En el caso 4 el IVA real es 3.1984. ¿Por qué mi ticket muestra 3.20?**
Porque std::fixed y std::setprecision(2) redondean el número a dos decimales solo al mostrarlo. La variable sigue valiendo 3.1984

**En el caso 10, ¿el ticket siguió alineado? Si no, ¿qué corregí?**
Sí siguió alineado. El nombre del producto va al final de la línea, después de la etiqueta de 12 espacios, así que su largo no mueve las demás líneas

## 14. Generalización (Fase 4)

**¿Qué cálculo hacen calcularDescuento y calcularIVA? ¿Qué cambia entre una y otra?**
Las dos calculan un porcentaje de una cantidad: cantidad × porcentaje / 100. Solo cambian los datos: el descuento usa el subtotal y el porcentaje que escribe el usuario, y el IVA usa la base (subtotal menos descuento) y la tasa de 16 %. La operación es la misma

**Receta de calcularPorcentaje** (también va en RECETA.md):

```text
MODULO calcularPorcentaje(cantidad, porcentaje)
    // Recibe: una cantidad de dinero y un porcentaje (10 significa 10 %)
    // Hace: calcula esa parte de la cantidad
    // Devuelve: el resultado en pesos

    resultado  cantidad * porcentaje / 100
    DEVOLVER resultado
FIN MODULO
```

**¿Cómo quedaron el descuento y el IVA después del cambio?**
Los dos llaman a calcularPorcentaje. calcularDescuento devuelve calcularPorcentaje(subtotal, porcentaje) y calcularIVA devuelve calcularPorcentaje(baseIVA, TASA_IVA). La fórmula quedó escrita en un solo lugar

**¿Volví a correr toda la tabla de pruebas después del cambio? ¿Todo siguió pasando?**
Si, volví a correr los 13 casos y todo siguió pasando

**¿Agregué calcularPorcentaje a mi tabla de módulos (sección 7)?** Si

**¿En qué otro programa podría reutilizar calcularPorcentaje?**
En un programa que calcule propinas, comisiones de ventas o el porcentaje de batería de un robot

## 15. Revisión de calidad (Fase 4)

| Principio | Pregunta | ¿Lo cumple? | Evidencia |
|---|---|---|---|
| Correcto | ¿Pasa todas las pruebas de la tabla? | Sí | Los 13 casos de la sección 13 dan lo esperado |
| Robusto | ¿Resiste datos inválidos sin fallar ni terminar? | Sí | Los ciclos while vuelven a pedir el dato, y las funciones de utilerias.h rechazan texto |
| Legible | ¿Otra persona entiende tu código sin que se lo expliques? | Sí | Nombres claros de variables y funciones, y comentarios de lo que recibe y devuelve cada función |
| Modular | ¿Cada función hace una sola cosa? | Sí | Las funciones de cálculo solo calculan y imprimirTicket solo imprime |
| Sin números mágicos | ¿Los valores fijos tienen nombre? | Sí | TASA_IVA, ANCHO_TICKET y VENDEDOR |
| Fácil de mantener | Si cambia el IVA o quien atiende, ¿cuántas líneas cambias? | Sí | 1 línea para el IVA (TASA_IVA) y 1 línea para quien atiende (VENDEDOR) |
| Reutilizable | ¿Alguna de tus funciones serviría en otro programa? | Sí | calcularPorcentaje y calcularSubtotal |

## 16. Reto obligatorio (Fase 4)

**¿Qué reto elegí?** tener que poner del 0 al 1 para los descuentos, con punto decimal

**¿Por qué lo elegí?**
porque estaba facil

**¿Cómo lo resolví? ¿Qué módulos agregué o cambié?**
solo defini que el usuario pusiera del 0 al 1 porque no funcionaba del 0 al 100

**¿Hice algún otro reto opcional? ¿Cuál?**
Ninguno

## 17. Bitácora de mejoras (Fase 4)

| # | ¿Qué falló o qué quise mejorar? | ¿Qué cambié? | ¿Funcionó? |
|---|---|---|---|
| 1 | Con descuentos mayores que 0, el descuento salía enorme y el total negativo | Corregí calcularDescuento para dividir entre 100 | Sí |
| 2 | Errores de compilación por errores de escritura (TASA_ IVA: 16.0 y desucentoMonto) | Corregí la constante a TASA_IVA = 16.0 y el nombre de la variable | Sí, el programa compiló |

## 18. Dudas para el profesor (Fase 3)

| Duda | Lo que ya intenté |
|---|---|
| No  | No  |

## 19. Reflexión final

**¿Qué aprendí con esta práctica?**
Aprendí a dividir un programa en módulos pequeños, cada uno con una sola tarea, y a validar datos con ciclos while, también aprendí a leer los mensajes del compilador y a depurar paso por paso en lugar de adivinar

**Ahora que terminé, ¿qué cambiaría de mi proceso?**
Probaría desde el principio con descuentos distintos de 0 y revisaría con más cuidado lo que escribo antes de compilar, para evitar errores de escritura

**¿Qué fue lo más difícil y cómo lo resolví?**
Lo más difícil fueron los errores de compilación, porque uno solo generaba varios mensajes. Lo resolví corrigiendo siempre el primer error de la lista y revisando el archivo y la línea que indicaba el compilador

**¿Qué pregunta me quedó sin responder?**
¿Cómo se pueden agrupar los siete parámetros de imprimirTicket para no pasarlos uno por uno? Entiendo que se verá en la Unidad VII

**Comparado con las prácticas anteriores, donde todo estaba en main(), ¿dividir el programa en módulos me facilitó o me complicó el trabajo? ¿Por qué?**
Me facilitó el trabajo. Cuando el total salió mal, el subtotal estaba bien, y eso me dijo que el error estaba en calcularDescuento y no en el resto. Cada módulo se puede probar por separado

**¿Cómo encontré el error de calcularDescuento? ¿Lo habría encontrado si solo hubiera probado sin descuento?**
Lo encontré probando con 90 % de descuento: el descuento salió como $18000.00, y con una salida [DEBUG] vi que el valor ya estaba mal al salir de la función. Si solo hubiera probado sin descuento no lo habría encontrado, porque con 0 % el resultado es correcto aunque la fórmula esté mal

## 20. Commits (Fase 5)

**¿Cuántos commits hice durante la práctica?** 
15

**Si hice menos de 3, ¿por qué?**
No

## 21. Lista de verificación antes de entregar (Fase 5)

- [x] Llené las secciones 1 a 20 (no quedan `_____`; escribí `No aplica` donde corresponde)
- [x] Completé el árbol de análisis descendente y la tabla de módulos
- [x] Escribí en `RECETA.md` la receta de `main` y la de cada módulo, antes de programar
- [x] Cada bloque de `main.cpp` tiene su comentario `// Paso N`, de acuerdo con mi receta
- [x] Corregí el error de `calcularDescuento` y documenté cómo lo encontré
- [x] Hice los Experimentos A y B y dejé el código correcto al terminar
- [x] Mi ticket se ve alineado y termina con la línea "Le atendio:", leída de una constante
- [x] Justifiqué dónde definí la constante con mi nombre
- [x] Escribí `calcularPorcentaje` y volví a correr todas las pruebas
- [x] Hice al menos uno de los retos y lo documenté
- [x] No queda ninguna salida `[DEBUG]` activa
- [x] Mi programa compila sin advertencias
- [x] Probé todos los casos de la tabla
- [x] Revisé los principios de calidad de mi programa
- [x] No modifiqué `utilerias.h`
- [x] Tengo al menos 3 commits con mensajes claros (o justifiqué por qué no)
- [x] Hice `git push` y verifiqué mi fork en GitHub
- [x] Mi fork se llama `ulsa_ime_1_dp_ticket_compra`, mis módulos están en `include/ticket.h` y mi programa principal en `src/main.cpp`
- [x] Entregué el enlace de mi fork en Classroom
