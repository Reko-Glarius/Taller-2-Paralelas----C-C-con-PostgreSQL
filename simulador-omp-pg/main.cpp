#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "db.h"

using namespace std;

int main(int argc, char** argv) 
{
    int n_campos,n_filas,promedio=0,dato=0;
    string datin;
    
    std::ofstream archivo ("promedio.csv");
    PGconn* conexion = dbconnect((char *) DBSERVER, DBPORT, (char *) DBNAME, (char *) DBUSER, (char *) DBPASSWORD);
    cout << "hola" << std::endl;
    std::string query="SELECT rut,nem,ranking,matematica,lenguaje,ciencias,historia FROM puntajes ORDER BY rut";
    PGresult* resultado = dbquery(conexion, (char *) query.c_str());
    
    for (int i=0; i<PQntuples(resultado);i++)
    {
        for(int j=1; j<PQnfields(resultado);j++)
        {
            datin=PQgetvalue(resultado, i, j);
            std::istringstream(datin) >> dato;
            promedio+=dato;
            dato=0;
        }
        cout << "mundo" << std::endl;
        promedio=(promedio/6);
        archivo<<PQgetvalue(resultado, i, 0)<<";"<<promedio<<endl;
        promedio=0;
    }
    dbclose(conexion);
    archivo.close();
}
