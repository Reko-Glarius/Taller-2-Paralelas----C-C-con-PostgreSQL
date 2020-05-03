#include <iostream>
#include <fstream>>
#include <sstream>
#include <pqxx/pqxx>
#include <string>

using namespace std

int main()
{
    std::string rut,nem,ranking,matematicas,lenguaje,ciencias,historia;
    int nemn,rankingn,matematicasn,lenguajen,cienciasn,historian;
    double promedio;

    ofstream arhivo_promedios("promedio.csv");

    pqxx::connection connect("dbname=psu user=psu");
    pqxx::work txn(connect);
    pqxx::result contenedor = txn.exec(
        "SELECT *"
        "FROM puntajes"
    );

    for(int i=0; i<contenedor.size(); i++)
    {
        rut=contenedor[i][1].as<std::string>();

        nem=contenedor[i][2].as<std::string>();
        std::istringstream(nem) >> nemn;
        ranking=contenedor[i][3].as<std::string>();
        std::istringstream(ranking) >> rankingn;
        matematicas=contenedor[i][4].as<std::string>();
        std::istringstream(matematicas) >> matematicasn;
        lenguaje=contenedor[i][5].as<std::string>();
        std::istringstream(lenguaje) >> lenguajen;
        ciencias=contenedor[i][6].as<std::string>();
        std::istringstream(ciencias) >> cienciasn;
        historia=contenedor[i][7].as<std::string>();
        std::istringstream(historia) >> historian;

        promedio=double((nemn+rankingn+matematicasn+lenguajen+cienciasn+historian)/6);
        archivo_promedio<<rut<<";"<<promedio<<std::endl;
        promedio=0;
    }

    txn.commit();
    archivo_promedio.close();
    return 0;
}
