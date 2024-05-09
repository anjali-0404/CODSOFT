#include <iostream>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'x';
bool tie = false;
int row,column;
string n1, n2;

void displayboard() {
    cout<< "   |    |  \n";
    cout<< " " << space[0][0] << " | " << space[0][1] << "  | " << space[0][2] << " \n";
    cout<< "___|____|___\n";
    cout<< "   |    |   \n";
    cout<< " " << space[1][0] << " | " << space[1][1] << "  | " << space[1][2] << " \n";
    cout<< "___|____|___\n";
    cout<< "   |    |   \n";
    cout<< " " << space[2][0] << " | " << space[2][1] << "  | " << space[2][2] << " \n";
    cout<< "   |    |   \n";
}

void check() {
    int dig;

    if (currentPlayer == 'x') {
        cout<<n1<<"Enter:";
        cin>>dig;
    } else {
        cout<<n2<<" enter:";
        cin>>dig;
    }

    row=(dig - 1) / 3;
    column=(dig - 1) % 3;

    if(dig<1 || dig>9 || space[row][column] == 'x' || space[row][column] == 'o') {
        cout<<"Invalid input."<<endl;
        check(); 
    }else{
        space[row][column] = currentPlayer;
    }
}

bool checkgame() {
    for (int i = 0; i < 3; i++) {
        if (space[i][0] == space[i][1] && space[i][1] == space[i][2]) return true; 
        if (space[0][i] == space[1][i] && space[1][i] == space[2][i]) return true; 
    }
    if (space[0][0] == space[1][1] && space[1][1] == space[2][2]) return true;
    if (space[0][2] == space[1][1] && space[1][1] == space[2][0]) return true; 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'x' && space[i][j] != 'o') return false;
        }
    }
    tie = true;
    return true;
}

int main() {
    cout << "Enter the 1st player name: ";
    getline(cin, n1);
    cout << "Enter the 2nd player name: ";
    getline(cin, n2);
    cout<<n1<<" x " << n2 << " o" << endl;

    while (!checkgame()) {
        displayboard();
        check();
        currentPlayer = (currentPlayer == 'x') ? 'o' : 'x'; 
    }

    displayboard();

    if (tie) {
        cout<<"tie!"<<endl;
    } else {
        if (currentPlayer == 'x') {
            cout<<n2<<"Won!"<<endl;
        } else {
            cout<<n1<<"Won!"<<endl;
        }
    }

    return 0;
}
