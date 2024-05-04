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

template <class Key>
class NodoB {
 public:
  // Constructores
  NodoB(Key dato): dato_(dato), izquierda_(nullptr), derecha_(nullptr) {}
  NodoB(Key dato, NodoB<Key> *izquierda, NodoB<Key> *derecha): dato_(dato), izquierda_(izquierda), derecha_(derecha) {}
  
  // Getters y setters
  Key get_dato() const { return dato_; }
  NodoB<Key>* get_izquierda() const { return izquierda_; }
  NodoB<Key>* get_derecha() const { return derecha_; }
  void set_derecha(NodoB<Key> *derecha) { derecha_ = derecha; }
  void set_izquierda(NodoB<Key> *izquierda) { izquierda_ = izquierda; }
 private:
  Key dato_;
  NodoB<Key> *izquierda_;
  NodoB<Key> *derecha_;
};