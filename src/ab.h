/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: AyEDA
/// Curso: 2º
/// Práctica 6: Árboles TAD
/// Autor: Joel Oscar Martín Gutiérrez
/// Correo: alu0101473840@ull.es
/// Fecha: 16/04/2024
/// Archivo: ab.h

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#include "nodo.h"

#ifndef AB_H
#define AB_H

template <class Key>
class AB {
  virtual bool Buscar(const Key &clave) const = 0;
  virtual bool Insertar(const Key &clave) = 0;
  virtual bool Inorden() const = 0;
  template<class T>
  friend std::ostream& operator<<(std::ostream &os, const AB<T> &arbol);
 private:
  NodoB<Key> *raiz_;
};

template <class Key>
class ABE: public AB<Key> {
 public:
  // Constructor por defecto
  ABE();
  ABE(const std::vector<Key>& claves);
  
  // Métodos
  bool Buscar(const Key &clave) const;
  bool Insertar(const Key &clave);
  bool Inorden() const;

  // Sobrecarga de operador de inserción
  template<class T>
  friend std::ostream& operator<<(std::ostream &os, const ABE<T> &arbol);
 private:
  NodoB<Key> *raiz_;
};

template <class Key>
class ABB: public AB<Key> {
 public:
  // Constructor por defecto
  ABB();
  ABB(const std::vector<Key>& claves);

  // Métodos
  bool Buscar(const Key &clave) const;
  bool Insertar(const Key &clave);
  bool Inorden() const;

  // Sobrecarga de operador de inserción
  template<class T>
  friend std::ostream& operator<<(std::ostream &os, const ABB<T> &arbol);
 private:
  NodoB<Key> *raiz_;
};

// Constructor por defecto de la clase ABE
template <class Key>
ABE<Key>::ABE() {
  raiz_ = nullptr;
}

// Constructor de la clase ABE
template <class Key>
ABE<Key>::ABE(const std::vector<Key>& claves) {
  raiz_ = nullptr;
  for (int i = 0; i < claves.size(); i++) {
    Insertar(claves[i]);
  }
}

// Método que comprueba si una clave se encuentra en el árbol
template <class Key>
bool ABE<Key>::Buscar(const Key &clave) const {
  if (raiz_ == nullptr) {
    return false;
  } else {
    std::queue<NodoB<Key>*> cola;
    cola.push(raiz_);
    while (!cola.empty()) {
      NodoB<Key>* actual = cola.front();
      cola.pop();
      if (actual->get_dato() == clave) {
        return true;
      }
      if (actual->get_izquierda() != nullptr) {
        cola.push(actual->get_izquierda());
      }
      if (actual->get_derecha() != nullptr) {
        cola.push(actual->get_derecha());
      }
    }
    return false;
  }
}

// Método que inserta una clave en el árbol
template <class Key>
bool ABE<Key>::Insertar(const Key &clave) {
  if (raiz_ == nullptr) {
    raiz_ = new NodoB<Key>(clave);
    return true;
  } else {
    std::queue<NodoB<Key>*> cola;
    cola.push(raiz_);
    while (!cola.empty()) {
      NodoB<Key>* actual = cola.front();
      cola.pop();
      if (actual->get_izquierda() == nullptr) {
        actual->set_izquierda(new NodoB<Key>(clave));
        return true;
      } else if (actual->get_derecha() == nullptr) {
        actual->set_derecha(new NodoB<Key>(clave));
        return true;
      } else {
        cola.push(actual->get_izquierda());
        cola.push(actual->get_derecha());
      }
    }
    return false;
  }
}

// Método que recorre el árbol en inorden y lo imprime
template <class Key>
bool ABE<Key>::Inorden() const {
  if (raiz_ == nullptr) {
    return false;
  } else {
    std::cout << "Inorden: ";
    std::stack<NodoB<Key>*> pila;
    NodoB<Key>* actual = raiz_;
    while (actual != nullptr || !pila.empty()) {
      while (actual != nullptr) {
        pila.push(actual);
        actual = actual->get_izquierda();
      }
      actual = pila.top();
      pila.pop();
      std::cout << actual->get_dato() << " ";
      actual = actual->get_derecha();
    }
    return true;
  }
}

// Constructor por defecto de la clase ABB
template <class Key>
ABB<Key>::ABB() {
  raiz_ = nullptr;
}

// Constructor de la clase ABB
template <class Key>
ABB<Key>::ABB(const std::vector<Key>& claves) {
  raiz_ = nullptr;
  for (int i = 0; i < claves.size(); i++) {
    Insertar(claves[i]);
  }
}

// Método que comprueba si una clave se encuentra en el árbol
template <class Key>
bool ABB<Key>::Buscar(const Key &clave) const {
  if (raiz_ == nullptr) {
    return false;
  } else {
    NodoB<Key> *actual = raiz_;
    while (actual != nullptr) {
      if (clave == actual->get_dato()) {
        return true;
      } else if (clave < actual->get_dato()) {
        actual = actual->get_izquierda();
      } else {
        actual = actual->get_derecha();
      }
    }
    return false;
  }
}

// Método que inserta una clave en el árbol
template <class Key>
bool ABB<Key>::Insertar(const Key &clave) {
  if (raiz_ == nullptr) {
    raiz_ = new NodoB<Key>(clave);
    return true;
  } else {
    NodoB<Key> *actual = raiz_;
    while (true) {
      if (clave == actual->get_dato()) {
        return false;
      } else if (clave < actual->get_dato()) {
        if (actual->get_izquierda() == nullptr) {
          actual->set_izquierda(new NodoB<Key>(clave));
          return true;
        } else {
          actual = actual->get_izquierda();
        }
      } else {
        if (actual->get_derecha() == nullptr) {
          actual->set_derecha(new NodoB<Key>(clave));
          return true;
        } else {
          actual = actual->get_derecha();
        }
      }
    }
  }
}

// Método que recorre el árbol en inorden y lo imprime
template <class Key>
bool ABB<Key>::Inorden() const {
  if (raiz_ == nullptr) {
    return false;
  } else {
    std::cout << "Inorden: ";
    std::stack<NodoB<Key>*> pila;
    NodoB<Key>* actual = raiz_;
    while (actual != nullptr || !pila.empty()) {
      while (actual != nullptr) {
        pila.push(actual);
        actual = actual->get_izquierda();
      }
      actual = pila.top();
      pila.pop();
      std::cout << actual->get_dato() << " ";
      actual = actual->get_derecha();
    }
    return true;
  }
}

// Sobrecarga de operador de inserción
template <class T>
std::ostream& operator<<(std::ostream &os, const ABE<T> &arbol) {
  if (arbol.raiz_ == nullptr) {
    os << "Nivel 0: [.]" << std::endl;
    return os;
  }
  std::queue<std::pair<NodoB<T>*, int>> cola;
  cola.push({arbol.raiz_, 0});
  int nivel_actual = 0;
  while (!cola.empty()) {
    auto [nodo, nivel] = cola.front();
    cola.pop();
    if (nivel > nivel_actual || nivel == 0) {
      os << std::endl;
      nivel_actual = nivel;
      os << "Nivel " << nivel << ": ";
    }
    if (nodo == nullptr) {
      os << "[.]";
    } else {
      os << "[" << nodo->get_dato() << "]";
      cola.push({nodo->get_izquierda(), nivel + 1});
      cola.push({nodo->get_derecha(), nivel + 1});
    }
  }
  return os;
}

// Sobrecarga de operador de inserción
template <class T>
std::ostream& operator<<(std::ostream &os, const ABB<T> &arbol) {
  if (arbol.raiz_ == nullptr) {
    os << "Nivel 0: [.]" << std::endl;
    return os;
  }
  std::queue<std::pair<NodoB<T>*, int>> cola;
  cola.push({arbol.raiz_, 0});
  int nivel_actual = 0;
  while (!cola.empty()) {
    auto [nodo, nivel] = cola.front();
    cola.pop();
    if (nivel > nivel_actual || nivel == 0) {
      os << std::endl;
      nivel_actual = nivel;
      os << "Nivel " << nivel << ": ";
    }
    if (nodo == nullptr) {
      os << "[.]";
    } else {
      os << "[" << nodo->get_dato() << "]";
      cola.push({nodo->get_izquierda(), nivel + 1});
      cola.push({nodo->get_derecha(), nivel + 1});
    }
  }
  return os;
}

#endif