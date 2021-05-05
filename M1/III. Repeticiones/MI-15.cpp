#include <iostream>

using namespace std;

// without arrays, functions and string type

int main(){
    int infringement_type = 0, fine_value = 0, closure = 0;
    int l_sum = 0, m_sum = 0, g_sum = 0; // for each severity
    char infringement_severity, infringement_reason[24];
    
    for(int i = 0; i < 20; i++){
        cout << "> Infringement number " << i + 1 << endl;

        while(infringement_type < 1 || infringement_type > 4){
            cout << "Infingement type: "; 
            cin >> infringement_type;
        }

        cout << "Infingement reason: "; 
        cin >> infringement_reason;

        cout << "Fine value: "; 
        cin >> fine_value;

        while(infringement_severity != 'L' && infringement_severity != 'M' && infringement_severity != 'G'){
            cout << "Infingement severity: ";
            cin >> infringement_severity;
        }

        switch(infringement_severity){
            case 'L': 
                l_sum += fine_value;
                break;
            case 'M':
                m_sum += fine_value;
                break;
            case 'G':
                g_sum += fine_value;
                break;
        }

        if((infringement_type == 3 || infringement_type == 4) && infringement_severity == 'G') closure++;
    }

    cout << "Total L severity: " << l_sum << endl;
    cout << "Total M severity: " << m_sum << endl;
    cout << "Total G severity: " << g_sum << endl;

    if(closure > 3) cout << "Close the factory";

    return 0;
}