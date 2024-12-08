#include <iostream>
using namespace std;

class Pizza {
public:
    int size, qty, priceS = 100, priceM = 150, priceL = 200, cost;

    void order() {
        cout << "Enter choice for the size (1.Small 2.Medium 3.Large): ";
        cin >> size;

        // Validating size input
        while (size < 1 || size > 3) {
            cout << "Invalid choice! Please enter a valid size (1.Small 2.Medium 3.Large): ";
            cin >> size;
        }

        cout << "Enter the quantity: ";
        cin >> qty;

        // Validating quantity input
        while (qty <= 0) {
            cout << "Quantity must be greater than 0. Please enter the quantity again: ";
            cin >> qty;
        }

        // Calculate cost based on the size
        if (size == 1) {
            cost = priceS * qty;
        } else if (size == 2) {
            cost = priceM * qty;
        } else {
            cost = priceL * qty;
        }

        cout << "Order placed successfully!" << endl;
    }

    void display() {
        cout << "\t";
        if (size == 1) {
            cout << "Small";
        } else if (size == 2) {
            cout << "Medium";
        } else {
            cout << "Large";
        }
        cout << "\t" << qty << "\t\t" << cost << endl;
    }

    void delDisplay() {
        cout << "Size: ";
        if (size == 1) {
            cout << "Small";
        } else if (size == 2) {
            cout << "Medium";
        } else {
            cout << "Large";
        }
        cout << "\nQuantity: " << qty;
        cout << "\nCost: " << cost << "\n\n";
    }
};

int main() {
    Pizza p[10];
    int ch, cnt;
    int top = -1, front = -1, rear = -1, s = 10;

    do {
        cout << "1.Place order\n2.Deliver order\n3.Display\n4.Exit\nEnter choice: \n";
        cin >> ch;

        switch (ch) {
            case 1:  // Place an order
                if (rear == s - 1) {
                    cout << "Order list is full." << endl;
                } else {
                    rear++;
                    p[rear].order();
                    if (front == -1) {
                        front = 0;
                    }
                }
                break;

            case 2:  // Deliver order
                if (front == -1 || rear < front) {
                    cout << "Order list is empty." << endl;
                } else {
                    cout << "Order delivered:" << endl;
                    p[front].delDisplay();
                    front++;
                    cout << "Order Delivered successfully!" << endl;
                }

                if (front > rear) {
                    front = -1;
                    rear = -1;
                }
                break;

            case 3:  // Display all orders
                if (front == -1) {
                    cout << "No orders to display." << endl;
                } else {
                    cnt = 1;
                    cout << "Orders:" << endl;
                    cout << "Sr.no\tSize\tQuantity\tCost" << endl;
                    for (int i = front; i <= rear; i++) {
                        cout << cnt << "\t";
                        p[i].display();
                        cnt++;
                    }
                }
                break;

            case 4:  // Exit
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
                break;
        }
    } while (ch != 4);

    return 0;
}
