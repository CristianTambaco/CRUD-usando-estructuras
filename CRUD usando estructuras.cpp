#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

struct libro{
    string codigo;
    string titulo;
    int anio;
    bool estado; // 1 True :Disponible y 0 False: Prestado
};

vector<libro> listaLibros = {
    {"L001", "Una_breve_historia_del_tiempo", 1988, true},
    {"L002", "Don_Quijote_de_la_Mancha", 1605, true},
    {"L003", "La_sombra_del_viento", 2001, true},
    {"L004", "Padre_Rico_Padre_Pobre", 1997, true},
    {"L005", "El_nombre_de_la_rosa", 1980, true},
};

//READ(leer todos los registros)
vector <libro> leer() {
	vector<libro> libros;
	libros =  listaLibros;
	
	return libros;
}


//READ (leer un solo registro)
libro buscar(const string& codigo){
	libro libroB;
	libroB.codigo = "No encontrado";
	
		for(const auto& li : leer ()) {
			if (codigo == li.codigo) {
				libroB=li;
				break;
			}
		}
		return libroB;
}

//CREATE (Agregar un nuevo registro)
void agregar(const libro& nuevoLibro){
	auto it = find_if (listaLibros.begin(), listaLibros.end(),
	[&] (const libro& l) { return l.codigo == nuevoLibro.codigo; });
	
	if (it == listaLibros.end()) {
		listaLibros.push_back(nuevoLibro);
		cout <<"Libro con codigo " << nuevoLibro.codigo << " ha sido agregado." << endl;
	} else {
		cout << "El libro con codigo " << nuevoLibro.codigo << " ya existe. " << endl;
	}
	
}

//DELETE (Eliminar un registro existente)
void eliminar(const string& codigo) {
	auto it = remove_if(listaLibros.begin(), listaLibros.end(),
		[&] (const libro& l) { return l.codigo == codigo; });
		
		if (it != listaLibros.end()) {
			listaLibros.erase(it, listaLibros.end());
			cout<< "Libro con el codigo " << codigo << " ha sido eliminado." << endl;
		}else {
			cout<< "El libro con el codigo " << codigo << " no se encontro." << endl;
		}
			
}


//Actualizar
void actualizarLibro(const libro& libroActualizado) {
	auto it = find_if(listaLibros.begin(), listaLibros.end(),
		[&](const libro& l) { return l.codigo == libroActualizado.codigo; });
		
		if( it != listaLibros.end()) {
			//Actualiza los campos del libro encontrado
			it->titulo = libroActualizado.titulo;
			it->anio = libroActualizado.anio;
			it->estado = libroActualizado.estado;
			cout << "Libro con el codigo " << libroActualizado.codigo
			<< " ha sido actualizado." << endl;
		} else {
			cout << "El libro con el codigo " << libroActualizado.codigo
			<< " no se encontro." <<endl;
		}

}



int main(){
	
//________________________________________________________________________________________________________________________

	for (const auto& li : leer()) {
		cout<< li.codigo << "; " <<li.titulo << "; " << li.anio
		<< "; " << (li.estado ? "Disponible" : "Prestado") << endl;
	}
	
	cout <<"-------------------------------------------------------"<<endl;

//________________________________________________________________________________________________________________________
    
    libro li=buscar("L002");
    
    cout << li.codigo << "; " << li.titulo << "; " << li.anio
		<<"; " << (li.estado ? "Disponible" : "Prestado") << endl;
		
    cout <<"-------------------------------------------------------"<<endl;
		
//________________________________________________________________________________________________________________________
		
	agregar({"L006", "Nuevo_Libro", 2024, true});
	
	for (const auto& li : leer()) {
		cout << li.codigo << "; " << li.titulo << "; " << li.anio << "; "
			<< (li.estado ? "Disponible" : "Prestado") << endl;
	}
	
	cout <<"-------------------------------------------------------"<<endl;

//________________________________________________________________________________________________________________________	

	eliminar("L001");

	for (const auto& li : leer()) {
		cout << li.codigo << "; " << li.titulo << "; " << li.anio << ";"
			<<(li.estado ? "Disponible" : "Prestado") << endl;
	}

    cout <<"-------------------------------------------------------"<<endl;

//________________________________________________________________________________________________________________________	

actualizarLibro({"L003", "La_sombra_del_viento", 2024, false});

for (const auto& li : leer()) {
	cout << li.codigo << "; " << li.titulo << "; " << li.anio << ";"
	<< (li.estado ? "Disponible" : "Prestado") << endl;
}
cout <<"-------------------------------------------------------"<<endl;


    return 0;
}




































