#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

struct Card {
    int rank; // 1=A, 2..10, 11=J, 12=Q, 13=K
    int suit; // 0..3
};

static string rankStr(int r) {
    if (r == 1) return "A";
    if (r == 11) return "J";
    if (r == 12) return "Q";
    if (r == 13) return "K";
    return to_string(r);
}

static int cardValueForCount(const Card& c) {
    if (c.rank >= 11) return 10;
    if (c.rank == 1) return 11; // start as 11, adjust later
    return c.rank;
}

static int handTotal(const vector<Card>& hand) {
    int total = 0;
    int aces = 0;

    for (const auto& c : hand) {
        total += cardValueForCount(c);
        if (c.rank == 1) aces++;
    }

    while (total > 21 && aces > 0) {
        total -= 10; // turn an Ace from 11 into 1
        aces--;
    }

    return total;
}

static bool isBlackjack(const vector<Card>& hand) {
    if (hand.size() != 2) return false;
    int t = handTotal(hand);
    return (t == 21);
}

static bool canSplit(const vector<Card>& hand) {
    if (hand.size() != 2) return false;
    return hand[0].rank == hand[1].rank;
}

static void printHand(const string& label, const vector<Card>& hand, bool hideSecond) {
    cout << label << ": ";
    for (size_t i = 0; i < hand.size(); i++) {
        if (hideSecond && i == 1) {
            cout << "[?] ";
        } else {
            cout << "[" << rankStr(hand[i].rank) << "] ";
        }
    }
    if (!hideSecond) cout << "(Total: " << handTotal(hand) << ")";
    cout << endl;
}

struct Deck {
    vector<Card> cards;
    size_t idx = 0;
    mt19937 rng;

    Deck() : rng((unsigned)time(nullptr)) {
        reset();
    }

    void reset() {
        cards.clear();
        idx = 0;
        for (int s = 0; s < 4; s++) {
            for (int r = 1; r <= 13; r++) {
                cards.push_back(Card{r, s});
            }
        }
        shuffle(cards.begin(), cards.end(), rng);
    }

    Card draw() {
        if (idx >= cards.size()) reset();
        return cards[idx++];
    }
};

struct HandState {
    vector<Card> hand;
    int bet = 0;
    bool doubled = false;
    bool finished = false;
    bool busted = false;
    bool blackjack = false;
};

static bool canDoubleDown(const vector<Card>& hand, bool alreadyActed, int creditsAvailable, int bet) {
    if (alreadyActed) return false;
    if (hand.size() != 2) return false;
    int t = handTotal(hand);
    if (!(t == 9 || t == 10 || t == 11)) return false;
    if (creditsAvailable < bet) return false; // need extra to double
    return true;
}

static bool canPass(const vector<Card>& hand, bool alreadyActed) {
    return (!alreadyActed && hand.size() == 2);
}

int main() {
    Deck deck;

    int credits = 1000;

    while (credits > 0) {
        cout << "Credits: " << credits << endl;
        cout << "Enter bet (0 to quit): ";
        int bet = 0;
        cin >> bet;

        if (bet == 0) break;
        if (bet < 0 || bet > credits) {
            cout << "Invalid bet." << endl;
            continue;
        }

        credits -= bet;

        vector<Card> dealer;
        dealer.push_back(deck.draw());
        dealer.push_back(deck.draw());

        HandState h1;
        h1.bet = bet;
        h1.hand.push_back(deck.draw());
        h1.hand.push_back(deck.draw());

        bool splitUsed = false;
        bool roundEndedByPass = false;

        // Check immediate blackjacks (only before split/pass)
        bool playerBJ = isBlackjack(h1.hand);
        bool dealerBJ = isBlackjack(dealer);

        printHand("Dealer", dealer, true);
        printHand("Player", h1.hand, false);

        if (playerBJ || dealerBJ) {
            // Resolve immediately
            if (playerBJ && dealerBJ) {
                // Push
                credits += h1.bet;
                cout << "Push (both blackjack)." << endl;
            } else if (playerBJ) {
                // Win with 3:2 payout
                int win = (h1.bet * 3) / 2; // integer payout
                credits += h1.bet + win;
                cout << "Player blackjack. Win: " << win << endl;
            } else {
                // Dealer blackjack -> lose bet already deducted
                cout << "Dealer blackjack. You lose." << endl;
            }
            cout << endl;
            continue;
        }

        // Player action phase (supports one split)
        vector<HandState> hands;
        hands.push_back(h1);

        for (size_t hi = 0; hi < hands.size(); hi++) {
            bool acted = false;

            while (!hands[hi].finished) {
                int total = handTotal(hands[hi].hand);
                if (total > 21) {
                    hands[hi].busted = true;
                    hands[hi].finished = true;
                    break;
                }

                cout << endl;
                cout << "Hand " << (hi + 1) << " total: " << total << " | Bet: " << hands[hi].bet << endl;

                // Build options
                bool optH = true;
                bool optS = true;
                bool optP = (!splitUsed && hands[hi].hand.size() == 2 && canSplit(hands[hi].hand) && credits >= hands[hi].bet);
                bool optD = canDoubleDown(hands[hi].hand, acted, credits, hands[hi].bet);
                bool optX = (!splitUsed && hands.size() == 1 && canPass(hands[hi].hand, acted));

                cout << "Options: ";
                if (optH) cout << "H ";
                if (optS) cout << "S ";
                if (optP) cout << "P ";
                if (optD) cout << "D ";
                if (optX) cout << "X ";
                cout << endl;

                cout << "Choose: ";
                char choice;
                cin >> choice;
                choice = (char)toupper(choice);

                if (choice == 'H' && optH) {
                    hands[hi].hand.push_back(deck.draw());
                    acted = true;
                    printHand("Player", hands[hi].hand, false);
                } else if (choice == 'S' && optS) {
                    hands[hi].finished = true;
                } else if (choice == 'P' && optP) {
                    // Split into two hands (one split only)
                    splitUsed = true;

                    // Take the extra bet from credits
                    credits -= hands[hi].bet;

                    Card c1 = hands[hi].hand[0];
                    Card c2 = hands[hi].hand[1];

                    HandState a, b;
                    a.bet = hands[hi].bet;
                    b.bet = hands[hi].bet;

                    a.hand.push_back(c1);
                    b.hand.push_back(c2);

                    a.hand.push_back(deck.draw());
                    b.hand.push_back(deck.draw());

                    // Replace current hand with a, insert b after it
                    hands[hi] = a;
                    hands.insert(hands.begin() + (hi + 1), b);

                    cout << "Split done." << endl;
                    printHand("Hand 1", hands[hi].hand, false);
                    printHand("Hand 2", hands[hi + 1].hand, false);

                    acted = true; // splitting counts as acting
                } else if (choice == 'D' && optD) {
                    // Double bet: take extra bet, draw one, then stand
                    credits -= hands[hi].bet;
                    hands[hi].bet *= 2;
                    hands[hi].doubled = true;

                    hands[hi].hand.push_back(deck.draw());
                    printHand("Player", hands[hi].hand, false);

                    hands[hi].finished = true;
                    acted = true;
                } else if (choice == 'X' && optX) {
                    // Pass: round ends, dealer takes half bet
                    int refund = hands[hi].bet / 2;
                    credits += refund; // bet already deducted, so return half
                    cout << "Pass. You lose half your bet." << endl;
                    roundEndedByPass = true;
                    break;
                } else {
                    cout << "Invalid choice." << endl;
                }

                if (roundEndedByPass) break;
            }

            if (roundEndedByPass) break;
        }

        if (roundEndedByPass) {
            cout << endl;
            continue;
        }

        // Dealer plays if at least one hand not busted
        bool anyLive = false;
        for (auto& h : hands) {
            if (!h.busted) { anyLive = true; break; }
        }

        cout << endl;
        printHand("Dealer", dealer, false);

        if (anyLive) {
            while (handTotal(dealer) < 17) {
                dealer.push_back(deck.draw());
                printHand("Dealer", dealer, false);
            }
        }

        int dealerTotal = handTotal(dealer);
        bool dealerBust = dealerTotal > 21;

        // Settle each hand
        for (size_t hi = 0; hi < hands.size(); hi++) {
            int playerTotal = handTotal(hands[hi].hand);

            if (hands[hi].busted) {
                cout << "Hand " << (hi + 1) << ": Bust. Lose." << endl;
                continue; // bet already deducted
            }

            if (dealerBust) {
                // Win
                credits += hands[hi].bet * 2;
                cout << "Hand " << (hi + 1) << ": Dealer bust. Win." << endl;
            } else {
                if (playerTotal > dealerTotal) {
                    credits += hands[hi].bet * 2;
                    cout << "Hand " << (hi + 1) << ": Win." << endl;
                } else if (playerTotal < dealerTotal) {
                    cout << "Hand " << (hi + 1) << ": Lose." << endl;
                } else {
                    // Push
                    credits += hands[hi].bet;
                    cout << "Hand " << (hi + 1) << ": Push." << endl;
                }
            }
        }

        cout << endl;
    }

    cout << "Game over. Credits: " << credits << endl;
    return 0;
}
