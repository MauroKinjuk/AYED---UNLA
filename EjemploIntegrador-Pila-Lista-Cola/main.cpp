#include <iostream>

#include "Lista.h"
#include "Cola.h"
#include "Pila.h"
#include "Vuelo.h"
#include "Equipaje.h"
#include "Transportador.h"


using namespace std;


ResultadoComparacion compararListaVuelo(PtrDato ptrDato1, PtrDato ptrDato2) {
    int dato1 = ((Vuelo*) ptrDato1)->Id;
    int dato2 = ((Vuelo*) ptrDato2)->Id;

    if (dato1 < dato2) {
        return MENOR;
    }else if (dato1 > dato2) {
        return MAYOR;
    }else{
        return IGUAL;
    }
}

void imprimirVuelo(Vuelo vuelo){

     cout << "--------- Vuelo ---------- "<< endl;
     cout << "Id : " << getIdVuelo(vuelo) << endl;
     cout << "Aerolinea: " << getAerolinea(vuelo) << endl;
     cout << "Ciudad de Origen: " << getC_Origen(vuelo) << endl;
     cout << "Ciudad de Destino: " << getC_Destino(vuelo) << endl;
     cout << "Fecha de Salida: " << getF_Salida(vuelo) << endl;
     cout << "Hora de Embarque: " << getH_Embarque(vuelo) << endl;
     cout << "Hora de Despegue: " << getH_Despegue(vuelo) << endl;
     cout << "Fecha de Llegada: " << getF_Llegada(vuelo) << endl;
     cout << "Hora de Arribo: " << getH_Arribo(vuelo) << endl;
     cout << "Tipo: " << getTipoVuelo(vuelo) << endl;

     /// Que pasaria si quiero imprimir tambien la pila de equipajes?

     cout << endl;
}


void imprimirEquipaje(Equipaje equipaje){

     cout << "--------- Equipaje ---------- "<< endl;
     cout << "ID: " << getIdEquipaje(equipaje)<< endl;
     cout << "Duenio: " << getDuenioEquipaje(equipaje)<< endl;
     cout << "Peso: " << getPesoEquipaje(equipaje)<< endl;

}


int main()
{
    /// Crear una lista de Vuelos

    Lista vuelosArribos;
    crearLista(vuelosArribos, compararListaVuelo);

    ///--------------------------- Cargo un vuelo y sus equipajes-----------------------//

    /// Crear un Vuelo
    Vuelo* ptrVuelo1 = new Vuelo;
    crearVuelo(*ptrVuelo1);

    setIdVuelo(*ptrVuelo1, 1);
    setAerolinea(*ptrVuelo1,"Aerolineas Argentinas");
    setC_Origen(*ptrVuelo1, "Londres");
    setC_Destino(*ptrVuelo1, "Buenos Aires");
    setF_Salida(*ptrVuelo1, "05/06/2019");
    setH_Embarque(*ptrVuelo1, "09:00");
    setH_Despegue(*ptrVuelo1, "10:00");
    setF_Llegada(*ptrVuelo1, "06/06/2019");
    setH_Arribo(*ptrVuelo1, "01:00");
    setTipoVuelo(*ptrVuelo1, "Arribo");

    /// Agregarlo a la Lista
    adicionarFinal(vuelosArribos, ptrVuelo1);

    /// Crear un equipaje
    Equipaje* ptrEquipaje1 = new Equipaje;
    crearEquipaje(*ptrEquipaje1);

    setIdEquipaje(*ptrEquipaje1, 1);
    setDuenioEquipaje(*ptrEquipaje1, "Romina Mansilla");
    setPesoEquipaje(*ptrEquipaje1, 15);

    /// Agregarlo a la Pila del vuelo
    agregarEquipajeVuelo(*ptrVuelo1, ptrEquipaje1);

    /// Crear un equipaje
    Equipaje* ptrEquipaje2 = new Equipaje;
    crearEquipaje(*ptrEquipaje2);

    setIdEquipaje(*ptrEquipaje2, 2);
    setDuenioEquipaje(*ptrEquipaje2, "Damian Santos");
    setPesoEquipaje(*ptrEquipaje2, 23);

    /// Agregarlo a la Pila del vuelo
    agregarEquipajeVuelo(*ptrVuelo1, ptrEquipaje2);

    ///--------------------------- Repito el proceso-----------------------//

    /// Crear un vuelo
    Vuelo* ptrVuelo2 = new Vuelo;
    crearVuelo(*ptrVuelo2);

    setIdVuelo(*ptrVuelo2, 2);
    setAerolinea(*ptrVuelo2,"Gol");
    setC_Origen(*ptrVuelo2, "Salta");
    setC_Destino(*ptrVuelo2, "Buenos Aires");
    setF_Salida(*ptrVuelo2, "05/06/2019");
    setH_Embarque(*ptrVuelo2, "15:00");
    setH_Despegue(*ptrVuelo2, "16:00");
    setF_Llegada(*ptrVuelo2, "05/06/2019");
    setH_Arribo(*ptrVuelo2, "19:00");
    setTipoVuelo(*ptrVuelo2, "Arribo");

    /// Agregarlo a la Lista
    adicionarFinal(vuelosArribos, ptrVuelo2);

    /// Crear un equipaje
    Equipaje* ptrEquipaje3 = new Equipaje;
    crearEquipaje(*ptrEquipaje3);

    setIdEquipaje(*ptrEquipaje3, 3);
    setDuenioEquipaje(*ptrEquipaje3, "Juan Perez");
    setPesoEquipaje(*ptrEquipaje3, 13);

    /// Agregarlo a la Pila del vuelo
    agregarEquipajeVuelo(*ptrVuelo2, ptrEquipaje3);

    /// Crear un equipaje
    Equipaje* ptrEquipaje4 = new Equipaje;
    crearEquipaje(*ptrEquipaje4);

    setIdEquipaje(*ptrEquipaje4, 4);
    setDuenioEquipaje(*ptrEquipaje4, "Dario Pereyra");
    setPesoEquipaje(*ptrEquipaje4, 23);

    /// Agregarlo a la Pila del vuelo
    agregarEquipajeVuelo(*ptrVuelo2, ptrEquipaje4);

    ///--------------------------- Entrego los equipajes-----------------------//

    Cola equipajesAEntregar ;
    crearCola(equipajesAEntregar);

    /// Recorro la lista
     if(!listaVacia(vuelosArribos)){
        PtrNodoLista nodo = primero(vuelosArribos);
        while(nodo != finLista()){

            /// Obtengo el dato por la primitiva
            PtrDato d;
            obtenerDato(vuelosArribos, d, nodo);
            Vuelo* ptrVuelo = (Vuelo*) d;
            imprimirVuelo(*ptrVuelo);

            /// Si tiene equipajes
            while(tieneEquipaje(*ptrVuelo)){

                /// Los saco de la pila, y los paso a la cola de Equipajes a Entregar
                Equipaje* ptrEquipaje = new Equipaje;
                *ptrEquipaje = sacarEquipajeVuelo(*ptrVuelo);

                encolar(equipajesAEntregar, ptrEquipaje);
                imprimirEquipaje(*ptrEquipaje);
            }


            nodo = siguiente(vuelosArribos, nodo);
        }
    }

    /// 1. Crear y cargar una Cola de Vuelos en pista (tipo partida).

    /// 2. Crear imprimir una Lista de "Equipajes Perdidos"

    /// 3. Llenarla con los equipajes de los Vuelos en Pista

    return 0;
}
