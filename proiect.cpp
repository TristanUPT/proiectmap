#include <iostream>
#include <vector>
#include <stack>




using namespace std;

vector<stack<int>> rods(3);
int moves = 0;

void displayTowers() {
    cout << "-----------------------------------------------------\n";
    for (int i = rods.size() - 1; i >= 0; --i) {
        cout << "Tija " << (char)('A' + i) << ": ";
        stack<int> temp = rods[i];
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
    cout << "-----------------------------------------------------\n";

  


}

void towerOfHanoi(int n, int source, int auxiliary, int destination) {
    if (n > 0) {
        towerOfHanoi(n - 1, source, destination, auxiliary);
        int disk = rods[source].top();
        rods[source].pop();
        rods[destination].push(disk);
        moves++;
        cout << "Muta discul " << disk << " din tija " << (char)('A' + source) << " la tija " << (char)('A' + destination) << endl;
        displayTowers();
        towerOfHanoi(n - 1, auxiliary, source, destination);
    }
}

void automatedGame(int n) {
    cout << "Turnul din Hanoi pentru " << n << " discuri:\n";
    for (int i = n; i > 0; --i) {
        rods[0].push(i);
    }
    displayTowers();
    towerOfHanoi(n, 0, 1, 2);
}

int main() {
    cout << "Turnul din Hanoi minigame\n";
    cout << "1. Regulile jocului.\n";
    cout << "2. Joaca singur\n";
    cout << "3. Lasa minigame-ul sa joace pentru tine\n";

    int choice;
    cout << "Selecteaza o optiune:";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "-------------------------------------------------------------------------------------------------\n";
        cout << "                                           Reguli\n";
        cout << "-------------------------------------------------------------------------------------------------\n";
        cout << "Misiunea este sa mutati toate discurile pe a treia tija fara a încalca secventa de aranjament.\n";
        cout << "1. Un singur disc poate fi mutat între tije în orice moment." << "\n";
        cout << "2. Doar discul \"de sus\" poate fi îndepartat." << "\n";
        cout << "3. Niciun disc mare nu poate sta pe un disc mai mic." << "\n";
        cout << "-------------------------------------------------------------------------------------------------\n";
        break;

    case 2: {
        int option;
        cout << "Selectati optiunea:\n";
        cout << "1. Dificultate predefinita\n";
        cout << "2. Numar personalizat de discuri\n";
        cout << "Alegeti optiunea: ";
        cin >> option;

        int disks;
        switch (option) {
        case 1: {
            int difficulty;
            cout << "Selectati nivelul de dificultate:\n";
            cout << "1. Usor (3 discuri)\n";
            cout << "2. Normal (5 discuri)\n";
            cout << "3. Greu (8 discuri)\n";
            cout << "Alegeti nivelul de dificultate: ";
            cin >> difficulty;

            switch (difficulty) {
            case 1:
                disks = 3;
                break;
            case 2:
                disks = 5;
                break;
            case 3:
                disks = 8;
                break;
            default:
                cout << "Optiune invalida. Iesire...\n";
                return 1;
            }
            break;
        }
        case 2:
            cout << "Introduceti numarul de discuri: ";
            cin >> disks;
            if (disks <= 0) {
                cout << "Numarul de discuri trebuie sa fie pozitiv.\n";
                return 1;
            }
            break;
        default:
            cout << "Optiune invalida. Iesire...\n";
            return 1;
        }

        for (int i = disks; i > 0; --i) {
            rods[0].push(i);
        }
        displayTowers();

        while (rods[2].size() != static_cast<size_t>(disks)) {
            int from, to;
            cout << "Introdu tija sursa si tija destinatie: ";
            cin >> from >> to;

            if (from < 1 || from > 3 || to < 1 || to > 3) {
                cout << "Tija selectata nu exista, incercati din nou.\n";
                continue;
            }

            --from;
            --to;

            if (!rods[from].empty() && (rods[to].empty() || rods[from].top() < rods[to].top())) {
                int disk = rods[from].top();
                rods[from].pop();
                rods[to].push(disk);
                moves++;
                displayTowers();

                if (rods[2].size() == static_cast<size_t>(disks)) {
                    cout << "Felicitari, ati castigat!!!\n";
                    cout << "Ati terminat jocul în " << moves << " mutari.\n";
                }
            }
            else {
                cout << "Mutare invalida, discurile nu pot fi plasate pe discuri mai mici.\n";
            }
        }
        break;
    }

    case 3: {
        int option;
        cout << "Selectati optiunea:\n";
        cout << "1. Dificultate predefinita\n";
        cout << "2. Numar personalizat de discuri\n";
        cout << "Alegeti optiunea: ";
        cin >> option;

        int disks;
        switch (option) {
        case 1: {
            int difficulty;
            cout << "Selectati nivelul de dificultate:\n";
            cout << "1. Usor (3 discuri)\n";
            cout << "2. Normal (5 discuri)\n";
            cout << "3. Greu (8 discuri)\n";
            cout << "Alegeti nivelul de dificultate: ";
            cin >> difficulty;

            switch (difficulty) {
            case 1:
                disks = 3;
                break;
            case 2:
                disks = 5;
                break;
            case 3:
                disks = 8;
                break;
            default:
                cout << "Optiune invalida. Iesire...\n";
                return 1;
            }
            break;
        }
        case 2:
            cout << "Introduceti numarul de discuri: ";
            cin >> disks;
            if (disks <= 0) {
                cout << "Numarul de discuri trebuie sa fie pozitiv.\n";
                return 1;
            }
            break;
        default:
            cout << "Optiune invalida. Iesire...\n";
            return 1;
        }

        automatedGame(disks);
        cout << "Jocul a luat sfarsit in " << moves << " mutari.\n";
        break;
    }

    default:
        cout << "Optiune invalida, iesire...\n";
        return 1;
    }

    return 0;
}
