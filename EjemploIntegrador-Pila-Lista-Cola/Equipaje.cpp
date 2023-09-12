#include "Equipaje.h"

/******************************************************************************/
/* Implementación de Primitivas */
/*------------------------------*/

void crearEquipaje(Equipaje &equipaje){
    equipaje.Id = 0;
    equipaje.Duenio = "";
    equipaje.Peso = 0;
}

/*----------------------------------------------------------------------------*/


void setIdEquipaje(Equipaje &equipaje, int dato){
     equipaje.Id = dato;
}

/*----------------------------------------------------------------------------*/

void setDuenioEquipaje(Equipaje &equipaje, string dato){
     equipaje.Duenio = dato;
}

/*----------------------------------------------------------------------------*/

void setPesoEquipaje(Equipaje &equipaje, float dato){
     equipaje.Peso = dato;
}

/*----------------------------------------------------------------------------*/

int getIdEquipaje(Equipaje &equipaje){
    return equipaje.Id;
}

/*----------------------------------------------------------------------------*/

string getDuenioEquipaje(Equipaje &equipaje){
    return equipaje.Duenio;
}

/*----------------------------------------------------------------------------*/

float getPesoEquipaje(Equipaje &equipaje){
    return equipaje.Peso;
}

/*----------------------------------------------------------------------------*/

void eliminarEquipaje(Equipaje &equipaje){
}






