#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {

    string currencies[] = {
        "USD - US Dollar",
        "EUR - Euro",
        "GBP - British Pound",
        "JPY - Japanese Yen",
        "CNY - Chinese Yuan",
        "INR - Indian Rupee",
        "RUB - Russian Ruble",
        "AUD - Australian Dollar",
        "CAD - Canadian Dollar",
        "CHF - Swiss Franc",
        "SAR - Saudi Riyal",
        "AED - UAE Dirham",
        "IRR - Iranian Rial"
    };

    const int N = sizeof(currencies) / sizeof(currencies[0]);

  //no real amounts
    double rateToUSD[N] = {
        1.0,      // USD
        0.92,     // EUR
        0.80,     // GBP
        147.0,    // JPY
        7.2,      // CNY
        83.0,     // INR
        92.0,     // RUB
        1.55,     // AUD
        1.36,     // CAD
        0.92,     // CHF
        3.75,     // SAR
        3.67,     // AED
        42000.0   // IRR (iranian rial)
    };

    // currency list
    cout << "===================================" << endl;
    cout << "         CURRENCY CONVERTER" << endl;
    cout << "===================================" << endl;

    for (int i = 0; i < N; i++) {
        cout << i + 1 << ". " << currencies[i] << endl;
    }

    int from, to;
    double amount;

    // from currency
    cout << "\nEnter the number of the currency you want to convert FROM: ";
    cin >> from;

    // to currency
    cout << "Enter the number of the currency you want to convert TO: ";
    cin >> to;

    // enter amounts
    cout << "Enter the amount: ";
    cin >> amount;

    if (from < 1 || from > N || to < 1 || to > N) {
        cout << "Invalid choice!" << endl;
        return 0;
    }

    // logic
    // 1 : convert to USD
    double inUSD = amount / rateToUSD[from - 1];

    // 2 : Convert USD to target currency
    double result = inUSD * rateToUSD[to - 1];

    //  result
    cout << fixed << setprecision(2);
    cout << "\n" << amount << " " << currencies[from - 1]
         << " = " << result << " " << currencies[to - 1] << endl;

    cout << "===================================" << endl;
    cout << "bye" << endl;

    return 0;
}
