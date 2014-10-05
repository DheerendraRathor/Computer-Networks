/*
 * utils.cpp
 *
 *  Created on: Oct 5, 2014
 *      Author: dheerendra
 */

#include "utils.h"

#include <sstream>
#include <bitset>
#include <iostream>
#include <exception>
using namespace std;

/* Implementing default constructor */
match::match() {
}

/**
 * Implementing non-default constructor
 */
match::match(string ip, string subnet) {
    this->ip = ip;
    this->subnet = subnet;
    network = "";
    generateNetwork();
}

/**
 * Generating network address of length network bits + subnet bits
 */
void match::generateNetwork() {
    stringstream ip_ss(this->ip);
    stringstream subnet_ss(this->subnet);
    string ip_token, subnet_token;
    int subnet_no = 0;
    /** next line is getting byte by byte IP address in there tokens */
    while (getline(ip_ss, ip_token, '.'), getline(subnet_ss, subnet_token, '.')) {
        istringstream ip_iss(ip_token);
        istringstream subnet_iss(subnet_token);
        int ip_int, subnet_int;
        ip_iss >> ip_int;
        subnet_iss >> subnet_int;
        bitset<8> temp(ip_int & subnet_int); /** Getting 8 bit network address */
        network += temp.to_string(); /** appending new byte to previous address */
        try{
            subnet_no += subnetCount(subnet_int); /** Getting network bits + subnet bits */
        } catch (const char* e){
            /** Terminating program on invalid subnet mast */
            cerr<<e<<" Sub-net Mask entered is "<<this->subnet<<" which is not a valid sub-net"<<endl;
            terminate();
        }
    }
    /** truncating network address upto size of subnet bits */
    network = network.substr(0, subnet_no);
}

/**
 * Implemention of helper function for generating subnet bits count
 */
int subnetCount(int num) {
    switch (num) {
        case 0:
            return 0;
        case 128:
            return 1;
        case 192:
            return 2;
        case 224:
            return 3;
        case 240:
            return 4;
        case 248:
            return 5;
        case 252:
            return 6;
        case 254:
            return 7;
        case 255:
            return 8;
        default:
            throw "Bad sub-net Exception occured";
    }
}

/**
 * Converting a decimal IP string to binary IP string without '.'
 * to easily facilitate prefix matching.
 */
string ipToBinaryString(string ip) {
    stringstream ip_ss(ip);
    string ip_token;
    string answer = "";
    while (getline(ip_ss, ip_token, '.')) {
        istringstream ip_iss(ip_token);
        int temp;
        ip_iss >> temp;
        bitset<8> mybs(temp);
        answer += mybs.to_string();
    }
    return answer;
}

