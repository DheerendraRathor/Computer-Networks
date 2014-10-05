/*
 * utils.h
 *
 *  Created on: Oct 5, 2014
 *      Author: dheerendra
 */

#ifndef UTILS_H_
#define UTILS_H_

#include<string>

/*
 * Forward declaration for counting number of one's in an integer
 * Useful for getting network bits + sub-net bits
 */
int subnetCount(int);

/**
 * declaration for a function which converts the decimal ip string
 * to binary ip string
 */
std::string ipToBinaryString(std::string ip);

/**
 * structure for storing row of forwarding table
 */
struct match {
    std::string ip;         /** IP address */
    std::string subnet;     /** subnet address */
    std::string network;    /** Network address in binary (length = network + subnet bits) */

    /** default constructor declaration */
    match();

    /** constructor declaration */
    match(std::string, std::string);

    /** Helper function declaration for generating network address from ip and subnet mast */
    void generateNetwork();
};

#endif /* UTILS_H_ */
