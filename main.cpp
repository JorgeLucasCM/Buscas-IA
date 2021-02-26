#include <iostream>
#include <vector>
#include <queue> 

using namespace std;

class Vertice{
public:
	int indice;
	string nome;
	bool visitado = false;
	vector<Vertice*> adj;
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

	void addAdj(Vertice *v1, int dist){
		this->adj.push_back(v1);
		this->adjDist.push_back(dist);
	}

	Vertice* getAdj(int pos){
		return this->adj[pos];
	}


	int getAdjDist(int pos){
		return this->adjDist[pos];
	}

};

class Grafo{
	queue<Vertice*> fila;

public:
	Grafo(){

	}

	void bfs(Vertice *inicial, Vertice *final){
		Vertice *atual = inicial;
		cout << "Iniciando da cidade " << inicial->getNome() << endl;
		while(true){
			for(int i = 0 ; i < atual->adj.size(); i++){
				if(!atual->getAdj(i)->getVisitado()){
					cout << "Vistando cidade " << atual->getAdj(i)->getNome() << endl;
					atual->getAdj(i)->setVisitado();
					fila.push(atual->getAdj(i));
				}
			}	
			if(!fila.empty()){
				atual = fila.front();
				fila.pop();
			}else{
				break;
			}
		}
		cout<< "Chegou ao seu destino! " <<endl;
	}
};




int main(){
	//Adicionando Vertices
	Vertice *Oradea  = new Vertice(1,"Oradea");
	Vertice *Zerind = new Vertice(2,"Zerind");
	Vertice *Arad = new Vertice(3,"Arad");
	Vertice *Timisoara = new Vertice(4,"Timisoara");
	Vertice *Lugoj = new Vertice(5,"Lugoj");
	Vertice *Mehadia = new Vertice(6,"Mhadia");
	Vertice *Drobeta = new Vertice(7,"Drobeta");
	Vertice *Craiova = new Vertice(8,"Craiova");
	Vertice *Pitesti = new Vertice(9,"Pitesti");
	Vertice *RimnicuVilecea = new Vertice(10,"RimnicuVilecea");
	Vertice *Sibiu = new Vertice(11,"Sibiu");
	Vertice *Fagaras = new Vertice(12,"Fagaras");
	Vertice *Bucharest = new Vertice(13,"Bucharest");
	Vertice *Giurgiu = new Vertice(14,"Giurgiu");
	Vertice *Urziceni = new Vertice(15,"Urziceni");
	Vertice *Hirsova = new Vertice(16, "Hirsova");
	Vertice *Eforie = new Vertice(17, "Eforie");
	Vertice *Vaslui = new Vertice(18, "Vaslui");
	Vertice *Iasi = new Vertice(19, "Iasi");
	Vertice *Neamt = new Vertice(20, "Neamt");

	Oradea->addAdj(Zerind,71);	
	Oradea->addAdj(Sibiu,151);
	Zerind->addAdj(Arad,75);
	Sibiu->addAdj(Fagaras,99);

	


	Grafo grafo;
	grafo.bfs(Oradea, Fagaras);



	// Grafo grafo(2);

	// // adicionando as arestas
	// grafo.adicionarAresta(Oradea,Zerind,71);
	// grafo.adicionarAresta(Oradea,Sibiu,151);
	// grafo.adicionarAresta(Zerind,Arad,75);
	// grafo.adicionarAresta(Sibiu,Fagaras,99);


    

	return 0;
}