#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    
    int n = 0, m = 0;

    for (int i = 0; i < 10; i++){
        cin >> n;
        m = n > m ? n : m;
    }

    cout << "El mayor es: " << m;
    
    return 0;
}