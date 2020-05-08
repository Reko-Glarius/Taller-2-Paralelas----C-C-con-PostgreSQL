#include <iostream>
#include <fstream>
#include <cstdlib>
#include "db.h"

using namespace std;

int main(int argc, char** argv) 
{
    PGconn* conexion = dbconnect((char *) DBSERVER, DBPORT, (char *) DBNAME, (char *) DBUSER, (char *) DBPASSWORD);
    std:: string query="SELECT rut,nem,ranking,matematicas,lenguaje,ciencias,historia FROM puntajes ORDER BY rut");
    PGresult* resultado = dbquery(conexion, (char *) query.c_str());
    
    for (unsigned long rut = 14916641; rut <= 19932391; rut++)
    {
        int nem = aleatoreo(475, 750);
        int ranking = aleatoreo(475, 750);
        int matematica = aleatoreo(475, 750);
        int lenguaje = aleatoreo(475, 750);
        int ciencias = aleatoreo(475, 750);
        int historia = aleatoreo(475, 750);
            std::string linea;
            dbfree(resultado);
    }
    dbclose(conexion);
}
