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
	queue<Vertice*> borda;
	vector<Vertice*> explorados;

public:
	Grafo(){

	}

	void bfs(Vertice *inicial, Vertice *final){
		Vertice *atual = inicial;
		atual->setVisitado();
		cout << "Iniciando Busca de rota " << endl;
		cout << "Rota: de Cidade " << inicial->getNome() << " ate Cidade " << final->getNome() << endl;
		cout << "Iniciando a partir da cidade " << inicial->getNome() << endl;
		while(!final->getVisitado()){
			for(int i = 0 ; i < atual->adj.size(); i++){
				if(!atual->getAdj(i)->getVisitado()){
					cout << "Vistando cidade " << atual->getAdj(i)->getNome() << endl;
					atual->getAdj(i)->setVisitado();
					fila.push(atual->getAdj(i));
					if(final->getVisitado())
						break;	
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
		queue<Vertice*> fila_ex = fila;
		cout << "Borda: ";
		while(!fila_ex.empty()){
			cout << fila_ex.front()->getNome() << ", ";
			fila_ex.pop();
		}
		cout << endl;
	}

	bool contido_borda(Vertice* v1, queue<Vertice*> borda){
		queue <Vertice *> fila_aux = borda;
		for(int  i = 0; i < borda.size(); i++){
			if(v1 == fila_aux.front())
				return true;
			else
				fila_aux.pop();
		}
		return false;
	}

	bool contido_explorados(Vertice* v1, vector<Vertice*> explorados) {
		for(int  i = 0; i < explorados.size(); i++){
			if(v1 == explorados[i])
				return true;
		}
		return false;
	}


	void busca_em_largura(Vertice *inicial, Vertice *final) {
		Vertice *atual = inicial;
		if(atual == final){
				return;
		}
		borda.push(inicial);
		explorados.clear();
		while(true){
			if(borda.empty()){
				return;
			}
			atual = borda.front();
			borda.pop();
			explorados.push_back(atual);
			for(int i=0; i < atual->adj.size(); i++){
				if((contido_explorados(atual->adj[i], explorados) == false) || (contido_borda(atual->adj[i],borda) == true)){
					if(atual->adj[i] == final)
						return;
					borda.push(atual->adj[i]);
				}else{
					continue;
				}	
			}
		}
	}

	void mostrarExplorado(){
		cout << "Explorados: ";
		for(int i=0; i < explorados.size(); i ++){
			cout << explorados[i]->getNome() << " ";
		}
		cout << endl;
	}

	void mostrarBorda(){
		queue<Vertice *> fila_aux = borda;
		cout << "Bordas: ";
		for(int  i  = 0; i < borda.size(); i++){
			cout << fila_aux.front()->getNome() << " ";
			fila_aux.pop();
		}
		cout << endl;
	}
};


int main(){
	//Adicionando Vertices
	Vertice *Oradea  = new Vertice(1,"Oradea");
	Vertice *Zerind = new Vertice(2,"Zerind");
	Vertice *Arad = new Vertice(3,"Arad");
	Vertice *Timisoara = new Vertice(4,"Timisoara");
	Vertice *Lugoj = new Vertice(5,"Lugoj");
	Vertice *Mehadia = new Vertice(6,"Mehadia");
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

	//Caminhos de Oradea
	Oradea->addAdj(Zerind,71);	
	Oradea->addAdj(Sibiu,151);
	//Caminhos de Zerind
	Zerind->addAdj(Arad,75);
	Zerind->addAdj(Oradea,71);
	//Caminhos de Sibiu
	Sibiu->addAdj(Fagaras,99);
	Sibiu->addAdj(RimnicuVilecea,80);
	Sibiu->addAdj(Oradea,71);
	Sibiu->addAdj(Arad,140);
	//Caminhos de Fagaras
	Fagaras->addAdj(Sibiu,99);
	Fagaras->addAdj(Bucharest,211);
	//Caminhos de Rimnicu Vilecea
	RimnicuVilecea->addAdj(Sibiu,80);
	RimnicuVilecea->addAdj(Pitesti,97);
	RimnicuVilecea->addAdj(Craiova,146);
	//Caminhos de Arad
	Arad->addAdj(Timisoara,118);
	Arad->addAdj(Zerind,75);
	Arad->addAdj(Sibiu,140);
	//Caminhos de Timisoara
	Timisoara->addAdj(Arad,118);
	Timisoara->addAdj(Lugoj,111);
	//Caminhos de Lugoj
	Lugoj->addAdj(Timisoara,111);
	Lugoj->addAdj(Mehadia,70);
	//Caminhos de Mehadia
	Mehadia->addAdj(Lugoj,70);
	Mehadia->addAdj(Drobeta,75);
	//Caminhos de Dobreta
	Drobeta->addAdj(Mehadia,75);
	Drobeta->addAdj(Craiova,120);
	//Caminhos de Craiova
	Craiova->addAdj(Drobeta,120);
	Craiova->addAdj(RimnicuVilecea,146);
	Craiova->addAdj(Pitesti,138);
	//Caminhos de Pitesti
	Pitesti->addAdj(Craiova,138);
	Pitesti->addAdj(RimnicuVilecea,97);
	Pitesti->addAdj(Bucharest,101);
	//Caminhos de Bucharest
	Bucharest->addAdj(Pitesti,101);
	Bucharest->addAdj(Fagaras,211);
	Bucharest->addAdj(Giurgiu,90);
	Bucharest->addAdj(Urziceni,85);
	//Caminhos de Urziceni
	Urziceni->addAdj(Bucharest,85);
	Urziceni->addAdj(Hirsova,98);
	Urziceni->addAdj(Vaslui,142);
	//Caminhos de Giurgiu
	Giurgiu->addAdj(Bucharest,90);
	//Caminhos de Hisorva
	Hirsova->addAdj(Urziceni,98);
	Hirsova->addAdj(Eforie,86);
	//Caminhos de Eforie
	Eforie->addAdj(Hirsova,86);
	//Caminhos de Vaslui
	Vaslui->addAdj(Urziceni,142);
	Vaslui->addAdj(Iasi,92);
	//Caminhos de Iasi
	Iasi->addAdj(Vaslui,92);
	Iasi->addAdj(Neamt,87);
	//Caminhos de Giugiu
	Giurgiu->addAdj(Iasi,87);


	Grafo grafo;
	// grafo.bfs(Arad, Bucharest);
	grafo.busca_em_largura(Arad, Oradea);
	grafo.mostrarExplorado();
	grafo.mostrarBorda();

	
	return 0;
}