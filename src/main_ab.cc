/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: AyEDA
/// Curso: 2º
/// Práctica 6: Árboles TAD
/// Autor: Joel Oscar Martín Gutiérrez
/// Correo: alu0101473840@ull.es
/// Fecha: 16/04/2024
/// Archivo: nodo.h

#include <iostream>
#include <fstream>

#include "ab.h"
#include "nif.h"

// Función que comprueba que el número de parámetros de entrada es correcto y proporciona ayuda al usuario
void Usage(int argc, char *argv[]) {
  if (argc != 5 && argc != 6 && argc != 7) {
    std::cout << "--Árboles" << std::endl;
    std::cout << "Modo de uso: ./main_ab -ab <abe|abb> -init <i> <manual|file|random> [s][f]" << std::endl << "Pruebe ./main_ab --help para más información" << std::endl;
    exit(EXIT_FAILURE);
  }  
  if (argv[1] == "--help") {
    std::string parametro_introducido = argv[1];
    if (parametro_introducido == "--help") {
      std::cout << "--Árboles" << std::endl;
      std::cout << "Modo de uso: ./main_ab -ab <abe|abb> -init <i> <manual|file|random> [s][f]" << std::endl;
      std::cout << "-ab <abe|abb>: indica el tipo de árbol" << std::endl;
      std::cout << "-init <i> <manual|file|random> [s][f]: indica la forma de introducir los datos. En caso de ser random [s] debe indicar el nº de elementos a generar. En caso de ser file";
      std::cout << "[s] es el nº de elementos a generar y [f] el nombre del fichero de entrada." << std::endl;
      exit(EXIT_SUCCESS);
    } 
  }
}

// Función que ejecuta el menú de opciones para el árbol
template<typename T>
void MenuEjecucion(T& arbol) {
  while (true) {
    std::cout << "Introduzca una opción: " << std::endl;
    std::cout << "1. Insertar clave" << std::endl;
    std::cout << "2. Buscar clave" << std::endl;
    std::cout << "3. Mostrar árbol inorden" << std::endl;
    std::cout << "4. Salir" << std::endl;
    int opcion;
    std::cin >> opcion;
    if (opcion == 1) {
      std::cout << "Introduzca la clave a insertar: " << std::endl;
      Nif nif;
      int long nif_long = 0;
      std::cin >> nif_long;
      nif = nif_long;
      arbol.Insertar(nif);
      std::cout << arbol << std::endl;
    } else if (opcion == 2) {
      std::cout << "Introduzca la clave a buscar: " << std::endl;
      Nif nif;
      int long nif_long = 0;
      std::cin >> nif_long;
      nif = nif_long;
      if (arbol.Buscar(nif)) {
        std::cout << "Clave encontrada" << std::endl;
      } else {
        std::cout << "Clave no encontrada" << std::endl;
      }
    } else if (opcion == 3) {
      arbol.Inorden();
      std::cout << std::endl << std::endl;
    } else if (opcion == 4) {
      std::cout << "Saliendo..." << std::endl;
      exit(EXIT_SUCCESS);
    }
  }
}

// Función principal
int main(int argc, char *argv[]) {
  Usage(argc, argv);
  std::string tipo_arbol = argv[2];
  std::string inicializacion = argv[4];
  if (inicializacion == "manual") {
    if (tipo_arbol == "abe") {
      ABE<Nif> arbol;
      MenuEjecucion(arbol);
    } else if (tipo_arbol == "abb") {
      ABB<Nif> arbol;
      MenuEjecucion(arbol);
    }
  } else if (inicializacion == "file") {
    std::string nombre_fichero = argv[5];
    std::ifstream fichero(nombre_fichero);
    std::vector<Nif> claves;
    Nif nif;
    while (fichero >> nif) {
      claves.push_back(nif);
    }
    if (tipo_arbol == "abe") {
      ABE<Nif> arbol(claves);
      MenuEjecucion(arbol);
    } else if (tipo_arbol == "abb") {
      ABB<Nif> arbol(claves);
      MenuEjecucion(arbol);
    }
  } else if (inicializacion == "random") {
    int num_elem = std::stoi(argv[5]);
    std::vector<Nif> claves;
    for (int iterador = 0; iterador < num_elem; iterador++) {
      Nif nif;
      claves.push_back(nif);
    }
    if (tipo_arbol == "abe") {
      ABE<Nif> arbol(claves);
      MenuEjecucion(arbol);
    } else if (tipo_arbol == "abb") {
      ABB<Nif> arbol(claves);
      MenuEjecucion(arbol);
    }
  }
  return 0;
}