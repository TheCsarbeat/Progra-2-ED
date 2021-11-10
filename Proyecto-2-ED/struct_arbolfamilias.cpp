#include "struct_arbolfamilias.h"

bool ArbolFamilias::isEmpty(){
    return raiz == NULL;
}
int ArbolFamilias::height(NodoArbolFamiliaALV *t) {
   int h = 0;
   if (t != NULL) {
      int l_height = height(t->l);
      int r_height = height(t->r);
      int max_height = qMax(l_height, r_height);
      h = max_height + 1;
   }
   return h;
}
int ArbolFamilias::difference(NodoArbolFamiliaALV *t) {
   int l_height = height(t->l);
   int r_height = height(t->r);
   int b_factor = l_height - r_height;
   return b_factor;
}
NodoArbolFamiliaALV *ArbolFamilias::rr_rotat(NodoArbolFamiliaALV *parent) {
   NodoArbolFamiliaALV *t;
   t = parent->r;
   parent->r = t->l;
   t->l = parent;
   //cout<<"Right-Right Rotation";
   return t;
}
NodoArbolFamiliaALV *ArbolFamilias::ll_rotat(NodoArbolFamiliaALV *parent) {
   NodoArbolFamiliaALV *t;
   t = parent->l;
   parent->l = t->r;
   t->r = parent;
   //cout<<"Left-Left Rotation";
   return t;
}
NodoArbolFamiliaALV *ArbolFamilias::lr_rotat(NodoArbolFamiliaALV *parent) {
   NodoArbolFamiliaALV *t;
   t = parent->l;
   parent->l = rr_rotat(t);
   //cout<<"Left-Right Rotation";
   return ll_rotat(parent);
}
NodoArbolFamiliaALV *ArbolFamilias::rl_rotat(NodoArbolFamiliaALV *parent) {
   NodoArbolFamiliaALV *t;
   t = parent->r;
   parent->r = ll_rotat(t);
   //cout<<"Right-Left Rotation";
   return rr_rotat(parent);
}
NodoArbolFamiliaALV *ArbolFamilias::balance(NodoArbolFamiliaALV *t) {
   int bal_factor = difference(t);
   if (bal_factor > 1) {
      if (difference(t->l) > 0)
         t = ll_rotat(t);
      else
         t = lr_rotat(t);
   } else if (bal_factor < -1) {
      if (difference(t->r) > 0)
         t = rl_rotat(t);
      else
         t = rr_rotat(t);
   }
   return t;
}

NodoArbolFamiliaALV *ArbolFamilias::insert(Persona *persona){
    if(isEmpty())
        raiz= new NodoArbolFamiliaALV(persona);
    else
        raiz= insert(raiz, persona);

}

NodoArbolFamiliaALV *ArbolFamilias::insert(NodoArbolFamiliaALV *r, Persona *persona) {
   if (r == NULL) {
      asignarHijos(persona);
      r = new NodoArbolFamiliaALV(persona);      
      return r;
   } else if (persona->id< r->persona->id) {
      r->l = insert(r->l, persona);
      r = balance(r);
   } else if (persona->id >= r->persona->id) {
      r->r = insert(r->r, persona);
      r = balance(r);
   } return r;
}


void ArbolFamilias::asignarHijos(Persona *persona){
    int cont = QRandomGenerator::global()->bounded(3);
    persona->name = persona->name + ", cant Hijos: "+QString::number(cont);
    asignarHijos(persona, raiz, cont);
}

int ArbolFamilias::asignarHijos(Persona *persona, NodoArbolFamiliaALV *t, int dato){

    if (t == NULL || dato ==0)
       return dato;
    if(dato == 0){
        return dato;
    }
    if (t->persona->padre == NULL){
        t->persona->padre = persona;
        persona->hijos->insertar(t->persona);
        dato--;
        return dato;
    }
   dato = asignarHijos(persona,t->l, dato);
   if(dato != 0)
        asignarHijos(persona,t->r, dato);
}

void ArbolFamilias::inOrder(NodoArbolFamiliaALV *t) {
   if (t == NULL)
      return;
  inOrder(t->l);
  t->persona->imprimir();
  inOrder(t->r);
}
void ArbolFamilias::preOrder(NodoArbolFamiliaALV *t) {
   if (t == NULL)
      return;
  qDebug() << t->persona->id << " ";
  preOrder(t->l);
  preOrder(t->r);
}
void ArbolFamilias::postOrder(NodoArbolFamiliaALV *t) {
   if (t == NULL)
      return;
  postOrder(t ->l);
  postOrder(t ->r);
  qDebug() << t->persona->id << " ";
}

void ArbolFamilias::imprimirNivel(int nivel){
    nivelImprimir(raiz, nivel, 0);
}

NodoArbolFamiliaALV* ArbolFamilias::nivelImprimir(NodoArbolFamiliaALV*nodo , int nivel, int nivelActual){
    if (nodo != NULL)   {
        //cout<<"|"<<nivel<<", "<<nivelActual<<"|";
        if( nivel == nivelActual){
            qDebug() << nodo->persona->id<< "  ";
        }else if(nivel>nivelActual){
            nivelImprimir(nodo->l, nivel,nivelActual+1);
            nivelImprimir(nodo->r, nivel,nivelActual+1);
        }
   }
}

int ArbolFamilias::treeHeight(NodoArbolFamiliaALV* nodo){
     if (nodo == NULL) // Árbol vacío, devuelve 0
        return 0;
     if (nodo->l == NULL && nodo->r == NULL) // La raíz del árbol devuelve 1
        return 1;
     return qMax (treeHeight (nodo-> l), treeHeight (nodo-> r)) + 1; // La altura del árbol = MAX (la altura del subárbol izquierdo, la altura del subárbol derecho) + 1;
}


//*************************************************Lista de familiar************************
bool ListaSimpleArbolFamilias::isEmpy(){
    return primerNodo == NULL;
}

void ListaSimpleArbolFamilias::insertarALInicio(Persona * persona){
    if(isEmpy()){
        primerNodo = new NodoFamiliaListaSimple(persona);
    }else{
        NodoFamiliaListaSimple *nuevo = new NodoFamiliaListaSimple(persona);
        nuevo->siguiente = primerNodo;
        primerNodo = nuevo;
    }
    largo++;
}


NodoFamiliaListaSimple* ListaSimpleArbolFamilias::buscar(Persona * persona){
    if(!isEmpy()){
        NodoFamiliaListaSimple *temp = primerNodo;
        while(temp->siguiente != NULL){
            if(temp->arbol->raiz->persona->apellido == persona->apellido && temp->arbol->raiz->persona->pais == persona->pais)
                return temp;
            temp = temp->siguiente;
        }
    }
    return NULL;
}

void ListaSimpleArbolFamilias::imprimir(){
    NodoFamiliaListaSimple * temp = primerNodo;
    int cont =0;
    while (temp != NULL){
        qDebug()<<"\n\n";
        qDebug()<<"\nFamilia: "<<cont<<"\n";
        temp->arbol->inOrder(temp->arbol->raiz);
        cont++;
        temp = temp->siguiente;
    }
    qDebug()<<"\n\n***************\nLargo: "<<largo;
}



