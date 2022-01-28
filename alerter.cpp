#include <iostream>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius, bool isNetworkOk) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    if (isNetworkOk) 
        std::cout << "Network is ok" << std::endl;
    else {
        std::cout << "Network is not-ok" << std::endl;
        return 500;
    }
    return 200;
}

int alertInCelcius(float farenheit, bool isNetworkOk) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius, isNetworkOk);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    } 
    return alertFailureCount;
}

int main() {  
    assert(alertInCelcius(400.5, false) != 0);
    assert(alertInCelcius(303.6, true) == 1);
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
