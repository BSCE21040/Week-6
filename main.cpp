#include"function.h"

int main()
{
    int choice;
    int numCement;
    int numGravel;
    int numSand;
    Sack s;
    do 
    {
        cout << "1. Check the contents and weight of a single sack" << endl;
        cout << "2. Check a customer order for delivery" << endl;
        cout << "3. Calculate the price for a customer order" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter: ";
        cin >> choice;
        switch (choice) 
        {
        case 1:
        {
            s.processOrder();
            break;
        }
        case 2:
        {
            cout << "Enter the number of sacks of cement, gravel, and sand in the order:\n";
            cout << "Cement: ";
            cin >> numCement;
            cout << "Gravel: ";
            cin >> numGravel;
            cout << "Sand: ";
            cin >> numSand;
            int totalSacks = numCement + numGravel + numSand;
            int rejectedSacks = 0;
            float totalWeight = 0.0;
            for (int i = 0; i < numCement; ++i) {
                //Sack sack;
                s.content = 'C';
                cout << "Enter the weight of the cement sack in kilograms: ";
                cin >> s.weight;
                if (s.checkSack(s)) {
                    totalWeight += s.weight;
                }
                else {
                    ++rejectedSacks;
                }
            }
            for (int i = 0; i < numGravel; ++i) {
                //Sack sack;
                s.content = 'G';
                cout << "Enter the weight of the gravel sack in kilograms: ";
                cin >> s.weight;
                if (s.checkSack(s)) {
                    totalWeight += s.weight;
                }
                else {
                    ++rejectedSacks;
                }
            }
            for (int i = 0; i < numSand; ++i) {
                //Sack sack;
                s.content = 'S';
                cout << "Enter the weight of the sand sack in kilograms: ";
                cin >> s.weight;

                if (s.checkSack(s)) {
                    totalWeight += s.weight;
                }
                else {
                    ++rejectedSacks;
                }
            }
            cout << "Total weight of the order: " << totalWeight << " kg" << endl;
            cout << "Number of sacks rejected from the order: " << rejectedSacks << endl;
            break;
        }
        case 3:
        {
            int regularPrice = s.calculateRegularPrice(numCement, numGravel, numSand);
            int numDiscountPacks = s.calculateDiscountPacks(numCement, numGravel, numSand);
            int discountPrice = s.calculateDiscountPrice(numDiscountPacks);
            int amountSaved = s.calculateAmountSaved(numDiscountPacks);
            cout << fixed << setprecision(2);
            cout << "Regular price for the order: $" << regularPrice << endl;
            cout << "Discount price for the order: $" << discountPrice << endl;
            cout << "Amount saved: $" << amountSaved << endl;
            break;
        }
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 4);

    return 0;
}
