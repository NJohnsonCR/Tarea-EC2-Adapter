#include <iostream>
#include <memory>

using namespace std;
/**
 * @brief the class that represents the socket from Costa Rica, and needs to get adapted to other socket types.
 */
class CostaricanSocket{
    /**
     * @brief Method that receives an integer which is later used for choosing which adaption is needed.
     */
public:
    virtual void costaricanCharge(int ) = 0;
};

/**
 * @brief the class that represents the socket from USA.
 */
class USASocket {
public:
    /**
     * @brief Method that prints when the USA charger is plugged
     */
    void usaCharge(){
        cout << "The USA plug is charging. " << endl;
    }
};

/**
 * @brief the class that represents the socket from Germany.
 */
class GermanSocket{
public:
    /**
    * @brief Method that prints when the german charger is plugged.
    */
    void germanCharge(){
        cout << "The german plug is charging. " << endl;
    }
};

/**
 * @brief the class that represents the socket from Japan.
 */
class JapaneseSocket{
public:
    /**
     * @brief Method that prints when the japaneses charger is plugged
     */
    void japaneseCharge(){
        cout << "The japanese plug is charging. " << endl;

    }
};
/**
 * @brief The adapter class
 */
class SocketAdapter : public CostaricanSocket, public USASocket, public GermanSocket, public JapaneseSocket {
public:
    /**
     * Method used for adapting the costa rican socket to the different types.
     * @param adapter_type the type of charger that gets used.
     */
    void costaricanCharge(int adapter_type){
        switch (adapter_type) {
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