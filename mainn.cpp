#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class Grafo{
	int V; 
	list<int> *adj;

public:
	Grafo(int V); 
	void adicionarAresta(int v1, int v2); 

	bool existeVizinho(int v1, int v2); 
};

Grafo::Grafo(int V){
	this->V = V; 
	adj = new list<int>[V];
}

void Grafo::adicionarAresta(int v1, int v2){
	
	adj[v1].push_back(v2);
    
}


bool Grafo::existeVizinho(int v1, int v2){
	if(find(adj[v1].begin(), adj[v1].end(), v2) != adj[v1].end())
		return true;
	return false;
}

void menu(){


}
int main(){
	
	Grafo grafo( int i);

       cout<<"insira o valor maximo de cidades:\t";
       int vmax;
       cin>> vmax;
       cout<<"\n escolha uma opcao a seguir:\t";
        int op;
        menu(); 
         cin>>op;
        while (op!= 5){

   	menu(); 
         cin>>op;
        }

	if(grafo.existeVizinho(0, 1))
		cout << "\n\n1 eh vizinho de 0\n";
	else
		cout << "\n\n1 NAO eh vizinho de 0\n";

	if(grafo.existeVizinho(0, 2))
		cout << "2 eh vizinho de 0\n";
	else
		cout << "2 NAO eh vizinho de 0\n";

	return 0;
}
