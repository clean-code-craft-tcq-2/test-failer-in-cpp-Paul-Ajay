#include <iostream>
#include <assert.h>

int alertFailureCount = 0;

class networkAlert
{
public:
    virtual int checkNetworkStatus(float celcius, bool isNetworkOk) = 0;
    void printTempratureInCelcius() {
        std::cout << "ALERT: Temperature is " << this->celcius << " celcius.\n";
    }
    float convertFarenheitToCelcius(float farenheit) {
        return ((farenheit - 32) * 5 / 9);
    }
    float celcius;
};

class networkAlertStub : public networkAlert
{
public:
    int checkNetworkStatus(float celcius, bool isNetworkOk) {
        this->celcius = celcius;
        printTempratureInCelcius();
        if (isNetworkOk) {
            return 200;
        }
        else {
            return 500;
        }
    }
};

class networkAlertImpl : public networkAlert
{
public:
    int checkNetworkStatus(float celcius, bool isNetworkOk) {
        this->celcius = celcius;
        printTempratureInCelcius();
        if (isNetworkOk) {
            return 200;
        }
        else {
            return 500;
        }
    }

};


int alertInCelcius(float farenheit, networkAlert* networkAlertObject, bool isNetworkOk) {
    float celcius = networkAlertObject->convertFarenheitToCelcius(farenheit);
    int returnCode = networkAlertObject->checkNetworkStatus(celcius, isNetworkOk);
    if (returnCode != 200) {
        alertFailureCount += 1;
    } 
    return alertFailureCount;
}
 
int main() {

    networkAlert * networkAlertStubObject = new networkAlertStub();
    assert(alertInCelcius(400.5, networkAlertStubObject, false) == 1);
    assert(alertInCelcius(303.6, networkAlertStubObject, true) == 1);
    assert(alertInCelcius(97.4, networkAlertStubObject, false) == 2);
    std::cout << alertFailureCount << " alerts failed.\n";
    assert(alertFailureCount == 2);
    std::cout << "All is well (maybe!)\n";
    return 0;
}
