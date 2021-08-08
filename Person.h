#pragma once
#include "wallet.h"
#include "Transaction.h"
#include "Market_place.h"
#include <iostream>
#include <cstring>
using namespace std;

class person {
	wallet wall;
	char* public_key=new char[10];
	int private_key=6;
	char reciever_public_key[10];
	char* digital_signature=new char[10];
	float amount;
public:
	bool buy_item() {
		int choice;
		market_place mar;
		choice=mar.buy_item();
		//check for sufficient coins to buy a meme
		if (choice == 1) {
			if (wall.get_no_of_coins() >= mar.get_meme_price()) {
				amount = mar.get_meme_price();
				return true;
			}
			return false;
		}
		//check for sufficeint coins to buy an emoji
		if (choice == 2) {
			if (wall.get_no_of_coins() >= mar.get_emoji_price()) {
				amount = mar.get_emoji_price();
				return true;
			}
			return false;
		}
		//check for suuficient coins to buy a sticker
		if (choice == 3) {
			if (wall.get_no_of_coins() >= mar.get_sticker_price()) {
				amount = mar.get_sticker_price();
				return true;
			}
			return false;
		}
	}
	void buy_coins(float coins) {
		wall.set_coins(coins);
	}
	void set_public_key(char* key) {
		strcpy(public_key, key);
		cout << "public key =" << public_key << endl;
		strcpy(digital_signature, key);
		cout << "digital signature" << digital_signature << endl;
		encrypt();
	}
	void set_reciever_key(char* key) {
		strcpy(reciever_public_key,key);
	}
	void encrypt() {
		int i;
		for (i = 0; i < strlen(digital_signature); i++) {
			digital_signature[i] = digital_signature[i] + private_key;
		}
		cout << "digital signature" << digital_signature << endl;
	}
	char* get_digital_sig() {
		return digital_signature;
	}
	char* get_public_key() {
		return public_key;
	}
	void deduct_coin() {
		wall.deduct_coins(amount);
	}
	float get_coins_deducted() {
		return amount;
	}
};