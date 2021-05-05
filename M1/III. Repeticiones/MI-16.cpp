#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    
    int number = 1, count = 0;

    while (number > 0){
        count++;
        cout << "Sum inputs: " << count << endl;
        cin >> number;
    }

    return 0;
}