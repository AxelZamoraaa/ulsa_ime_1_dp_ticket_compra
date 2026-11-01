# Práctica: Ticket de compra

> **Nota importante: escribe tu código sin ayuda de IA.**
> Te sugerimos **no usar inteligencia artificial para generar el código** de esta práctica. Puedes usarla para resolver dudas o para que te explique un concepto, pero el código debes escribirlo tú.
> La razón es simple: cada error que encuentras y corriges por tu cuenta es experiencia que ganas. En el tercer parcial y en el examen semestral vas a escribir código **sin ayuda de IA**, y esta práctica es tu oportunidad para llegar preparado y con el conocimiento adecuado.

## Sobre esta práctica

**Problema:** escribir un programa en C++ que pida el nombre, el precio y la cantidad de un producto, y el porcentaje de descuento que se le aplica. Con esos datos, el programa calcula el subtotal, el descuento, el IVA (16 %) y el total, y muestra todo en forma de ticket.

**Lo que vas a practicar:** los temas de la Unidad VI, Análisis de programas:

- el **planteamiento** del programa (entradas, salidas, restricciones y proceso),
- el **análisis descendente y ascendente**,
- el **diseño modular**: dividir el programa en **funciones y procedimientos**,
- identificar un **tipo de dato abstracto** (TDA), sin programarlo todavía,
- **generalizar** una solución para poder reutilizarla,
- **codificar** a partir de tu receta,
- **probar y depurar** el programa,
- revisar los **principios de calidad** de tu programa.

**Idea central:** en las prácticas anteriores todo tu programa vivía dentro de `main()`. Esta vez lo vas a **dividir en piezas pequeñas**, cada una con una sola tarea, y `main()` solo las va a coordinar. El problema es sencillo a propósito: la meta no es hacer cuentas difíciles, sino aprender a **pensar en módulos** antes de escribir código.

**Repositorio base:** https://github.com/narizwallace/ulsa_ime_1_dp_ticket_compra

**Entregable:** el enlace a tu repositorio, publicado en Google Classroom.

**El proceso que vas a seguir:**

| Fase | Qué haces |
|---|---|
| 0 | Preparar tu entorno (fork y clonar) |
| 1 | Entender el problema (planteamiento y TDA) |
| 2 | Diseñar la solución: dividir en módulos y escribir la receta |
| 3 | Implementar y depurar |
| 4 | Probar, generalizar y mejorar |
| 5 | Publicar en GitHub |

**Cómo usar el `README.md`:** ya viene en el repositorio base, con espacios en blanco (`_____`). Lo vas llenando fase por fase; cada fase de esta guía te indica qué secciones llenar. No es necesario que uses el archivo README.md, también puedes copiar el contenido y hacerlo en un editor de texto de tu elección. Solo asegúrate de subir el archivo equivalente a tu repositorio. Si una pregunta no aplica (por ejemplo, no hiciste el Experimento C o no tuviste dudas), escribe `No aplica`. Si te sobran filas en una tabla, bórralas.

**Commits a lo largo de la práctica:** en cada fase encontrarás líneas marcadas como **Commit sugerido**, con un mensaje de ejemplo. Haz el commit en ese momento, no todo al final. Así tu historial cuenta cómo construiste tu solución, paso a paso.


## Fase 0. Preparar tu entorno

1. Entra al repositorio base: https://github.com/narizwallace/ulsa_ime_1_dp_ticket_compra
2. Haz clic en **Fork** (arriba a la derecha) para crear tu propia copia en tu cuenta de GitHub.
3. En tu fork, haz clic en **Code**, copia la URL y clónalo en tu computadora.

Estos son los comandos para clonar un repositorio desde tu terminal o línea de comando:
```bash
git clone <URL-de-tu-fork>
cd ulsa_ime_1_dp_ticket_compra
```
También puedes hacer el clone desde GitHub Desktop como lo hemos hecho antes.


4. Abre la carpeta en tu editor y revisa los archivos:

```
ulsa_ime_1_dp_ticket_compra/
├── README.md         ← plantilla con espacios en blanco para llenar
├── PRACTICA.md       ← este documento
├── RECETA.md         ← tu receta: la del programa principal y la de cada módulo
├── include/
│   ├── utilerias.h   ← funciones de apoyo para leer datos (no lo modifiques)
│   └── ticket.h      ← los módulos de cálculo e impresión del ticket
├── src/
│   └── main.cpp      ← el programa principal: coordina los módulos
├── .vscode/          ← configuración del editor (no lo modifiques)
└── .gitignore        ← evita subir el ejecutable
```

**Todo tu trabajo va dentro de esta carpeta.**

> **Nota técnica: ¿por qué ahora hay carpetas `include` y `src`?**
> Es la misma organización que usaste en el Parcial 2. En `include` van los archivos `.h` con los módulos, y en `src` va `main.cpp`. Así, con solo ver las carpetas, cualquier persona entiende cómo está dividido tu programa.

> **Nota técnica: ¿qué trae `utilerias.h`?**
> Las tres funciones que ya conoces: `leerEntero`, `leerDecimal` y `leerCadena`. Recuerda que solo revisan que el dato *sea* un número (o un texto no vacío), **no** que tenga sentido para tu problema. Esa validación te toca a ti.

---

## Fase 1. Entender el problema

*Aquí no se escribe código. Llena las secciones 1 a 5 de tu `README.md`.*

> **Nota técnica: el planteamiento del programa.**
> Plantear un programa es escribir, **antes de diseñar**, qué problema resuelve, qué recibe, qué entrega, qué condiciones deben cumplirse y cómo vas a saber si funciona. Es lo que has hecho en la Fase 1 de todas tus prácticas; ahora ya sabes que tiene nombre.

**Preguntas guía**

1. Explica el problema con tus palabras, en una o dos frases.
2. ¿Cuáles son las entradas? ¿Cuántas son y de qué tipo de dato es cada una?
3. ¿Cuál es la salida? ¿Qué datos debe mostrar el ticket?
4. ¿Entiendes el problema? Compruébalo: explícaselo a un compañero en 1 minuto, sin mirar tus notas.
5. ¿El IVA se calcula sobre el subtotal o sobre lo que queda después del descuento? Revisa un ticket real (del súper, de una papelería) y decide. Justifica tu respuesta.

**Restricciones: ¿qué debe cumplirse?**

- ¿Puede el nombre del producto estar vacío? ¿Puede tener espacios, como "Goma de borrar"? ¿Qué revisa `leerCadena` por ti?
- ¿Puede un precio ser 0 o negativo? ¿Y la cantidad?
- ¿La cantidad puede tener decimales? ¿Qué función de `utilerias.h` te conviene usar para leerla?
- ¿Entre qué valores debe estar el porcentaje de descuento?
- ¿Qué haces si el usuario escribe un dato fuera de rango? (Recuerda cómo lo resolviste en la Práctica 3).
- ¿Puede el total salir negativo? ¿Por qué?

**Resuelve a mano al menos 3 casos:** uno sin descuento, uno con descuento y uno con un precio con centavos. Anota el subtotal, el descuento, el IVA y el total de cada uno. Los usarás como pruebas más adelante.

**Identifica el tipo de dato abstracto (TDA)**

> **Nota técnica: ¿qué es un tipo de dato abstracto?**
> Es una forma de describir una "cosa" del problema por **qué datos tiene** y **qué se puede hacer con ella**, sin decir todavía cómo se programa. Por ejemplo, un *Sensor* tiene una lectura y una unidad, y se puede leer o calibrar. En la Unidad VII vas a aprender a programarlo con `struct`; por ahora solo lo analizas.

En la sección 5 de tu `README.md`, completa la tabla del TDA **Producto**:

| TDA | Datos (¿qué tiene?) | Operaciones (¿qué se puede hacer con él?) |
|---|---|---|
| Producto | nombre (texto), ______, ______ | calcular su subtotal |

Después, **identifica tú una segunda entidad** del problema (pista: ¿qué es lo que se imprime al final?) y llena su fila: sus datos y sus operaciones.

**Pregunta guía (jerarquías):** una tienda vende productos por pieza (un cuaderno) y productos por peso (un kilo de tortillas). ¿Los dos son productos? ¿Qué datos tienen en común y cuál cambia? Contéstalo en una o dos frases.

> **Nota técnica: cómo escribir un buen mensaje de commit.**
> - Empieza con un verbo que diga qué hace el cambio: `Agrega`, `Corrige`, `Completa`, `Valida`, `Generaliza`.
> - Describe **qué** cambió, no "avance", "cambios" ni "ya quedó".
> - Un commit, un cambio: si tu mensaje necesita un "y además", probablemente son dos commits.
> - Mantenlo corto, de preferencia en una línea. En esta guía los mensajes van sin acentos para evitar problemas con algunas terminales.

**Commit sugerido:** `Completa el planteamiento del problema y el TDA`

---

## Fase 2. Diseñar la solución

*Llena las secciones 3, 6 y 7 de tu `README.md` y escribe tu receta en `RECETA.md`.*

### Paso 1: análisis descendente

> **Nota técnica: análisis descendente y ascendente.**
> En el **análisis descendente** (de arriba hacia abajo) empiezas por el problema completo y lo vas dividiendo en partes más pequeñas, hasta que cada parte es tan simple que sabes cómo programarla.
> En el **análisis ascendente** (de abajo hacia arriba) empiezas por las piezas que ya tienes o que sabes hacer, y las vas combinando hasta resolver el problema completo.
> En la práctica se usan los dos: divides de arriba hacia abajo, y al llegar abajo te das cuenta de que algunas piezas ya existen.

> **Nota técnica: ¿cómo se lee un árbol de descomposición?**
> Es un dibujo del análisis descendente. Se lee de arriba hacia abajo y de izquierda a derecha:
> - La **raíz** (la primera línea) es el problema completo.
> - Cada **rama** (las líneas que salen con `├──` o `└──`) es una parte del problema que está justo arriba de ella. `└──` marca la última rama de ese nivel, y la línea vertical `│` solo une las ramas del mismo nivel.
> - Las **hojas** son las ramas que ya no se dividen: tareas tan sencillas que sabes cómo programarlas.
> - La numeración te dice de quién es parte cada rama: `2.1` y `2.2` son partes del paso `2`.
>
> Por ejemplo, el árbol de "Preparar un licuado" se vería así:
> ```
> Preparar un licuado
> ├── 1. Reunir los ingredientes
> │     ├── 1.1 Sacar la leche
> │     └── 1.2 Pelar el plátano
> ├── 2. Licuar
> └── 3. Servir en un vaso
> ```
> "Preparar un licuado" es la raíz; "Reunir los ingredientes" es una rama que se divide en dos hojas; "Licuar" y "Servir en un vaso" son hojas que ya no se dividen. Si sigues las hojas en orden (1.1, 1.2, 2, 3), obtienes los pasos de la receta.

Completa el árbol en la sección 6 de tu `README.md` (los espacios en blanco son tuyos):

```
Generar ticket de compra
├── 1. Mostrar bienvenida
├── 2. Pedir los datos
│     ├── 2.1 Pedir el nombre del producto
│     ├── 2.2 Pedir el precio (y validar que ______)
│     ├── 2.3 ______
│     └── 2.4 ______
├── 3. Calcular los importes
│     ├── 3.1 Calcular el subtotal
│     ├── 3.2 ______
│     ├── 3.3 ______
│     └── 3.4 ______
└── 4. ______
```

**Preguntas guía**

- ¿Cada parte del árbol hace **una sola cosa**? Si una parte hace dos, divídela.
- ¿Hasta dónde conviene dividir? ¿Tiene sentido hacer una función para algo que es una sola línea de código?
- **Análisis ascendente:** revisa `utilerias.h` y `ticket.h`. ¿Qué partes del árbol **ya están resueltas** por una función que existe? Márcalas en tu árbol.

**Commit sugerido:** `Agrega el arbol de analisis descendente`

### Paso 2: decide tus módulos

> **Nota de C++: funciones y procedimientos.**
> Una **función** recibe datos, hace un cálculo y **devuelve** un resultado con `return`. Por ejemplo, `calcularSubtotal` devuelve un `double`.
> Un **procedimiento** hace una tarea pero **no devuelve** nada; en C++ se escribe con `void`. Por ejemplo, un módulo que solo muestra texto en pantalla.
> ```cpp
> double calcularSubtotal(double precio, int cantidad);   // función: devuelve un valor
> void mostrarBienvenida();                               // procedimiento: no devuelve nada
> ```

En la sección 7 de tu `README.md` llena la tabla de módulos. Las dos primeras filas ya vienen hechas porque esos módulos ya existen en `ticket.h`:

| Módulo | ¿Qué recibe? | ¿Qué devuelve? | ¿Función o procedimiento? |
|---|---|---|---|
| `calcularSubtotal` | precio, cantidad | el subtotal | Función |
| `calcularDescuento` | subtotal, porcentaje | el monto del descuento | Función |
| `calcularIVA` | ______ | ______ | ______ |
| `imprimirTicket` | ______ | ______ | ______ |
| (los que tú agregues) | | | |

**Commit sugerido:** `Agrega la tabla de modulos`

### Paso 3: escribe tu receta

En `RECETA.md` escribe **dos tipos de receta**:

1. **La receta del programa principal** (`main`): qué pasos sigue y en qué orden llama a cada módulo. Debe leerse casi igual que tu árbol.
2. **Una receta corta para cada módulo que vas a escribir tú** (`calcularIVA`, `imprimirTicket` y los que agregues): qué recibe, qué hace y qué devuelve.

**Vocabulario de pseudocódigo** (úsalo como referencia, no es una receta):

```
MOSTRAR "mensaje"                LEER variable
variable ← expresión             variable ← leerDecimal("mensaje")
variable ← nombreModulo(datos)   LLAMAR nombreProcedimiento(datos)
SI condición ENTONCES ... SINO ... FIN SI
MIENTRAS condición HACER ... FIN MIENTRAS
MODULO nombre(recibe) ... DEVOLVER resultado ... FIN MODULO
```

> **Nota técnica: la invariante.**
> En esta práctica hay dos lugares donde puedes encontrar una invariante.
> **Pregunta guía 1:** después del ciclo que valida el precio, ¿qué es **siempre** cierto sobre el valor de `precio`?
> **Pregunta guía 2:** ¿qué relación se cumple **siempre** entre el subtotal, el descuento, el IVA y el total, sin importar los datos que escriba el usuario? ¿Puede el descuento ser mayor que el subtotal?
> Escribe tus respuestas en la sección 3 de tu `README.md`.

**Prueba tu receta a mano** con tus 3 casos de la Fase 1. Si algo no cuadra, corrige la receta ahora, no el código después.

**Commits sugeridos:** `Agrega la receta del programa principal` y, cuando termines las de los módulos, `Agrega las recetas de los modulos`. Si corregiste algo al probarla a mano: `Corrige la receta despues de la prueba a mano`.

---

## Fase 3. Implementar y depurar

*Trabaja sobre `src/main.cpp` e `include/ticket.h`. Llena las secciones 8, 9, 10, 11, 12 y 18 de tu `README.md`.*

**Preguntas guía**

- ¿Qué variables necesitas en `main()` y de qué tipo será cada una?
- ¿Hay algún valor que nunca cambia en tu programa? ¿Debería ser una constante?
- ¿Cada módulo de tu receta tiene su función en `ticket.h`? ¿Cada paso de `main` tiene su línea de código?

**Así se ve tu punto de partida en `include/ticket.h`:**

```cpp
#pragma once

#include <iostream>
#include <string>

// Recibe: el precio de un producto y la cantidad comprada.
// Devuelve: el subtotal (precio por cantidad).
inline double calcularSubtotal(double precio, int cantidad) {
    return precio * cantidad;
}

// Recibe: el subtotal y el porcentaje de descuento (de 0 a 100).
// Devuelve: el monto del descuento en pesos.
// OJO: esta funcion tiene un error escondido a proposito. Lee la Fase 3.
inline double calcularDescuento(double subtotal, double porcentaje) {
    return subtotal * porcentaje;
}

// TODO: calcularIVA
//       ¿Qué recibe? ¿Qué devuelve? ¿Dónde guardas la tasa del 16 %?

// TODO: imprimirTicket
//       ¿Es función o procedimiento? ¿Qué datos necesita para imprimir el ticket?
```

> **Nota de C++: `#pragma once`.**
> Evita que el contenido de un `.h` se incluya dos veces en el mismo programa (por ejemplo, si dos archivos hacen `#include "ticket.h"`). Va siempre en la primera línea del archivo `.h`.

**Y así se ve `src/main.cpp`:**

```cpp
// Práctica: Ticket de compra
// main() solo coordina: pide los datos, llama a los módulos y muestra el ticket.
// Deja el comentario "// Paso N" sobre cada bloque, con la numeración de TU receta.

// ¿Recuerdas qué hace iostream?
#include <iostream>
#include <string>

#include "utilerias.h"
#include "ticket.h"

int main() {
    // Variables (siempre inicializadas)
    // TODO: ¿cuántas necesitas? ¿De qué tipo es cada una?

    // Paso 1: mensaje de bienvenida
    // TODO

    // Paso 2: pedir y validar los datos
    // TODO: ¿qué función de utilerias.h usas para cada dato?
    //       ¿Cómo vuelves a pedir un dato que está fuera de rango?

    // Paso 3: calcular los importes llamando a los módulos de ticket.h
    // TODO

    // Paso 4: imprimir el ticket
    // TODO

    // ¿Qué significa return 0;?
    return 0;
}
```

> **Nota de C++: el operador `::`.**
> Se llama **operador de resolución de ámbito**. En `std::cout`, `std` es un *espacio de nombres* (*namespace*): un "apellido" que agrupa todo lo que viene en la biblioteca estándar de C++. `std::cout` se lee "el `cout` que pertenece a `std`".
> Sirve para evitar confusiones: si tú creas una función llamada `max`, no choca con `std::max`, porque cada una tiene su propio "apellido".
> Por eso en este curso escribimos siempre `std::cout`, `std::string`, etc., en lugar de usar `using namespace std;`: así queda claro de dónde viene cada cosa.

### Para compilar y ejecutar

Abre la terminal **en la carpeta del proyecto** (la que contiene `include` y `src`).

**Paso 1. Compilar** (el comando es el mismo en Windows y en macOS):

```bash
g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o ticket
```

**Paso 2. Ejecutar:**

En **macOS**:
```bash
./ticket
```

En **Windows** (PowerShell o la terminal de VSCode):
```bash
.\ticket.exe
```

> **Nota técnica: ¿qué significa cada parte del comando de compilación?**
> - `g++`: el compilador de C++.
> - `-Wall`: activa las advertencias (*warnings*) más comunes, por ejemplo una variable que declaraste y nunca usaste.
> - `-Wextra`: activa advertencias adicionales que `-Wall` no incluye, por ejemplo un parámetro que la función recibe pero no usa.
> - `-std=c++17`: le indica al compilador qué versión del lenguaje usar, en este caso C++17. Así tu código se compila igual en cualquier computadora.
> - `-Iinclude`: le dice al compilador que busque los archivos `.h` también en la carpeta `include`. Gracias a eso puedes escribir `#include "ticket.h"` en lugar de `#include "../include/ticket.h"`.
> - `src/main.cpp`: el archivo que se va a compilar.
> - `-o ticket`: el nombre del ejecutable que se va a generar. En Windows, `g++` le agrega automáticamente la extensión `.exe`.
>
> Una advertencia **no** detiene la compilación, pero casi siempre señala un error real. Tu programa debe compilar **sin advertencias**.

### Construye en pasos pequeños

Compila, prueba y haz un commit después de cada paso:

1. Pide los cuatro datos (sin validar rangos todavía) y muéstralos de vuelta.
   **Commit sugerido:** `Lee los datos del producto`
2. Agrega los ciclos de validación para el precio, la cantidad y el descuento.
   **Commit sugerido:** `Valida el rango del precio, la cantidad y el descuento`
3. Llama a `calcularSubtotal` y muestra el resultado.
   **Commit sugerido:** `Calcula el subtotal`
4. Llama a `calcularDescuento`, pruébalo con un descuento de 10 % y haz el **Experimento A**.
   **Commit sugerido:** `Corrige el error de calcularDescuento`
5. Escribe `calcularIVA`, llámala y calcula el total.
   **Commit sugerido:** `Agrega calcularIVA y el calculo del total`
6. Escribe `imprimirTicket` y úsalo para mostrar el ticket con el formato alineado.
   **Commit sugerido:** `Agrega imprimirTicket con formato alineado`
7. Agrega al final del ticket la línea "Le atendio:" con tu nombre.
   **Commit sugerido:** `Agrega la linea Le atendio al ticket`

### Así debería verse tu ticket

Puedes darle tu propio estilo, pero debe mostrar todos estos datos, **alineados**. Este ejemplo es la salida del caso 2 de la tabla de pruebas (Cuaderno, 50, 2, 10): ejecuta tu programa con esos mismos datos y pega lo que muestra en la sección 9 de tu `README.md`.

```
====================================
          TICKET DE COMPRA
====================================
Producto:   Cuaderno
Precio:     $50.00
Cantidad:   2
------------------------------------
Subtotal:   $100.00
Descuento:  $10.00
IVA (16%):  $14.40
------------------------------------
TOTAL:      $104.40
------------------------------------
Le atendio: Ana Lopez
====================================
```

> **Nota técnica: ¿por qué "atendio" sin acento?**
> La terminal de Windows a veces muestra los acentos como símbolos raros, y además `std::setw` (que verás abajo) cuenta los caracteres acentuados como dos, lo que descuadra la alineación. Por eso, en lo que tu programa **imprime**, escribe sin acentos.

> **Nota de C++: `std::fixed` y `std::setprecision()`.**
> Para que los importes se vean como dinero (`14.40` y no `14.4`), incluye `<iomanip>` y, antes de imprimir los importes, escribe:
> ```cpp
> std::cout << std::fixed << std::setprecision(2);
> ```
> - `std::setprecision(2)` indica **cuántos dígitos** mostrar.
> - `std::fixed` hace que esos dígitos se cuenten **después del punto decimal**. Sin `std::fixed`, `setprecision(2)` cuenta los dígitos totales, y `104.4` se mostraría como `1e+02`.
> - Los dos se quedan activos: desde esa línea, **todos** los `double` se muestran con dos decimales.
> - Esto solo cambia **cómo se ve** el número, no el valor que guarda la variable. El IVA de 3.1984 se muestra como `3.20`, pero la variable sigue valiendo 3.1984.

> **Nota de C++: alinear columnas con `std::setw` y `std::left`.**
> `std::setw(n)` (también de `<iomanip>`) reserva **n espacios** para lo siguiente que se imprime y rellena con espacios lo que sobra. `std::left` hace que el texto quede pegado a la izquierda de ese espacio.
> ```cpp
> std::cout << std::left << std::setw(12) << "Producto:" << nombre << "\n";
> std::cout << std::left << std::setw(12) << "Precio:"   << "$" << precio << "\n";
> ```
> Las dos líneas imprimen la etiqueta en un espacio de 12 caracteres, así que los valores empiezan siempre en la misma columna:
> ```
> Producto:   Cuaderno
> Precio:     $50.00
> ```
> **Ojo:** `std::setw` solo afecta a **lo siguiente** que se imprime, así que tienes que ponerlo en cada línea. `std::left`, en cambio, se queda activo.
> **Pregunta guía:** ¿por qué 12? Cuenta los caracteres de la etiqueta más larga de tu ticket. ¿Qué pasa si usas un número menor que esa cantidad? Contesta en la sección 10 de tu `README.md`.

> **Nota de C++: dibujar las líneas del ticket.**
> En lugar de escribir 36 signos `=` a mano, puedes crear una cadena que repite un carácter:
> ```cpp
> std::cout << std::string(36, '=') << "\n";   // imprime 36 veces el signo =
> std::cout << std::string(36, '-') << "\n";   // imprime 36 guiones
> ```
> **Pregunta guía:** el 36 aparece en varias líneas. ¿Debería ser una constante? ¿Cómo la llamarías? Contesta en la sección 10 de tu `README.md`.

### La línea "Le atendio"

Al final del ticket debe aparecer la línea `Le atendio: <tu nombre>`. Tu nombre **debe leerse de una constante**, no escribirse directamente dentro del `std::cout`. Hay al menos tres lugares donde puedes definir ese dato:

1. Como una **constante local** dentro de `imprimirTicket`.
2. Como una **constante a nivel de la librería**, en `ticket.h`, fuera de cualquier función.
3. Como una **función** que siempre devuelve la misma cadena, por ejemplo `obtenerNombreVendedor()`.

Elige uno y, en la sección 12 de tu `README.md`, **justifica tu elección**.

**Preguntas guía**

- ¿Qué otras partes del programa podrían necesitar el nombre de quien atiende? ¿Un mensaje de bienvenida? ¿Un ticket de devolución?
- Si mañana atiende otra persona, ¿en cuántos lugares tienes que cambiar el nombre con cada opción?
- Si algún día el nombre ya no fuera fijo, sino que se leyera del teclado o de un archivo, ¿con cuál de las tres opciones cambiarías menos código?

> **Nota de C++: el alcance de una constante.**
> El lugar donde declaras una variable o constante define **quién puede usarla**. Eso se llama *alcance* (*scope*).
> - Si la declaras **dentro de una función**, solo esa función la conoce.
> - Si la declaras **en el `.h`, fuera de las funciones**, la conoce cualquier archivo que haga `#include` de ese `.h`.
> No hay una única respuesta correcta: lo importante es que el dato esté en **un solo lugar** y que puedas explicar por qué lo pusiste ahí.

### Depurar

> **Nota técnica: depurar es un proceso, no adivinar.**
> Depurar es encontrar y corregir la causa de un error. Sigue siempre estos pasos:
> 1. **Reproduce** el error: encuentra unos datos con los que siempre falle.
> 2. **Aísla** el error: muestra con `std::cout` los valores intermedios (subtotal, descuento...) hasta encontrar el primero que está mal.
> 3. **Explica** el error: escribe en una frase por qué ese valor está mal.
> 4. **Corrige una sola cosa** y vuelve a probar **todos** tus casos.
> 5. **Limpia:** desactiva las salidas de depuración que agregaste.

> **Nota técnica: salidas de depuración con `[DEBUG]`.**
> Empieza cada mensaje de depuración con el prefijo `[DEBUG]`. Así distingues de inmediato lo que imprime tu programa para el usuario de lo que imprimes tú para buscar errores:
> ```cpp
> std::cout << "[DEBUG] subtotal = " << subtotal << "\n";
> std::cout << "[DEBUG] descuento = " << descuento << "\n";
> ```
> Cuando ya no las necesites, **coméntalas con `//`** en lugar de borrarlas. Así, si el error regresa, solo les quitas el `//`:
> ```cpp
> // std::cout << "[DEBUG] subtotal = " << subtotal << "\n";
> ```
> Antes de entregar, revisa que ninguna línea `[DEBUG]` siga activa: tu ticket final no debe mostrarlas.

> **Experimento A (obligatorio): depura `calcularDescuento`.**
> Esta función trae un error escondido a propósito. **No lo busques leyendo el código: encuéntralo probando.**
> Ejecuta tu programa sin descuento (0 %). ¿El resultado es correcto? Ahora ejecútalo con un descuento de 10 %. ¿Qué pasa?
> Sigue los 5 pasos de depuración, usando salidas `[DEBUG]`, y anota en la sección 11 de tu `README.md`: con qué datos falló, qué valor intermedio estaba mal, cuál era la causa y cómo la corregiste.
> **Pregunta guía:** la prueba con 0 % pasó aunque la función tenía un error. ¿Qué te enseña eso sobre elegir tus casos de prueba?

> **Nota de C++: evita los números mágicos.**
> La tasa del IVA (16) es un valor que no cambia durante la ejecución: declárala como constante, por ejemplo `const double TASA_IVA = 16.0;`, y úsala por su nombre.
> **Experimento B (obligatorio):** en las ciudades de la frontera norte el IVA es de 8 %. Cambia tu programa para calcular con 8 %. ¿Cuántas líneas tuviste que cambiar? Si fue más de una, ¿qué mejorarías? Revisa también tu ticket: ¿sigue diciendo `IVA (16%)`? Al terminar, regresa al 16 %.
> **Commit sugerido** (si mejoraste algo): `Usa la constante TASA_IVA`

> **Nota de C++: paso por valor.**
> **Experimento C (opcional):** dentro de `calcularIVA`, cambia temporalmente el valor del parámetro que recibe (por ejemplo, ponlo en 0 antes del `return`). En `main()`, muestra con `[DEBUG]` la variable que le mandaste antes y después de llamar a la función. ¿Cambió? ¿Por qué? Recuerda lo que vimos sobre paso por valor y por referencia. Deja tu función como estaba.

> **Nota de C++: buenas prácticas.**
> - Cada función hace **una sola cosa**, y su nombre dice cuál (`calcularIVA`, no `calcular2`).
> - Escribe sobre cada función un comentario con lo que **recibe** y lo que **devuelve**, como en `utilerias.h`.
> - Las funciones de cálculo **no** imprimen nada y **no** piden datos: solo reciben valores y devuelven un resultado. Pedir e imprimir le toca a `main()` y a `imprimirTicket`.
> - Inicializa siempre tus variables.
> - Comenta el *porqué* de lo que haces, no lo obvio. Los comentarios `// Paso N` son la excepción: sirven para rastrear la receta.

**Traza tu receta en tu código.** Al terminar, llena la sección 10 de tu `README.md`: para cada paso de tu receta, el módulo o la instrucción de C++ que lo implementa. Si un paso no tiene código, o hay código que no corresponde a ningún paso, algo no cuadra.

**Bitácora de dudas:** ¿qué dudas quieres cubrir con el profesor? Anótalas en la sección 18 de tu `README.md`, junto con lo que ya intentaste para resolverlas.

**Commit sugerido:** `Completa las secciones de implementacion del README`

---

## Fase 4. Probar, generalizar y mejorar

*Llena las secciones 13, 14, 15, 16 y 17 de tu `README.md`.*

### Tabla de pruebas

**Datos de entrada de cada caso.** Escribe los datos en este orden: nombre, precio, cantidad y descuento. Donde dice "luego", escribe primero el dato inválido; el programa debe volver a pedirlo y entonces escribes el siguiente.

| # | Caso | Nombre | Precio | Cantidad | Descuento (%) |
|---|---|---|---|---|---|
| 1 | Sin descuento | Caja de colores | 25 | 4 | 0 |
| 2 | Con descuento | Cuaderno | 50 | 2 | 10 |
| 3 | Descuento de 15 % | Calculadora | 120 | 5 | 15 |
| 4 | Precio con centavos | Pluma | 19.99 | 1 | 0 |
| 5 | Descuento total | Regla | 30 | 3 | 100 |
| 6 | Precio inválido | Mochila | `0`, luego `-5`, luego `40` | 1 | 0 |
| 7 | Cantidad inválida | Marcador | 10 | `0`, luego `2.5`, luego `2` | 0 |
| 8 | Descuento inválido | Libro | 100 | 1 | `150`, luego `-10`, luego `20` |
| 9 | Texto en el precio | Tijeras | `abc`, luego `25` | 4 | 0 |
| 10 | Nombre con espacios | Goma de borrar | 8.50 | 3 | 0 |
| 11 | Nombre vacío | (solo Enter), luego `Folder` | 12 | 1 | 0 |

**Resultados esperados** (en tu `README.md` completa las columnas "Obtenido" y "¿Pasó?"):

| # | Subtotal | Descuento | IVA | Total | Además, debe pasar... |
|---|---|---|---|---|---|
| 1 | 100.00 | 0.00 | 16.00 | 116.00 | |
| 2 | 100.00 | 10.00 | 14.40 | 104.40 | |
| 3 | 600.00 | 90.00 | 81.60 | 591.60 | |
| 4 | 19.99 | 0.00 | 3.20 | 23.19 | |
| 5 | 90.00 | 90.00 | 0.00 | 0.00 | |
| 6 | 40.00 | 0.00 | 6.40 | 46.40 | vuelve a pedir el precio dos veces |
| 7 | 20.00 | 0.00 | 3.20 | 23.20 | vuelve a pedir la cantidad dos veces |
| 8 | 100.00 | 20.00 | 12.80 | 92.80 | vuelve a pedir el descuento dos veces |
| 9 | 100.00 | 0.00 | 16.00 | 116.00 | vuelve a pedir el precio una vez |
| 10 | 25.50 | 0.00 | 4.08 | 29.58 | el ticket muestra el nombre completo |
| 11 | 12.00 | 0.00 | 1.92 | 13.92 | vuelve a pedir el nombre una vez |

Los valores de la tabla consideran que el IVA se calcula **después** del descuento. Si en la Fase 1 decidiste otra cosa, ajusta tus valores esperados antes de probar. **Agrega al menos 2 casos propios.**

**Preguntas guía**

- ¿Alguna prueba falló? ¿El error estaba en un módulo, en `main()`, en tu receta o en el resultado esperado?
- Si un total sale mal, ¿cómo averiguas **en qué módulo** está el error? ¿Te ayuda que el programa esté dividido en funciones?
- En el caso 4, el IVA real es 3.1984. ¿Por qué tu ticket muestra 3.20?
- En el caso 10, ¿el ticket sigue alineado aunque el nombre del producto sea más largo?

**Commit sugerido:** `Completa la tabla de pruebas`

### Generalizar para reutilizar

> **Nota técnica: generalización.**
> Generalizar es darte cuenta de que dos soluciones "distintas" son en realidad **la misma idea** con datos diferentes, y escribir **una sola** solución que sirva para ambas. Así escribes menos código, cometes menos errores y puedes reutilizar esa solución en otros programas.

Ahora que tu programa funciona, compara `calcularDescuento` y `calcularIVA` lado a lado:

- ¿Qué cálculo hace cada una? Escríbelo con palabras.
- ¿Qué cambia entre una y otra? ¿Solo los datos, o también la operación?
- ¿Podrías escribir **una sola** función `calcularPorcentaje` que sirva para los dos casos? ¿Qué recibiría y qué devolvería?

Escribe `calcularPorcentaje` en `ticket.h` y úsala para calcular el descuento y el IVA. Después **vuelve a correr toda tu tabla de pruebas**: si antes pasaba y ahora no, tu cambio rompió algo. Por último, agrega `calcularPorcentaje` a tu tabla de módulos (sección 7 de tu `README.md`).

En la sección 14 de tu `README.md` anota: la receta de `calcularPorcentaje`, cómo quedaron el descuento y el IVA después del cambio, y **en qué otro programa** podrías reutilizar esta función (una propina, una comisión, el porcentaje de batería de un robot...).

> **Nota técnica: prueba de regresión.**
> Cada vez que cambias código que ya funcionaba, vuelves a probar **todos** los casos, no solo el que te interesa. A eso se le llama *prueba de regresión*: confirmar que lo que ya servía sigue sirviendo. Tu tabla de pruebas es tu herramienta para hacerlo.

**Commit sugerido:** `Generaliza el calculo de porcentajes con calcularPorcentaje`

### Revisa la calidad de tu programa

Un programa que da el resultado correcto no siempre es un buen programa. En la sección 15 de tu `README.md`, revisa tu programa con estos principios de calidad y escribe una evidencia de cada uno:

| Principio | Pregunta | ¿Lo cumple? | Evidencia |
|---|---|---|---|
| Correcto | ¿Pasa todas las pruebas de la tabla? | | |
| Robusto | ¿Resiste datos inválidos sin fallar ni terminar? | | |
| Legible | ¿Otra persona entiende tu código sin que se lo expliques? | | |
| Modular | ¿Cada función hace una sola cosa? | | |
| Sin números mágicos | ¿Los valores fijos tienen nombre? | | |
| Fácil de mantener | Si cambia el IVA o quien atiende, ¿cuántas líneas cambias? | | |
| Reutilizable | ¿Alguna de tus funciones serviría en otro programa? | | |

Si algún principio no se cumple, mejóralo, vuelve a correr las pruebas y regístralo en tu bitácora de mejoras (sección 17).

**Commit sugerido:** `Agrega la revision de calidad`

**Ciclo de mejora:** identifica → cambia una sola cosa → vuelve a probar **todo**. Registra cada cambio en tu bitácora de mejoras (sección 17). Si el error estaba en tu receta, corrígela también en `RECETA.md`. Haz un commit por cada mejora, por ejemplo: `Mejora los mensajes de error de la validacion`.

### Retos (uno es obligatorio)

**Elige al menos uno** de los siguientes retos y complétalo: **el que tú quieras es obligatorio**, excepto el 4, que no cuenta como reto obligatorio porque no se programa; los demás son opcionales, para tu insatisfacción positiva. En la sección 16 de tu `README.md` anota cuál elegiste, por qué y cómo lo resolviste.

Antes de programar un reto, agrega primero los pasos nuevos a tu receta en `RECETA.md`.

1. Muestra en el ticket el porcentaje de descuento aplicado, por ejemplo `Descuento (10%): $10.00`, sin perder la alineación. Pistas: `Descuento (10%):` es más larga que las demás etiquetas, ¿qué ancho necesitas ahora en `std::setw`? Y como `std::fixed` y `std::setprecision(2)` siguen activos, ¿cómo evitas que el porcentaje salga como `10.00%`?
2. Tus tres ciclos de validación se parecen mucho. **Generaliza:** escribe una función `leerDecimalEnRango(mensaje, minimo, maximo)` que pida un número hasta que esté dentro del rango, y úsala para el precio y el descuento. ¿Necesitarías otra para la cantidad? ¿Por qué?
3. Alinea los importes **a la derecha**, como en los tickets reales (pista: `std::right`). ¿Qué tienes que cambiar en `imprimirTicket`?
4. *(Opcional, no cuenta como el obligatorio)* `imprimirTicket` recibe muchos parámetros. ¿Cuántos son? ¿Qué pasaría si el ticket tuviera que mostrar 10 datos más? Escribe tu opinión y propón una solución; en la Unidad VII veremos una forma de agruparlos.
5. Permite capturar **varios productos** en un mismo ticket. ¿Qué módulos puedes reutilizar sin cambiarlos? ¿Cuáles tienes que modificar?

**Commit sugerido:** `Agrega el reto: <nombre corto del reto>`, por ejemplo `Agrega el reto: porcentaje de descuento en el ticket`

---

## Fase 5. Publicar en GitHub

1. Verifica que tu `README.md` esté completo, sin `_____` pendientes, que tu receta final esté en `RECETA.md`, que no quede ninguna salida `[DEBUG]` activa y que tu programa compile sin advertencias.
2. Revisa tu historial de commits (en GitHub Desktop, en la pestaña **History**; o en la terminal con `git log --oneline`). Si seguiste los commits sugeridos, a estas alturas ya debes llevar **varios**. Como mínimo debes tener **3 commits** hechos durante el trabajo (no uno solo al final). **Si tienes menos de 3, explica por qué en la sección 20 de tu `README.md`.**
3. Haz tus últimos commits y sube tus cambios a tu fork.

Con los siguientes comandos puedes hacer un commit y publicarlo desde tu terminal o línea de comando:

```bash
git add .
git commit -m "Completa la reflexion final"
git push origin main
```
También puedes usar GitHub Desktop como lo hemos hecho antes.

4. Abre tu repositorio en GitHub y comprueba que ahí aparezcan tu código, tu receta y tu `README.md` actualizados. Tu fork tiene esta forma:
   `https://github.com/<tu-usuario>/ulsa_ime_1_dp_ticket_compra`
5. Entrega en Google Classroom el enlace a **tu fork**.

> **Nota técnica: commits pequeños.**
> Cada commit es un punto al que puedes volver si algo sale mal. Te será especialmente útil al generalizar: si tu cambio rompe algo, puedes regresar al último commit que funcionaba. Además, tu historial de commits le muestra a cualquier persona **cómo** construiste tu programa, no solo el resultado.

---

## Cierre y reflexión

*Llena la sección 19 de tu `README.md` antes de entregar.*

1. ¿Qué aprendiste con esta práctica?
2. Ahora que la terminaste, ¿qué cambiarías de tu proceso?
3. ¿Qué fue lo más difícil y cómo lo resolviste?
4. ¿Qué pregunta te quedó sin responder?
5. Compara esta práctica con las anteriores, donde todo estaba en `main()`. ¿Dividir el programa en módulos te facilitó o te complicó el trabajo? ¿Por qué?
6. ¿Cómo encontraste el error de `calcularDescuento`? ¿Lo habrías encontrado si solo hubieras probado sin descuento?

**Commit sugerido:** `Completa la reflexion final`

---

## Lista de verificación antes de entregar

- [ ] Llené las secciones 1 a 20 de mi `README.md` (no quedan `_____`; escribí `No aplica` donde corresponde)
- [ ] Completé el árbol de análisis descendente y la tabla de módulos
- [ ] Escribí en `RECETA.md` la receta de `main` y la de cada módulo, antes de programar
- [ ] Cada bloque de `main.cpp` tiene su comentario `// Paso N`, de acuerdo con mi receta
- [ ] Corregí el error de `calcularDescuento` y documenté cómo lo encontré
- [ ] Hice los Experimentos A y B y dejé el código correcto al terminar
- [ ] Mi ticket se ve alineado y termina con la línea "Le atendio:", leída de una constante
- [ ] Justifiqué dónde definí la constante con mi nombre
- [ ] Escribí `calcularPorcentaje` y volví a correr todas las pruebas
- [ ] Hice al menos uno de los retos y lo documenté
- [ ] No queda ninguna salida `[DEBUG]` activa
- [ ] Mi programa compila sin advertencias
- [ ] Probé todos los casos de la tabla
- [ ] Revisé los principios de calidad de mi programa
- [ ] No modifiqué `utilerias.h`
- [ ] Tengo al menos 3 commits con mensajes claros (o justifiqué por qué no)
- [ ] Hice `git push` y verifiqué mi fork en GitHub
- [ ] Mi fork se llama `ulsa_ime_1_dp_ticket_compra`, mis módulos están en `include/ticket.h` y mi programa principal en `src/main.cpp`
- [ ] Entregué el enlace de mi fork en Classroom
