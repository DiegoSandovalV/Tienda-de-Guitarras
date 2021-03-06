/*
 * Proyecto A01709113
 * Sandoval Vargas Diego Ernesto
 * A01709113
 * 14/06/2022
 */


/*Clase Instrumento
 * Es la clase Padre abstracta que contiene los metodos y carcateristicar a heredar en las subclases, se declara un metodo
 * virtual que dependiendo del tipo de objeto se muestran sus caracteristicas y tiene un metodo para calcular el porcentaje
 * de venta de un cualquier producto
*/

#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#include <iostream>
#include <string>
#include<sstream>

using namespace std;

class Instrumento {

private:
    float precio;

public:
    string marca;
    string modelo;

    int unidades; //Cantidad de producto que se tiene para vender (stock)
    int ventas; //Cantidad de unidades que se vendieron

    //constructor default
    Instrumento() : marca(""), modelo(""), precio(0), unidades(0), ventas(0) {};

    //Construccion con entrada de datos
    Instrumento(string mar, string mod, float pre, int uni, int ven) : marca(mar), modelo(mod), precio(pre),
                                                                       unidades(uni), ventas(ven) {};


    //metodos

    //getters
    string get_marca();
    string get_modelo();
    float get_precio();
    int get_unidades();
    int get_ventas();

    //setters
    void set_marca(string);
    void set_modelo(string);
    void set_precio(float);
    void set_unidades(int);
    void set_ventas(int);

    //Declaracion de metodo virtual
    virtual string mostrar_car()=0;

    //Metodo para calcular el porcentaje de ventas del objeto
    string porcentaje_ventas();

};

//Getters


string Instrumento::get_marca() {
    return marca;
}

string Instrumento::get_modelo() {
    return modelo;
}

float Instrumento::get_precio() {
    return precio;
}

int Instrumento::get_unidades() {
    return unidades;
}

int Instrumento::get_ventas() {
    return ventas;
}

//Setters

void Instrumento::set_marca(string mar) {
    marca = mar;
}

void Instrumento::set_modelo(string mod) {
    modelo = mod;
}

void Instrumento::set_precio(float pre) {
    precio = pre;
}

void Instrumento::set_unidades(int un) {
    unidades = un;
}

void Instrumento::set_ventas(int ven) {
    ventas = ven;
}

//Metodo para calcular el porcentaje de ventas del objeto

string Instrumento::porcentaje_ventas(){

    //Se calcula el porcentaje convirtiendo los valores int de ventas y unidades a float,
    float p;
    p = (float) ventas / (float) unidades * 100; // se multiplica * 100 para que se vea mejor el numero

    if(ventas==0){
        return "No ha tenido ventas el producto";
    }
    else if(unidades>ventas) {
        return "El porcentaje de ventas es: " + to_string(p) + "%";
    }else if(unidades==ventas){
        return "Se han vendido todas las unidades";
    }
    else{
        return "Posible error en unidades y ventas";
    }
}


#endif
