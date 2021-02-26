#include <iostream>
#include <vector>
#include <queue> 

using namespace std;

class Vertice{
public:
	int indice;
	string nome;
	bool visitado = false;
	vector<Vertice> adj;
	vector<int> adjDist;
public:
	Vertice(){

	}
	Vertice(int indice,string nome){
		this-> indice = indice;
		this-> nome = nome;
	}

	string getNome(){

		return this->nome;
	}

	int getIndice(){
		return this->indice;
	}

	void setVisitado(){
		this->visitado = true;
	}

	bool getVisitado(){
		return this->visitado;
	}

	void printVertice(){
		cout << indice << " " << nome << " " << visitado << endl;
	}

	void addAdj(Vertice v1, int dist){
		this->adj.push_back(v1);
		this->adjDist.push_back(dist);
	}

	Vertice getAdj(int pos){
		return this->adj[pos];
	}


	int getAdjDist(int pos){
		return this->adjDist[pos];
	}

};

class Grafo{
	queue<Vertice> fila;

public:
	Grafo(){

	}

	void bfs(Vertice inical, Vertice final){
		
	}
};




int main(){
	//Adicionando Vertices
	Vertice Oradea(1,"Oradea");
	Vertice Zerind(2,"Zerind");
	Vertice Arad(3,"Arad");
	Vertice Timisoara(4,"Timisoara");
	Vertice Lugoj(5,"Lugoj");
	Vertice Mehadia(6,"Mhadia");
	Vertice Drobeta(7,"Drobeta");
	Vertice Craiova(8,"Craiova");
	Vertice Pitesti(9,"Pitesti");
	Vertice RimnicuVilecea(10,"RimnicuVilecea");
	Vertice Sibiu(11,"Sibiu");
	Vertice Fagaras(12,"Fagaras");
	Vertice Bucharest(13,"Bucharest");
	Vertice Giurgiu(14,"Giurgiu");
	Vertice Urziceni(15,"Urziceni");
	Vertice Hirsova(16, "Hirsova");
	Vertice Eforie(17, "Eforie");
	Vertice Vaslui(18, "Vaslui");
	Vertice Iasi(19, "Iasi");
	Vertice Neamt(20, "Neamt");

	Oradea.addAdj(Zerind,71);
	Oradea.addAdj(Sibiu,151);
	Zerind.addAdj(Arad,75);
	Sibiu.addAdj(Fagaras,99);



	// Grafo grafo(2);

	// // adicionando as arestas
	// grafo.adicionarAresta(Oradea,Zerind,71);
	// grafo.adicionarAresta(Oradea,Sibiu,151);
	// grafo.adicionarAresta(Zerind,Arad,75);
	// grafo.adicionarAresta(Sibiu,Fagaras,99);


    

	return 0;
}