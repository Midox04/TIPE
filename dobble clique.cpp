#include "functions.h"


int main() {

  time_t start, end;
   time(&start);

    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);


    // Recording end time.



    // Initialize the graph.
   int n ,k;
  cin >> k >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    arr[i] = i+1;
  
  vector<int> data(k);
  vector<vector<int>> res;
  combinaisons(arr, n, k, 0, data, 0, res);
  vector<vector<int>> voisins_0;
  voisins_0.push_back(res[0]);
  for(int i=0;i<res.size();i++){
    if(une_intersection(res[0] , res[i]))
        voisins_0.push_back(res[i]);
  }
  bool** graphe = matrice(voisins_0.size() ,voisins_0);
  int taille = voisins_0.size();
  pair<int,vector<int>> Clique_max = renvoie_clique_max(graphe,taille);
  cout << "taille : " << Clique_max.first << endl;
  for (int i = 0; i < Clique_max.second.size(); i++) {
        for(int j=0;j<k;j++){
            cout << voisins_0[Clique_max.second[i]][j] << " ";
        }


        cout << endl;
    }
    time(&end);
    double time_taken = double(end - start);
     cout << "Time taken by program is : " << fixed
        << time_taken << setprecision(5);
    // Deallocate memory.
    for (int i = 0; i < taille; i++) {
        delete[] graphe[i];
    }
    delete[] graphe;

    return 0;
}
