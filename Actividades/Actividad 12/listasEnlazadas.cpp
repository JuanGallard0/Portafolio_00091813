#include <iostream>
#include <vector>
using namespace std;

typedef struct Orden{
    int revueltas;
    int frijolConQueso;
    int queso;
    bool arroz;
}Orden;

Orden solicitarOrden(){
    Orden p; string sino;
    cout << "Cantidad de revueltas: "; cin >> p.revueltas;
    cout << "Cantidad de frijol con queso: ";   cin >> p.frijolConQueso;
    cout << "Cantidad de queso: : "; cin >> p.queso;
    do
    {  
        cout<<"De arroz? (si/no): "; 
        cin>>sino;
    } while (sino != "si" and sino != "no"); 
    if (sino == "si")
        p.arroz = true;     
    else p.arroz = false;
    return p;
}

void mostrarOrden(Orden p){
    cout << "Revueltas: " << p.revueltas << endl;
    cout << "Frijol con queso: " << p.frijolConQueso << endl;
    cout << "Queso: " << p.queso << endl;
    if (p.arroz == true)
        cout<<"de arroz"<<endl;
    else cout<<"de maiz"<<endl;
    cout << endl;
}

vector<Orden> lista;

void agregarOrden(){
    Orden p = solicitarOrden();
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\t1) Al principio\n\t2) Al final"
            << "\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: lista.insert(lista.begin(), p);
                continuar = false;
            break;
            case 2: lista.push_back(p);
                continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);
}

void mostrarLista() {
    for (int i = 0; i < lista.size(); i++) 
        mostrarOrden(lista[i]);
}

int main(){
    cout << "Inicializando..." << endl;
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar orden\n\t2) Ver orden"
            << "\n\t3) Salir\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: cout << "Agregando..." << endl;
                agregarOrden();
            break;
            case 2: cout << "Listando..." << endl;
                mostrarLista();
            break;
            case 3: continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);

    return 0;
}