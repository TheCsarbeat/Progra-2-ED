#include "struct_cielo.h"

void ArbolAngelesCielo::insertar(Angel *a){
    QString *insertado = new QString;
    *insertado = "";
    raiz= insertar(raiz, a, insertado);
}

NodoArbolAngelesCielo* ArbolAngelesCielo::insertar(NodoArbolAngelesCielo * nodo, Angel* a, QString *insertado){

    if (nodo == NULL){
        a->insertado = true;
        return new NodoArbolAngelesCielo(a);
    }else if (nodo->angel->generacion < a->generacion-1){

        if(a->insertado) return nodo;
        nodo->izquierdo = insertar(nodo->izquierdo,a, 0);

        if(a->insertado) return nodo;
        nodo->centro =  insertar(nodo->centro,a, 0);

        if(a->insertado) return nodo;
        nodo->derecho = insertar(nodo->derecho, a, 0);

    }else if(nodo->angel->generacion == a->generacion-1 && nodo->angel->version*3 >= a->version){
        if(nodo->izquierdo ==NULL)
            nodo->izquierdo = insertar(nodo->izquierdo,a, 0);

        else if(nodo->centro == NULL && nodo->izquierdo->angel != a)
            nodo->centro = insertar(nodo->centro,a, 0);

        else if(nodo->derecho ==NULL && nodo->izquierdo->angel != a && nodo->centro->angel != a)
            nodo->derecho= insertar(nodo->derecho,a, 0);
    }
    return nodo;
}

void ArbolAngelesCielo::imprimirNivel(int nivel){
    nivelImprimir(raiz, nivel, 0);
}

void ArbolAngelesCielo::nivelImprimir(NodoArbolAngelesCielo *nodo , int nivel, int nivelActual){
    if (nodo != NULL)   {
        //cout<<"|"<<nivel<<", "<<nivelActual<<"|";
        if( nivel == nivelActual){
            qDebug() <<"Nombre: "<<nodo->angel->name<<"Version: "<< nodo->angel->version<< ", Generacion: "<<nodo->angel->generacion;
        }else if(nivel>nivelActual){
            nivelImprimir(nodo->izquierdo, nivel,nivelActual+1);
            nivelImprimir(nodo->centro, nivel,nivelActual+1);
            nivelImprimir(nodo->derecho , nivel,nivelActual+1);
        }
   }
}

//----------------------------------------ARBOL BUCKET AVL--------------------------------------

bool ArbolCieloALV::isEmpty(){
    return raiz == NULL;
}
int ArbolCieloALV::height(NodoArbolCieloALV *t) {
   int h = 0;
   if (t != NULL) {
      int l_height = height(t->l);
      int r_height = height(t->r);
      int max_height = qMax(l_height, r_height);
      h = max_height + 1;
   }
   return h;
}
int ArbolCieloALV::difference(NodoArbolCieloALV *t) {
   int l_height = height(t->l);
   int r_height = height(t->r);
   int b_factor = l_height - r_height;
   return b_factor;
}
NodoArbolCieloALV *ArbolCieloALV::rr_rotat(NodoArbolCieloALV *parent) {
   NodoArbolCieloALV *t;
   t = parent->r;
   parent->r = t->l;
   t->l = parent;
   //cout<<"Right-Right Rotation";
   return t;
}
NodoArbolCieloALV *ArbolCieloALV::ll_rotat(NodoArbolCieloALV *parent) {
   NodoArbolCieloALV *t;
   t = parent->l;
   parent->l = t->r;
   t->r = parent;
   //cout<<"Left-Left Rotation";
   return t;
}
NodoArbolCieloALV *ArbolCieloALV::lr_rotat(NodoArbolCieloALV *parent) {
   NodoArbolCieloALV *t;
   t = parent->l;
   parent->l = rr_rotat(t);
   //cout<<"Left-Right Rotation";
   return ll_rotat(parent);
}
NodoArbolCieloALV *ArbolCieloALV::rl_rotat(NodoArbolCieloALV *parent) {
   NodoArbolCieloALV *t;
   t = parent->r;
   parent->r = ll_rotat(t);
   //cout<<"Right-Left Rotation";
   return rr_rotat(parent);
}
NodoArbolCieloALV *ArbolCieloALV::balance(NodoArbolCieloALV *t) {
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

NodoArbolCieloALV *ArbolCieloALV::insert(Persona *persona, Angel *angel){
    if(isEmpty()){
        raiz= new NodoArbolCieloALV(persona, angel);
        cant++;
    }else
        raiz= insert(raiz, persona, angel);

}

NodoArbolCieloALV *ArbolCieloALV::insert(NodoArbolCieloALV *r, Persona *persona, Angel*angel) {
   if (r == NULL) {
      r = new NodoArbolCieloALV(persona,angel);
      cant++;
      return r;
   } else if (persona->id < r->persona->id) {
      r->l = insert(r->l, persona, angel);
      r = balance(r);
   } else if (persona->id >= r->persona->id) {
      r->r = insert(r->r, persona, angel);
      r = balance(r);
   } return r;
}

void ArbolCieloALV::inOrder(NodoArbolCieloALV *t) {
   if (t == NULL)
      return;
  inOrder(t->l);
  t->persona->imprimir();
  inOrder(t->r);
}

QString * ArbolCieloALV::toStringInOrden(){
    QString *dato = new QString();
    *dato = "";
    toStringInOrden(raiz, dato);
    return dato;
}

void ArbolCieloALV::toStringInOrden(NodoArbolCieloALV* t, QString* dato){
    if (t == NULL)
       return;
   toStringInOrden(t->l,dato);
   t->persona->imprimir();
   *dato += t->persona->toString()+t->persona->hijos->toStringIDHijos();
   toStringInOrden(t->r,dato);
}

