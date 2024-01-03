#include<iostream>
#include <iomanip>
using namespace std;

const double MIN_WEIGHT_GRAVEL_SAND = 49.9;
const double MAX_WEIGHT_GRAVEL_SAND = 50.1;
const double MIN_WEIGHT_CEMENT = 24.9;
const double MAX_WEIGHT_CEMENT = 25.1;
const double PRICE_CEMENT = 3.0;
const double PRICE_GRAVEL = 2.0;
const double PRICE_SAND = 2.0;
const double DISCOUNT_PACK_PRICE = 10.0;
const int SPECIAL_PACK_CEMENT = 1;
const int SPECIAL_PACK_GRAVEL = 2;
const int SPECIAL_PACK_SAND = 2;

struct Sack {
    char content;
    double weight;

    bool checkSack(const Sack& sack) {
        if ((sack.content == 'C' && sack.weight >= MIN_WEIGHT_CEMENT && sack.weight <= MAX_WEIGHT_CEMENT) ||
            ((sack.content == 'G' || sack.content == 'S') &&
                sack.weight >= MIN_WEIGHT_GRAVEL_SAND && sack.weight <= MAX_WEIGHT_GRAVEL_SAND)) {
            return true;
        }
        else {
            cout << "Rejected sack - ";
            if (sack.content == 'C') {
                cout << "Invalid weight for cement.\n";
            }
            else if (sack.content == 'G' || sack.content == 'S') {
                cout << "Invalid weight for gravel or sand.\n";
            }
            else {
                cout << "Invalid content.\n";
            }
            return false;
        }
    }

    void processOrder() {
        int numCement, numGravel, numSand;
        int rejectedSacks = 0;
        double totalWeight = 0.0;

        cout << "Enter the number of sacks of cement, gravel, and sand in the order:\n";
        cout << "Cement: ";
        cin >> numCement;
        cout << "Gravel: ";
        cin >> numGravel;
        cout << "Sand: ";
        cin >> numSand;

        for (int i = 0; i < numCement; ++i) {
            Sack sack;
            sack.content = 'C';
            cout << "Enter the weight of the cement sack in kilograms: ";
            cin >> sack.weight;

            if (checkSack(sack)) {
                totalWeight += sack.weight;
            }
            else {
                ++rejectedSacks;
            }
        }

        for (int i = 0; i < numGravel; ++i) {
            Sack sack;
            sack.content = 'G';
            cout << "Enter the weight of the gravel sack in kilograms: ";
            cin >> sack.weight;

            if (checkSack(sack)) {
                totalWeight += sack.weight;
            }
            else {
                ++rejectedSacks;
            }
        }

        for (int i = 0; i < numSand; ++i) {
            Sack sack;
            sack.content = 'S';
            cout << "Enter the weight of the sand sack in kilograms: ";
            cin >> sack.weight;

            if (checkSack(sack)) {
                totalWeight += sack.weight;
            }
            else {
                ++rejectedSacks;
            }
        }

        cout << "Total weight of the order: " << totalWeight << " kg\n";
        cout << "Number of sacks rejected from the order: " << rejectedSacks << endl;
    }

    double calculateRegularPrice(int numCement, int numGravel, int numSand) {
        return numCement * PRICE_CEMENT + numGravel * PRICE_GRAVEL + numSand * PRICE_SAND;
    }

    int calculateDiscountPacks(int numCement, int numGravel, int numSand) {
        int numDiscountPacks = min(min(numCement / SPECIAL_PACK_CEMENT, numGravel / SPECIAL_PACK_GRAVEL), numSand / SPECIAL_PACK_SAND);
        return numDiscountPacks;
    }

    double calculateDiscountPrice(int numDiscountPacks) {
        return numDiscountPacks * DISCOUNT_PACK_PRICE;
    }

    double calculateAmountSaved(int numDiscountPacks) {
        return numDiscountPacks * (PRICE_CEMENT * SPECIAL_PACK_CEMENT + PRICE_GRAVEL * SPECIAL_PACK_GRAVEL +
            PRICE_SAND * SPECIAL_PACK_SAND) - calculateDiscountPrice(numDiscountPacks);
    }
};
