#include <iostream>
#include <vector>
#include <queue> 

using namespace std;

class Vertice{
	int indice;
	string nome;
	bool visitado = false;
	
public:
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
};

// class Grafo{
// 	vector<Vertice> *adj;
// 	vector<int> *adjDist;
// 	int totalVerices=0;

// public:
// 	Grafo(int v){
		
// 	}

// 	void bfs(Vertice inicio, Vertice fim);
// 	void adicionarAresta(Vertice v1, Vertice v2, int dist);
// };


// void Grafo::adicionarAresta(Vertice v1, Vertice v2, int dist)
// {
// 	adj[v1.getIndice()].push_back(v2);
// 	adjDist[v1.getIndice()].push_back(dist);
// 	if(totalVerices <= v1.getIndice())
// 		totalVerices = v1.getIndice();
	
// }

// void Grafo::bfs(Vertice inicio, Vertice fim){
	
	// Vertice atual = inicio;

	
	// queue<Vertice> fila;
		
				
	// while(!fim.getVisitado()){
	// 	if(!atual.getVisitado()){
	// 		atual.setVisitado();
	// 		fila.push(atual);
	// 	}

	// }
			
		// 	adj[*it].
		// 	if() 
		// 	{
		// 		cout << "Visitando vertice " << *it << " ...\n";
		// 		visitados[*it] = true; // marca como visitado
		// 		fila.push(*it); // insere na fila
		// 	}
		// }

		// // verifica se a fila NÃO está vazia
		// if(!fila.empty())
		// {
		// 	v = fila.front(); // obtém o primeiro elemento
		// 	fila.pop(); // remove da fila
		// }
		// else

// }




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



	// Grafo grafo(2);

	// // adicionando as arestas
	// grafo.adicionarAresta(Oradea,Zerind,71);
	// grafo.adicionarAresta(Oradea,Sibiu,151);
	// grafo.adicionarAresta(Zerind,Arad,75);
	// grafo.adicionarAresta(Sibiu,Fagaras,99);


	Oradea.printVertice();
	Zerind.printVertice();
	Sibiu.printVertice();
	Arad.printVertice();
	Fagaras.printVertice();
    

	return 0;
}