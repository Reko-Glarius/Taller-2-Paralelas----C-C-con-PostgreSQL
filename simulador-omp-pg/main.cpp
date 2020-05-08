#include <iostream>
#include <fstream>
#include <cstdlib>
#include "db.h"

using namespace std;

int main(int argc, char** argv) 
{
    int ,n_campos,n_filas,promedio=0,dato=0;
    
    ofstream archivo ("Promedio.csv");
    PGconn* conexion = dbconnect((char *) DBSERVER, DBPORT, (char *) DBNAME, (char *) DBUSER, (char *) DBPASSWORD);
    std:: string query="SELECT rut,nem,ranking,matematicas,lenguaje,ciencias,historia FROM puntajes ORDER BY rut");
    PGresult* resultado = dbquery(conexion, (char *) query.c_str());
    
    for (i=0; i<PQnTuples(resultado);i++)
    {
        for(j=2; j<PQnfields(resultado;j++)
        {
            std::istringstream(PQgetvalue(resultado, i, j)) >> dato;
            promedio+=dato;
        }
        promedio=(promedio/6);
        archivo<<PQgetvalue(resultado, i, 1))<<";"<<promedio<<endl;
        promedio=0;
    }
    dbclose(conexion);
}