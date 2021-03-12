#include <iostream>
#include <stdio.h>  
#include <string.h> 


using namespace std;
const char *nombe_archivo = "archivo.dat";

struct Empleado{
	int codigo;
	char nombre[50];
	char apellido[50];
	char puesto [20];
	int salario;
	int bonificacion;
};
 void ingresar_empleado();
 void abrir_empleado();
 void modificar_empleado();

 
int main (){
	
	system ("COLOR 3 ");
	abrir_empleado();
    ingresar_empleado();
	modificar_empleado();

	return 0;	
}
void buscar_codigo(){
	
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int indice=0,pos=0,cod=0;
	cout<<"BUSCAR CODIGO DE EMPLEADO: ";
	cin>>cod;
	Empleado empleado;
	
	fread ( &empleado, sizeof(Empleado), 1, archivo );
		
		do{
			
			if (empleado.codigo == cod){
			pos = indice;
			}
	
		fread ( &empleado, sizeof(Empleado), 1, archivo );
		indice += 1;
		} while (feof( archivo ) == 0);
		
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Empleado), SEEK_SET );

    fread ( &empleado, sizeof( Empleado ), 1, archivo );

    	cout << "Codigo de empleado: " << empleado.codigo << endl;
        cout << "Nombre: " << empleado.nombre << endl;
        cout << "Apellido: " << empleado.apellido << endl;
        cout << "Puesto: " << empleado.puesto << endl;
        cout << "Sueldo Base Q.:	"<< empleado.salario << endl;
        cout << " Bonificacion Q.:	"<< empleado.bonificacion << endl;
         cout << "TOTAL DE SALARIO LIQUIDO"<< empleado.bonificacion + empleado.salario<<endl;
        cout << endl;
	
	fclose(archivo);
	system("PAUSE");
}


void buscar_indice(){
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int pos=0;
	cout<<"Que registro desea ver: ";
	cin>>pos;
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Empleado), SEEK_SET );
	
	Empleado empleado;
	
    fread ( &empleado, sizeof( Empleado ), 1, archivo );

    	cout << "Codigo de empleado: " << empleado.codigo << endl;
        cout << "Nombre: " << empleado.nombre << endl;
        cout << "Apellido: " << empleado.apellido << endl;
        cout << "Cargo : " << empleado.puesto<< endl;
        cout << "Sueldo Base Q.:"<< empleado.salario<< endl;
        cout << " Bonificacion Q.:"<< empleado.bonificacion<<endl;
        cout << "TOTAL DE SALARIO LIQUIDO"<< empleado.bonificacion + empleado.salario<<endl;
        cout << endl;
	
	fclose(archivo);

	
}


void abrir_empleado(){

	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	Empleado empleado;
	int registro=0;
	fread ( &empleado, sizeof(Empleado), 1, archivo );
	cout<<"______________________________________________________________________________________________________________________________________________________________________"<<endl;
	cout <<			 "ID" <<"|"<< "CODIGO" <<"|"<< 	"NOMBRE"<<" |"<<	"APELLIDO"<<"| "<<" PUESTO"<<"|"<<"SUELDO BASE"<<"|"<<"BONIFICACION"<<"|"<<"SALARIO LIQUIDO"<<"|"<<endl;
		do{
		cout<<"___________________________________________________________________________________________________________________________________________________________________"<<endl;
		cout <<registro<<"|"<<empleado.codigo<<"|	 "<< empleado.nombre<<"		|	 "<<empleado.apellido<<"	| "<<empleado.puesto<<" |	"<<"Q. "<<empleado.salario<<"	|	"<<"Q. "<<empleado.bonificacion<<"	|	"<< "Q."<<empleado.bonificacion + empleado.salario<<endl;
        
		fread ( &empleado, sizeof(Empleado), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
	}
void ingresar_empleado(){
	
	char continuar;
	FILE* archivo = fopen(nombe_archivo, "ab"); // ab
	
	
		Empleado empleado;
		 string nombre,apellido,puesto;
		do{
			fflush(stdin);
			
		cout<<"Ingrese el Codigo:";
		cin>>empleado.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(empleado.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(empleado.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el Puesto:";
		getline(cin,puesto);
		strcpy(empleado.puesto, puesto.c_str());
		
		cout <<"Ingrese el Salario Q.:  ";
		cin>>empleado.salario;
		cin.ignore();
		
		cout<<"Ingrese la bonificacion Q.:  ";
		cin>>empleado.bonificacion;
		cin.ignore();
		
		 cout << "TOTAL DE SALARIO LIQUIDO Q.:"<< empleado.bonificacion + empleado.salario<<endl;
		
		fwrite( &empleado, sizeof(Empleado), 1, archivo );
		
		cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
	abrir_empleado();
	//buscar_indice();	
	buscar_codigo();
}
void modificar_empleado(){
	
	FILE* archivo = fopen(nombe_archivo, "r+b");
	
		int id;
		string nombre,apellido,puesto;
    	Empleado empleado;
    
		cout << "Ingrese el ID que desea Modificar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(Empleado), SEEK_SET );  // esto es lo que permite modificar en la pocision
	
		cout<<"Ingrese el Codigo:";
		cin>>empleado.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(empleado.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(empleado.apellido, apellido.c_str()); 
		
			cout<<"Ingrese el Puesto:";
		getline(cin,puesto);
		strcpy (empleado.puesto, puesto.c_str());
		
		cout <<"Ingrese el Salario Q.: ";
		cin>>empleado.salario;
		cin.ignore();
		
		cout<<"Ingrese la bonificacion Q.:  ";
		cin>>empleado.bonificacion;
		cin.ignore();
		
		fwrite( &empleado, sizeof(Empleado), 1, archivo );
		
	fclose(archivo);
	abrir_empleado();
		system("PAUSE");
}



