/**
 * Rodar com `g++ main.cpp` no shell
 */

#include "./queue.cpp"
#include "options.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void show_options();
Options get_option();
int get_plane_id();
string get_plane_name();
void show_separator();

int main() {
  Options option = undefined;
  Queue *queue = new Queue();
  Plane *plane = nullptr;

  do {
    show_separator();
    show_options();
    option = get_option();
    show_separator();

    switch (option) {
    case list_number:
      cout << "Existem " << queue->GetSize() << " avioes na fila!" << endl;
      break;

    case authorize_first:
      if (queue->IsEmpty()) {
        cout << "Fila vazia!" << endl;
        break;
      }
      plane = queue->Dequeue();
      cout << "Partindo agora aviao " << plane->name << " com id de "
           << plane->id << endl;
      delete plane;
      plane = nullptr;
      break;

    case add_plane:
      plane = new Plane();
      plane->id = get_plane_id();
      plane->name = get_plane_name();
      queue->Enqueue(plane);
      plane = nullptr;
      break;

    case list_planes:
      queue->List();
      break;

    case list_first:
      if (queue->IsEmpty()) {
        cout << "Fila Vazia!" << endl;
        break;
      }
      queue->PrintFirst();
      break;

    case quit:
      break;

    default:
      cout << "Opcao invalida!" << endl;
      break;
    }
  } while (option != quit);

  delete queue;
}

void show_options() {
  cout << "1. Listar numero de avioes na fila" << endl;
  cout << "2. Autorizar decolagem de aviao" << endl;
  cout << "3. Adicionar aviao na fila" << endl;
  cout << "4. Listar avioes na fila de espera" << endl;
  cout << "5. Listar caracteristica do primeiro aviao" << endl;
  cout << "0.  Sair" << endl;
}

Options get_option() {
  int option;
  cout << "Escolha sua opcao: ";
  cin >> option;

  if (option < -1 || option > 5)
    return undefined;
  return (Options)option;
}

int get_plane_id() {
  int id;
  cout << "Digite o id do aviao: ";
  cin >> id;
  return id;
}

string get_plane_name() {
  string name;
  cout << "Digite o nome do aviao: ";
  cin >> name;
  return name;
}

void show_separator() {
  cout << "========================================" << endl;
}
