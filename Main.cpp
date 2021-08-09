//#include <iostream>
//using namespace std;
//#include "Block.h"
//#include "block_chain.h"
//#include "Items.h"
//#include "Market_place.h"
//#include "Person.h"
//#include "Transaction.h"
//#include "wallet.h"
//
//
//void make_transaction(transaction**& t, int& no) {
//	if (no == 0) {
//		t = new transaction * [no+1];
//		t[0] = new transaction;
//		no++;
//	}
//	else {
//		transaction** temp;
//		temp = new transaction * [no + 1];
//		int i;
//		for (i = 0; i < no; i++) {
//			temp[i] = t[i];
//		}
//		temp[i] = new transaction;
//		delete[]t;
//		t = temp;
//		temp = nullptr;
//		no++;
//	}
//}
//
//
//int main() {
//	//creating genesis block
//	transaction** Tlist;
//	int transaction_no = 0;
//	make_transaction(Tlist, transaction_no);
//	Tlist[0]->set_amount(300);
//	//transaction_no++;
//	block b;
//	b.add_transaction(Tlist[0]);
//	block_chain bc;
//	bc.add_block(&b);

//	person* p=new person[3];
//	//users buying coins
//	p[0].buy_coins(50);
//	p[1].buy_coins(50);
//	p[2].buy_coins(50);
//	//marketplace buying coins
//	market_place mar;
//	mar.buy_coins(150);
//	int count=0;
//	for (int i = 0; i < 3; i++) {
//		cout << "Person " << count+1 << endl;
//		if (p[count+1].buy_item()) {
//			char* pkey = new char[10];
//			char* rkey = new char[10];
//			cout << "Enter Your Public Key : ";
//			cin >> pkey;
//			p[count + 1].set_public_key(pkey);
//			cout << "Enter the receiver's Public key : ";
//			cin >> rkey;
//			p[count + 1].set_reciever_key(rkey);
//			if (mar.verify_transaction(p[count+1].get_digital_sig(), p[count + 1].get_public_key())) {
//				make_transaction(Tlist, transaction_no);
//				cout << "Transaction no : " << transaction_no << endl;
//				Tlist[transaction_no]->set_amount(p[count + 1].get_coins_deducted());
//				Tlist[transaction_no]->set_digital_signature(p[count + 1].get_digital_sig());
//				Tlist[transaction_no]->set_reciever_key(rkey);
//				Tlist[transaction_no]->set_sender_key(pkey);
//				b.add_transaction(Tlist[transaction_no]);
//				if (count % 3 == 0) {
//					bc.add_block(&b);
//				}
//			}
//		}
//		else {
//			cout << "You do not have enough coins to buy items" << endl;
//		}
//		count++;
//		if (count % 3 == 0) {
//			count = 0;
//		}
//	}
//	bc.print_block_chain();
//	return 0;
//}















#include <iostream>
#include <cstring>
#include "block.h"
#include "block_chain.h"
#include "Items.h"
#include "Market_place.h"
#include "Person.h"
#include "Transaction.h"
#include "wallet.h"
using namespace std;

void make_transaction(transaction**& t, int& no) {
	if (no == 0) {
		t = new transaction * [1];
		t[0] = new transaction;
		no++;
	}
	else {
		transaction** temp;
		temp = new transaction * [no + 1];
		int i;
		for (i = 0; i < no; i++) {
			temp[i] = t[i];
		}
		temp[i] = new transaction;
		delete[]t;
		t = temp;
		temp = nullptr;
		no++;
	}
}
void make_block(block**& b, int& no) {
	if (no == 0) {
		b = new block * [1];
		b[0] = new block;
		no++;
	}
	else {
		block** temp;
		temp = new block * [no + 1];
		for (int i = 0; i < no; i++) {
			temp[i] = b[i];
		}
		delete[]b;
		b = temp;
		temp = nullptr;
		no++;
	}
}

int main() {
	//creating genesis block;
	transaction** t;
	int transaction_no = 0, block_no = 0;
	make_transaction(t, transaction_no);
	t[0]->set_amount(300);
	block** b;
	make_block(b, block_no);
	b[0][0].add_transaction(t[0],0);
	block_chain bc;
	bc.add_block(b[0]);
        bc.print_block_chain();
	//assigning coisn to persons and market
	person* p = new person[3];
	for (int i = 0; i < 3; i++) {
		p[i].buy_coins(50);
	}
	market_place mar;
	mar.buy_coins(150);
	int count = 0;
	for (int i = 0; i < 3; i++) {
		cout << "Person Number " << count + 1 << endl;
		//check for enough wow coins
		if (p[count + 1].buy_item()) {
			char* pkey = new char[10];
			char* rkey = new char[10];
			cout << "Enter your wallet address or public key : ";
			cin >> pkey;
			p[count + 1].set_public_key(pkey);
			cout << "Enter the reciever's public key : ";
			cin >> rkey;
			p[count + 1].set_reciever_key(rkey);
			//verifying the transaction
			if (mar.verify_transaction(p[count + 1].get_digital_sig(), p[count + 1].get_public_key())) {
				make_transaction(t, transaction_no);
				cout << transaction_no;
				//maintaing transaction record
				t[transaction_no - 1]->set_amount(p[count + 1].get_coins_deducted());
				t[transaction_no - 1]->set_reciever_key(rkey);
				t[transaction_no - 1]->set_sender_key(pkey);
				t[transaction_no - 1]->set_digital_signature(p[count + 1].get_digital_sig());
				make_block(b, block_no);
				b[block_no - 1][0].add_transaction(t[transaction_no - 1],count);
				if (count % 3 == 0) {
					//combing transactions into block
					bc.add_block(b[block_no - 1]);
					make_block(b, block_no);
					count = 0;
				}
			}
		}
		else {
			cout << "You do not have enough coins to buy this item" << endl;
		}
		count++;
	}
	bc.print_block_chain();
	return 0;
}
