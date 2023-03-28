#include <iostream>
#include <string>
#define TAM 50
using namespace std;

class Alumno{
private:
    string Nombre;
    string Carrera;
    int Materias;
    float Promedio;
public:
    Alumno(){}
    friend ostream& operator<<(ostream& O, Alumno& x){
            O << "\nNombre: " << x.Nombre;
            O << "\nCarrera: " << x.Carrera;
            O << "\nMaterias Aprobadas: " << x.Materias;
            O << "\nPromedio: " << x.Promedio;
            return O;
    }
    friend istream& operator>>(istream& I, Alumno& x){
            cout << "\nNombre: ";
            I >> x.Nombre;
            cout << "Carrera: ";
            I >> x.Carrera;
            cout << "Materias Aprobadas: ";
            I >> x.Materias;
            cout << "Promedio: ";
            I >> x.Promedio;
            return I;
    }
    bool operator==(string str) const {
        return (this->Nombre == str);
    }
    const string& getNombre() const {
        return Nombre;
    }

    void setNombre(const string& nuevoNombre) {
        Nombre = nuevoNombre;
    }
};

//plantillas
template<class T>
class Cola{
private:
    T datos[TAM];
    int ult;
    bool inserta(T, int);
    bool elimina(int);
    T recupera(int)const;
    int primero()const;
    int ultimo()const;
    void imprime()const;
public:
    Cola():ult(-1){}
    bool vacia()const;
    bool llena()const;
    bool Queue(T&);
    bool Dequeue();
    T Front()const;
    int Buscar(string);
};

template<class T>
int Cola<T>::Buscar(string Nom){
    int a = 0;
    for(int i = 0; i <= ult; i++){
        if(datos[i].getNombre() == Nom){
            return i;
            a = 1;
        }
    }
    if(a == 0){
        cout<<"El alumno aún no tiene solicitud, por favor dar de alta la solicitud\n";
        int i=-1;
        return i;
    }
}

template<class T>
T Cola<T>::Front()const{
    if(primero()!=-1){
        T x = datos[primero()];
        return x;}
    else{
        T x = datos[0];
        return x;}
}

template<class T>
bool Cola<T>::Dequeue(){
    if(vacia()){
        return false;
    }
    else{
        elimina(primero());
    }
    return true;
}

template<class T>
bool Cola<T>::Queue(T& elem){
    if(llena()){
        return false;
    }
    if(vacia()){
        inserta(elem,0);
    }
    else{
        inserta(elem, ultimo()+1);
    }
    return true;
}

template<class T>
void Cola<T>::imprime()const{
    if(!vacia()){
        for(int i = 0; i <= ult; i++){
            Alumno x = datos[i];
            std::cout<<x<<std::endl;
        }
    }
}

template<class T>
bool Cola<T>::vacia()const{
    return ult == -1;
}

template<class T>
bool Cola<T>::llena()const{
    return ult == TAM-1;
}

template<class T>
bool Cola<T>::inserta(T elem, int pos){
    if(llena() || pos<0 || pos>ult+1){
        std::cout<<"\n No se pudo insertar";
        return false;
    }
    int i=ult+1;
    while(i>pos){
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    return true;
}

template<class T>
bool Cola<T>::elimina(int pos){
    if(vacia() || pos<0 || pos>ult){
        std::cout<<"\n No se pudo eliminar";
        return false;
    }
    int i=pos;
    while(i<ult){
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    return true;
}

template<class T>
T Cola<T>::recupera(int pos)const{
    if(vacia() || pos<0 || pos>ult-1){
        std::cout<<"\n Insuficiencia de datos";
        //Manejar exceptions
    }
    else{
       return datos[pos];
    }
}

template<class T>
int Cola<T>::primero()const{
    if(vacia()){
       return -1;
    }
    return 0;
}

template<class T>
int Cola<T>::ultimo()const{
    if(vacia()){
       return -1;
    }
    return ult;
}

int main()
{
    Cola<Alumno> MiCola;
    Alumno x;
    int pos,opc;
    string z;
    do{
        cout<<"MENU\n";
        cout<<"1-Dar de Alta un alumno: \n";
        cout<<"2-Crear una constancia: \n";
        cout<<"3-Buscar una solicitud de alumno: \n";
        cout<<"4-Salir: \n";
        cout<<"Elige una opcion: \t";
        cin>>opc;
        switch(opc){
            case 1:
                cin>>x;
                MiCola.Queue(x);
                break;
            case 2:
                x=MiCola.Front();
                if(!MiCola.Dequeue()){
                    cout<<"\nLa Cola esta vacia\n";
                }
                else
                    cout<<x<<endl;
                break;
            case 3:
                cout<<"\n\nQue Alumno deseas buscar?\n";
                cin>>z;
                pos = MiCola.Buscar(z);
                if(pos!=-1){
                    cout<<"\n\nEl nombre de la solicitud requerida se encuentra en la posicion: "<<pos;
                    cout<<"\n\nSe necesitan elaborar: "<<pos<<" constancias antes para poder elaborar la requerida";
                }
                break;
            case 4:
                break;
            default:
                cout<<"\nElige una opcion entre 1 y 4\n";
        }
    cout<<"\n\n\n";
    }while(opc!=4);
return 0;
}
