#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const long long MOD = 1e9 + 7;
const int MAXN = 1e3;
#pragma GCC optimize(" unroll-loops")
#pragma gcc optimize("Ofast")
#pragma GCC optimization("Ofast")
#pragma optimize(Ofast)

void trouve_clique_maximum (ll int** graphe , int taille , vector<int>& currentClique , vector<int> candidats , vector<int>& cliqueMaximum ,int& taille_clique_max){

    if(candidats.empty()){
        if ( currentClique.size() > taille_clique_max){
            taille_clique_max = currentClique.size();
            cliqueMaximum = currentClique;
        }
        return;
    }

    int candidat = candidats[0];

    bool canAddCandidate = true;
    for (int i = 0; i < currentClique.size(); i++) {
        if (graphe[candidat][currentClique[i]] == false) {
            canAddCandidate = false;
            break;
        }
    }

    if(canAddCandidate){
        currentClique.push_back(candidat);
        vector<int> candidats_restants;
        for(int i=1 ; i<candidats.size();i++){
            if(graphe[candidat][candidats[i]] == true){
              candidats_restants.push_back(candidats[i]);

            }

        }
        trouve_clique_maximum (graphe,taille,currentClique,candidats_restants,cliqueMaximum,taille_clique_max);
        currentClique.pop_back();

    }



        candidats.erase(candidats.begin());
        trouve_clique_maximum(graphe,taille,currentClique,candidats,cliqueMaximum,taille_clique_max);




}


pair<int,vector<int>> renvoie_clique_max (ll int** graphe ,int taille){

     vector<int> clique_max;
     int taille_clique_max = 0;
     vector<int> currentClique;
     vector<int> candidats;
     for(int i=0;i < taille;i++){
        if(graphe[0][i] == 1){
            candidats.push_back(i);
        }
     }

     trouve_clique_maximum(graphe, taille,currentClique,candidats,clique_max,taille_clique_max);
     return make_pair(taille_clique_max,clique_max);



}

bool une_intersection (vector<int>& v , vector<int>& data ){
  int cnt = 0;
  for(int i=0;i<data.size();i++){
    if( find(v.begin(),v.end(),data[i]) != v.end() ) {
      cnt ++ ;
    }
  }
  if (cnt == 1)
    return true ;
  return false;
}

void combinaisons(int arr[], int n, int r, int index, vector<int> data, int i,
                  vector<vector<int>> &res,vector<int>& carte) {

  if (index == r) {
    if (une_intersection (carte ,data)){
            res.push_back(data);}
    return;
  }

  if (i >= n)
    return;

  data[index] = arr[i];
  combinaisons(arr, n, r, index + 1, data, i + 1, res,carte);
  combinaisons(arr, n, r, index, data, i + 1, res,carte);
}

ll int** matrice(int taille , vector<vector<int>>& cartes){

  ll int** matrice = new ll int*[taille];
  for(int i = 0; i < taille; i++){
    matrice[i] = new ll int[taille];
  }
  for(int i = 0; i < taille; i++){
    for(int j = 0; j < taille; j++){
      if(une_intersection(cartes[i],cartes[j]) == true)
        matrice[i][j] = 1;
      else
        matrice[i][j] = 0;
    }
    matrice[i][i] = 1;
  }
  return matrice;
}


/******************************** Version vecteur d'adjacence *********************************/

vector<vector<int>> vecteur_adjacence(int taille , vector<vector<int>>& res){
  vector<vector<int>> vadj;
  for(int i=0;i<taille;i++){
     vadj.pb({i});}

   for(int i=0;i<taille;i++){
     for(int j=0;j<taille;j++){
       if(une_intersection(res[i],res[j]) ){
            if(i > j)
                vadj[j].push_back(i);
           else if (i<j)
                vadj[j].push_back(i);
       }
     }
   }
  return vadj;
}



bool connected( int i , int j , vector<vector<int>>& vadj ){
  int   a = min(i,j);
  int b = max(i,j);
  if(find(vadj[a].begin(),vadj[a].end(),b) != vadj[a].end()){
    return true;
  }
  return false;
}


void trouve_clique_maximum2 (vector<vector<int>>& vadj , int taille , vector<int>& currentClique , vector<int> candidats , vector<int>& cliqueMaximum ,int& taille_clique_max){

    if(candidats.empty()){
        if ( currentClique.size() > taille_clique_max){
            taille_clique_max = currentClique.size();
            cliqueMaximum = currentClique;
        }
        return;
    }

    int candidat = candidats[0];

    bool canAddCandidate = true;
    for (int i = 0; i < currentClique.size(); i++) {
        if (connected(candidat,currentClique[i],vadj) == false) {
            canAddCandidate = false;
            break;
        }
    }

    if(canAddCandidate){
        currentClique.push_back(candidat);
        vector<int> candidats_restants;
        for(int i=1 ; i<candidats.size();i++){
            if(connected(candidat,candidats[i],vadj) == true){
              candidats_restants.push_back(candidats[i]);

            }

        }
        trouve_clique_maximum2 (vadj,taille,currentClique,candidats_restants,cliqueMaximum,taille_clique_max);
        currentClique.pop_back();

    }



        candidats.erase(candidats.begin());
        trouve_clique_maximum2(vadj,taille,currentClique,candidats,cliqueMaximum,taille_clique_max);




}


pair<int,vector<int>> renvoie_clique_max2 (vector<vector<int>>& vadj ,int taille){

     vector<int> clique_max;
     int taille_clique_max = 0;
     vector<int> currentClique;
     vector<int> candidats;
     for(int i=0;i < taille;i++){
        if(connected(0,i,vadj) == 1){
            candidats.push_back(i);
        }
     }

     trouve_clique_maximum2(vadj, taille,currentClique,candidats,clique_max,taille_clique_max);
     return make_pair(taille_clique_max,clique_max);



}

/*************************** Implementation du graphe en utlisant set et hash map ************************************/


struct Graph {
    int V;
    set<int>* adjList;
};

// A utility function that creates a graph of V vertices
Graph* createGraph(int V)
{
    Graph* graph = new Graph;
    graph->V = V;

    // Create an array of sets representing
    // adjacency lists.  Size of the array will be V
    graph->adjList = new set<int >[V];

    return graph;
}

void addEdge(Graph* graph, int src, int dest)
{
    // Add an edge from src to dest.  A new
    // element is inserted to the adjacent
    // list of src.
    graph->adjList[src].insert(dest);

    // Since graph is undirected, add an edge
    // from dest to src also
    graph->adjList[dest].insert(src);
}


Graph* Constuire_graphe( int taille , vector<vector<int>>& res){
   Graph* graphe = createGraph(taille);
   for(int i=0;i<taille;i++){
    addEdge(graphe,i,i);
     for(int j=0;j<taille;j++){
       if(une_intersection(res[i],res[j]) ){
            addEdge(graphe,i,j);
       }
     }
   }

  return graphe;
}



bool searchEdge( int src, int dest,Graph* graph)
{
    auto itr = graph->adjList[src].find(dest);
    if (itr == graph->adjList[src].end())
        return false;
    else
       return true;
}
void trouve_clique_maximum3 (Graph* vadj , int taille , vector<int>& currentClique , vector<int> candidats , vector<int>& cliqueMaximum ,int& taille_clique_max){

    if(candidats.empty()){
        if ( currentClique.size() > taille_clique_max){
            taille_clique_max = currentClique.size();
            cliqueMaximum = currentClique;
        }
        return;
    }

    int candidat = candidats[0];

    bool canAddCandidate = true;
    for (int i = 0; i < currentClique.size(); i++) {
        if (searchEdge(candidat,currentClique[i],vadj) == false) {
            canAddCandidate = false;
            break;
        }
    }

    if(canAddCandidate){
        currentClique.push_back(candidat);
        vector<int> candidats_restants;
        for(int i=1 ; i<candidats.size();i++){
            if(searchEdge(candidat,candidats[i],vadj) == true){
              candidats_restants.push_back(candidats[i]);

            }

        }
        trouve_clique_maximum3 (vadj,taille,currentClique,candidats_restants,cliqueMaximum,taille_clique_max);
        currentClique.pop_back();

    }



        candidats.erase(candidats.begin());
        trouve_clique_maximum3(vadj,taille,currentClique,candidats,cliqueMaximum,taille_clique_max);




}


pair<int,vector<int>> renvoie_clique_max3 (Graph* vadj ,int taille){

     vector<int> clique_max;
     int taille_clique_max = 0;
     vector<int> currentClique;
     vector<int> candidats;
     for(int i=0;i < taille;i++){
        if(searchEdge(0,i,vadj) == 1){
            candidats.push_back(i);
        }
     }

     trouve_clique_maximum3(vadj, taille,currentClique,candidats,clique_max,taille_clique_max);
     return make_pair(taille_clique_max,clique_max);



}

