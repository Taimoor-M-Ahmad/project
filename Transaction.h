#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class transaction {
	char* sender_public_key;
	char* reciever_public_key;
	float amount;
	char* digital_signature;
public:
	transaction() {
		sender_public_key = new char[10];
		strcpy(sender_public_key,"0000");
		reciever_public_key = new char[10];
		strcpy(reciever_public_key, "0000");
		digital_signature = new char[10];
		strcpy(digital_signature, "0000");
	}
	void print_transaction() {
		cout << "SENDER PUBLIC KEY : " << sender_public_key << endl;
		cout << "RECEIVER PUBLIC KEY : " << reciever_public_key << endl;
		cout << "TRANSACTION AMOUNT : " << amount << endl;
		cout << "DIGITAL SIGNATURE OF SENDER : " << digital_signature << endl;
	}
	void set_amount(float amt) {
		amount = amt;
	}
	float get_amount() {
		return amount;
	}
	char* get_receiver_public_key() {
		return reciever_public_key;
	}
	void set_sender_key(char* key) {
		if (key != nullptr) {
			strcpy(sender_public_key, key);
		}
	}
	void set_reciever_key(char* key) {
		if (key != nullptr) {
			strcpy(reciever_public_key, key);
		}
	}
	void set_digital_signature(char* sig) {
		if (sig != nullptr) {
			strcpy(digital_signature, sig);
		}
	}
	char* get_digital_signature() {
		return digital_signature;
	}
	char* get_sender_key() {
		return sender_public_key;
	}
};