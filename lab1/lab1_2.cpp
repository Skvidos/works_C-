#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  cout << "Vvedite razmer klastera v bajtah (M): ";
  int M;
  cin >> M;

  cout << "Vvedite razmer fajla v megabajtah (V): ";
  float V;
  cin >> V;

  int fileSizeBytes = V * 1024 * 1024;

  int numClusters = ceil((float)fileSizeBytes / M);

  int bytesOccupied = numClusters * M;

  int lastClusterBytes = fileSizeBytes % M;

  int freeBytesInLastCluster = M - lastClusterBytes;

  cout << "Chislo svobodnyh bajt v poslednem klastere: " << freeBytesInLastCluster << endl;

  return 0;
}
