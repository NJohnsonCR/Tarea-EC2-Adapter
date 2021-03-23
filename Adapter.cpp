#include <iostream>
#include <memory>

using namespace std;

class CostaricanSocket{
public:
    virtual void costaricanCharge(int ) = 0;
};

class USASocket {
public:
    void usaCharge(){
        cout << "The USA plug is charging. " << endl;
    }
};

class GermanSocket{
public:
    void germanCharge(){
        cout << "The german plug is charging. " << endl;
    }
};

class JapaneseSocket{
public:
    void japaneseCharge(){
        cout << "The japanese plug is charging. " << endl;

    }
};

class SocketAdapter : public CostaricanSocket, public USASocket, public GermanSocket, public JapaneseSocket {
public:
    void costaricanCharge(int tmp){
        switch (tmp) {
            case 1:
                usaCharge();
                break;
            case 2:
                germanCharge();
                break;
            case 3:
                japaneseCharge();
                break;
            default:
                break;
        }
    }
};
int main(){
    unique_ptr<CostaricanSocket> socket = make_unique<SocketAdapter>();
    socket->costaricanCharge(1);
    socket->costaricanCharge(2);
    socket->costaricanCharge(3);

    return 0;
}