#include <iostream>

using namespace std;

int main(){
    int n = 0, m = 0, producto = 0;

    cin >> n >> m;

    for (int i = 0; i < m; i++) producto += n;

    cout << "Producto por sumas sucesivas " << producto;

    return 0;
}