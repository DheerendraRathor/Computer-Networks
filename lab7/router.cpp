/*
 * router.cpp
 *
 *  Created on: Oct 5, 2014
 *      Author: dheerendra
 */

#include <iostream>
#include <vector>

#include "utils.h"
#include "trie.h"

using namespace std;

int main() {
    vector<Match> forward; /** Vector for storing input IP/Mask pair */
    string ip, subnet;
    cin >> ip >> subnet; /** reading header line */
    while (1) {
        cin >> ip;
        if (ip == "default")
            break;
        cin >> subnet;
        Match temp(ip, subnet);
        forward.push_back(temp);
    }

    Trie* mytrie = new Trie();
    for (int i = 0; i < forward.size(); i++) {
        mytrie->insert(forward[i].network, i); /** creating forwarding table Trie */
    }

    int test;
    cin >> test;
    while (test--) {
        string ip;
        cin >> ip;
        string ip_bin = ipToBinaryString(ip);
        int index = mytrie->getindex(ip_bin); /** Getting index of matched prefix for forward vector */
        if (index == -1) /** if nothing is matched then returning -1 (default) */
            cout << ip << " default" << endl;
        else
            cout << ip << " " << forward[index].ip << " "
                    << forward[index].subnet << endl;
    }
    return 0;
}
