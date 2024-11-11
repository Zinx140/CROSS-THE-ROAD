#include <iostream>
#include <random>

using namespace std;

int main() {
    int i, j, a, b, c, d, e, f, stop, speeda, speedb, speedc, speedd, speede, speedf;// a - f kecepatan
    int k = 14; // spawn
    int y = 20; // spawn
    a = 2;
    c = 2;
    d = 2;
    b = 28;
    e = 28;
    f = 28;
    //random speed
    random_device rd;
    uniform_int_distribution<int>dist(1,12);

    char move;
    // arena dan aturan nya
    for (stop = 1; stop <= 2;) {
        for (i = 1 ;i <= 21; i++) {
            if (i == 2) {
                cout << "#----------FINISH!----------#";
            }
            for (j = 1; j <= 29; j++) {
                if ((i == 1 || j == 1 || i == 21 || j == 29) && i != 2) {
                    cout << "#";
                } else if (i == y && j == k) {
                    cout << "P";
                } else if (j == a && (i == 18 || i == 8)) {
                    cout << "=";
                } else if (j == b && (i == 16 || i == 14 || i == 6)) {
                    cout << "=";
                } else if (a >= 28) {
                    a = 2;
                } else if (b <= 2) {
                    b = 27;
                } else if (j == c && (i == 15 || i == 10 || i == 13)) {
                    cout << "=";
                } else if (j == d && (i == 26 || i == 5)) {
                    cout << "=";
                } else if (j == e && (i == 23 || i == 9)) {
                    cout << "=";
                } else if (j == f && (i == 4 || i == 11)) {
                    cout << "=";
                } else if (e <= 2) { //pembatas gerakan
                    e = 28;
                } else if (f <= 2) {
                    f = 28;
                } else if (c >= 28) {
                    c = 2;
                } else if (d >= 28) {
                    d = 2;
                } else {
                    cout << " ";
                }
            }
            cout << endl;
        }

            // hitbox
            if ((k == a && (y == 18 || y == 8)) || (k == b && (y == 16 || y == 14 || y == 6)) || (k == c && (y == 15 || y == 10 || y == 13)) ||
                (k == d && (y == 26 || y == 5)) || (k == e && (y == 23 || y == 9))
                || (k == f && (y == 4 || y == 11))) {
                system("CLS");
                stop = 3;
                cout << "Game Over, Try Again later" << endl
                     << "Enter w to exit" << endl;
            } else if (y == 2) { // garis finish
                system("ClS");
                stop = 3;
                cout << "You Win" << endl
                     << "Enter w to exit" << endl;

            }

            // penambahan agar (=) bergerak
            a += dist(rd);
            c += dist(rd);
            d += dist(rd);
            b -= dist(rd);
            e -= dist(rd);
            f -= dist(rd);

            // input gerakan
            cout << "Input (w/a/s/d) to move >>";
            cin >> move;
            if (move == 'd') {
                k += 1;
            } else if (move == 'a') {
                k -= 1;
            } else if (move == 'w') {
                y -= 1;
            } else if (move == 's') {
                y += 1;
            }

            // pembatas
            if (k <= 1) {
                k += 1;
            } else if (k >= 29) {
                k -= 1;
            } else if (y <= 0) {
                y += 1;
            } else if (y >= 21) {
                y -= 1;
            }

            system("CLS");
        }

    return 0;
}
