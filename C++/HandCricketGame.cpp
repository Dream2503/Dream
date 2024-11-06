#include <iostream>
using namespace std;

const string PLAYABLES[2] = {"bat", "bowl"};
const string CHOOSABLES[2] = {"odd", "even"};
const char SCOREABLES[6] = {1, 2, 3, 4, 5, 6};
const char lenPlayables = 2, lenChoosables = 2, lenScoreables = 6;
string userDes, compDes;

auto choice(const auto *lst, const char len);
bool isAlpha(const string str);
bool in(const auto element, const auto *lst, const char len);
void toss();
char userScoring(string game);
char compScoring(string game);

int main() {
    short totalScore = 0;
    char userBattingScore, userBowlingScore, compBattingScore, compBowlingScore;
    bool innings1 = true, innings2 = false;
    toss();

    while (innings1) {
        if (userDes == PLAYABLES[0]) {
            userBattingScore = userScoring(PLAYABLES[0]), compBowlingScore = compScoring(PLAYABLES[1]);

            if (userBattingScore == compBowlingScore) {
                cout << endl << "User OUT!!" << endl;
                cout << "Total run scored by User: " << totalScore << endl << endl;
                cout << "Now User bowls and Computer bats" << endl;
                cout << "Computer needs " << totalScore + 1 << " runs to win" << endl << endl;
                innings1 = false; innings2 = true;
                break;
            } else {
                totalScore += userBattingScore;
                cout << "Total user score " << totalScore << endl << endl;
            }
        } else if (userDes == PLAYABLES[1]) {
            userBowlingScore = userScoring(PLAYABLES[1]), compBattingScore = compScoring(PLAYABLES[0]);

            if (userBowlingScore == compBattingScore) {
                cout << endl << "Computer OUT!!" <<  endl;
                cout << "Total run scored by Computer: " << totalScore << endl << endl;
                cout << "Now User bats and Computer bowls" << endl;
                cout << "User needs " << totalScore + 1 << " runs to win" << endl << endl;
                innings1 = false; innings2 = true;
                break;
            } else {
                totalScore += compBattingScore;
                cout << "Total computer score " << totalScore << endl << endl;
            }
        }
    }
    while (innings2) {
        if (userDes == PLAYABLES[0]) {
            userBowlingScore = userScoring(PLAYABLES[1]), compBattingScore = compScoring(PLAYABLES[0]);

            if (userBowlingScore == compBattingScore) {
                cout << "Computer OUT!!" << endl;

                if (totalScore > 0)
                    cout << "User won the match by " << totalScore << " runs!!" << endl;
                else
                    cout << "Computer won the match" << endl;

                innings2 = false;
                break;
            } else {
                totalScore -= compBattingScore;

                if (totalScore <= 0) {
                    cout << "Computer won the match" << endl;
                    break;
                }
                cout << "Computer needs more " << totalScore << " to win" << endl << endl;
            }
        } else if (userDes == PLAYABLES[1]) {
            userBattingScore = userScoring(PLAYABLES[0]), compBowlingScore = compScoring(PLAYABLES[1]);
        
            if (userBattingScore == compBowlingScore) {
                cout << "User OUT!!" << endl;

                if (totalScore > 0)
                    cout << "Computer won the match by "<< totalScore << " runs!!" << endl;
                else
                    cout << "User won the match" << endl;

                innings2 = false;
                break;
            } else {
                totalScore -= userBattingScore;

                if (totalScore <= 0) {
                    cout << "User won the match" << endl;
                    break;
                }
                cout << "User needs more " << totalScore << " to win" << endl << endl;
            }
        }
    }
    cout << endl << "Press any key to exit...";
    cin >> userBattingScore;
}

auto choice(const auto *lst, const char len) {
    srand(time(0));
    return lst[rand() % len];
}
bool isAlpha(const string str) {
    char cnt = 0;
    char chr;

    while ((chr = str[cnt]) != '\0') {
        if (chr <= 'A' or chr >= 'z')
            return false;

        cnt++;
    }
    return true;
}
bool in(const auto element, const auto *lst, const char len) {
    for (char i = 0; i < len; i++)
        if (element == lst[i])
            return true;
    
    return false;
}
void toss() {
    bool tossWon = false;
    short userToss, compToss;
    string userChoice;
    while (not tossWon) {
        cout << "Choose odd/even: "; cin >> userChoice;
        cout << endl;

        if (not isAlpha(userChoice) || not in(userChoice, CHOOSABLES, lenChoosables))
            cout << "Choose 'even' or 'odd' only!" << endl;
        else
            break;
    }
    while (not tossWon) {
        cout << "Enter toss (1-6): "; cin >> userToss;

        if (not in(userToss, SCOREABLES, lenScoreables))
            cout << "Enter number from 1 to 6 only!" << endl;
        else
            break;
    }
    compToss = choice(SCOREABLES, lenScoreables);
    cout << "Computer choose "<< compToss << endl;

    if (((userToss + compToss) % 2 == 0 and (userChoice == CHOOSABLES[1])) or ((userToss + compToss) % 2 == 1 and (userChoice == CHOOSABLES[0]))) {
        tossWon = true;
        cout << "You won the toss" << endl << endl;

        while (tossWon) {
            cout << "Choose bat/bowl: "; cin >> userDes;
            cout << endl;

            if (not in(userDes, PLAYABLES, lenPlayables))
                cout << "Choose 'bat' or 'bowl' only!" << endl;               
            else
                break;
        }
    } else {
        compDes = choice(PLAYABLES, lenPlayables);
        cout << "Computer won the toss and chooses to " << compDes << endl << endl;
    }
    if (tossWon) {
        if (userDes == PLAYABLES[0])
            compDes = PLAYABLES[1];
        else
            compDes = PLAYABLES[0];
    } else {
        if (compDes == PLAYABLES[0])
            userDes = PLAYABLES[1];
        else
            userDes = PLAYABLES[0];
    }
}
char userScoring(string game) {
    short userScore;

    while (true) {
        if (game == PLAYABLES[0]) 
            cout << "Score a Run (1-6): ";
        else 
            cout << "Throw a ball (1-6): ";
        
        cin >> userScore;

        if (not in(userScore, SCOREABLES, lenScoreables))
            cout << "Enter number from 1 to 6 only!" << endl;
        else
            return userScore;
    }
}
char compScoring(string game) {
    const char compScore = choice(SCOREABLES, lenScoreables);

    if (game == PLAYABLES[0])
        cout << "Computer scores " << (short)compScore << endl;
    else
        cout << "Computer bowls " << (short)compScore << endl;

    return compScore;
}