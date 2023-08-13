# Quiniela Plus - Juego de Azar en C++

Este proyecto es una aplicación de consola creada en C++ utilizando Visual Studio Code (VSCode). El objetivo principal de este proyecto es proporcionar a los usuarios una experiencia interactiva para jugar a la Quiniela Plus, un emocionante juego de azar. 

## ¿Qué es la Quiniela Plus?

La Quiniela Plus es un juego de azar en el que los jugadores compran un cartón con 8 números únicos del 00 al 99, ordenados de manera ascendente. En cada jugada, se generan 20 números al azar del 00 al 99, que pueden repetirse. Los premios se otorgan según la cantidad de aciertos:

- 8 aciertos: $11,000,000
- 7 aciertos: $20,000
- 6 aciertos: $500
- 5 aciertos: $50

Cada cartón tiene una fecha de emisión, una fecha de juego (siempre un domingo) y la dirección de la agencia que vendió el cartón. El valor de cada cartón es de $70. Además, se solicita información personal del jugador, incluyendo nombre y DNI.

## Características del Programa

El programa incluye las siguientes características mínimas:

1. **Comprar Cartón Automático:** Permite al usuario comprar un cartón de manera automática, generando 8 números únicos de forma aleatoria.

2. **Comprar Cartón Personalizado:** Permite al usuario seleccionar manualmente los 8 números para su cartón.

3. **Jugar y Generar Números:** El programa genera 20 números aleatorios del 00 al 99 para cada jugada.

4. **Verificar Cartón:** Verifica si el cartón del jugador es ganador y muestra la cantidad de aciertos y el premio correspondiente.

5. **Imprimir Cartón:** Imprime el cartón del jugador, resaltando los números que coinciden con los números generados en la jugada. También guarda el cartón en un archivo.

6. **Bucle de Juego:** Genera un bucle que muestra cuántas veces se necesita jugar con el mismo cartón para alcanzar 8 aciertos y ganar el premio máximo.

## Instrucciones de Uso

1. Clona este repositorio en tu máquina local utilizando el comando:

   ```bash
   git clone https://github.com/tu-usuario/quiniela-plus-cpp.git
   ```

2. Abre el archivo `main.cpp` en Visual Studio Code.

3. Compila y ejecuta el programa desde la terminal de VSCode utilizando el siguiente comando:

   ```bash
   g++ main.cpp -o quiniela
   ./quiniela
   ```

4. Sigue las instrucciones en pantalla para jugar a la Quiniela Plus, comprar cartones, generar jugadas y verificar premios.

## Contribuciones

Si deseas contribuir a este proyecto, ¡te damos la bienvenida! Si tienes alguna idea de mejora, corrección de errores o nuevas características, no dudes en enviar un pull request.

## Aviso Legal

Este programa es solo para fines educativos y de aprendizaje. No promovemos ni apoyamos el juego de azar con dinero real. No nos hacemos responsables de ningún uso indebido de este programa.