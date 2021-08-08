#pragma once
#include "Items.h"

class market_place {
	//all items have same initial quantity
	meme mobj[10];//1 
	emoji eobj[10];//2
	stickers sobj[10];//3
	float coins;
	int private_key=6;
public:
	int buy_item() {
		int choice;
		cout << "Enter the Type of Item to be Bought : " << endl;
		cout << "1. Meme\n2. Emoji\n3. Sticker" << endl;
		cin >> choice;
		while (choice < 1 && choice>3) {
			cout << "Enter the Type of Item to be Bought : " << endl;
			cout << "1. Meme\n2. Emoji\n3. Sticker" << endl;
			cout << "Invalid Choice! Please pick number between 1 and 3 inclusively" << endl;
			cin >> choice;
		}
		return choice;
	}
	float get_meme_price() {
		return mobj->get_price();
	}
	float get_emoji_price() {
		return eobj->get_price();
	}
	float get_sticker_price() {
		return sobj->get_price();
	}
	bool verify_transaction(char* dig_sig,char* public_key) {
		cout << "Public key "<<public_key << endl;
		cout << "digital key " << dig_sig << endl;
		for (int i = 0; i < strlen(dig_sig); i++) {
			dig_sig[i] = dig_sig[i] - private_key;
		}
		cout << "digital key " << dig_sig << endl;
		if (strcmp(dig_sig, public_key) == 0) {
			cout << "Transaction has been verified" << endl;
			return true;
		}
		cout << "Transaction is invalid !" << endl;
		return false;
	}
	void buy_coins(float coins) {
		this->coins = coins;
	}
};