#include <iostream>
#include <assert.h>

int alertFailureCount = 0;

class networkAlert
{
public:
    virtual int checkNetworkStatus(bool isNetworkOk) = 0;
};

class networkAlertStub : public networkAlert
{
public:
    int checkNetworkStatus(bool isNetworkOk) {
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
    int checkNetworkStatus(bool isNetworkOk) {
        return 200;
    }

};

float convertFarenheitToCelcius(float farenheit) {
    return ((farenheit - 32) * 5 / 9);
}

int alertInCelcius(float farenheit, networkAlert* networkAlertObject, bool isNetworkOk) {
    float celcius = convertFarenheitToCelcius(farenheit);
    int returnCode = networkAlertObject->checkNetworkStatus(isNetworkOk);
    if (returnCode != 200) {
        alertFailureCount += 1;
    } 
    return alertFailureCount;
}
 
int main() {

    networkAlert * networkAlertStubObject = new networkAlertStub();
    assert(alertInCelcius(400.5, networkAlertStubObject, false) == 1);
    assert(alertInCelcius(303.6, networkAlertStubObject, true) == 1);
    assert(alertInCelcius(303.6, networkAlertStubObject, false) == 2);
    std::cout << alertFailureCount << " alerts failed.\n";
    assert(alertFailureCount == 2);
    std::cout << "All is well (maybe!)\n";
    return 0;
}
