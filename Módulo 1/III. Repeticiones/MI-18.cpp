#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    
    int m = 0, count = 0;
    unsigned int number = 0;

    cin >> m;

    while(count <= m){
        number++;
        if(number % 3 && !(number%5==0)){
            cout << number << endl;
            count++;
        }
    }

    return 0;
}