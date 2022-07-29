// Pedro Marcelino Mendes Novaes Melo
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <list>
#include <set>

using namespace std;

// usando a estrutura vector como grafo
vector<int> grafo[50001];

// usando a estrutura de arvore binaria como fila para execucao
// da ordenacao topologica
set<int> fila;

int grau[50001];
int saida[50001];

int main(){
	int N, M, i, A, B, aceito = 0, k = 0;

	scanf(" %d %d", &N, &M);

	for(i = 0; i < N; i++){
		grafo[i].clear();
		grau[i] = 0;
	}

	for(i = 0; i < M; i++){
		scanf(" %d %d", &A, &B);
		grafo[A].push_back(B);
		grau[B]++;
	}

	// ------------------ aqui comeca a ordenacao topologica ------------------ //

	for(i = 0; i < N; i++){
		if(grau[i] == 0){
			fila.insert(i);
			grau[i]--;
			aceito = 1;
		}
	}

	if(aceito == 0){
		printf("*\n");
		return 0;
	}

	while(fila.size() != 0){
		int u = *fila.begin();
		fila.erase(u);
		saida[k] = u;
		k++;

		for(std::vector<int>::iterator i = grafo[u].begin(); i != grafo[u].end(); ++i){
			int verts = *i;
			if(grau[verts] >= 1){
				grau[verts]--;
				if(grau[verts] == 0){
					fila.insert(verts);
					grau[verts]--;
				}
			}
		}
	}

	if(k == N)
		aceito = 1;
	else
		aceito = 0;

	if(aceito == 0)
		printf("*\n");
	else{
		for(i = 0; i < N; i++)
			printf("%d\n", saida[i]);
	}

	return 0;
}