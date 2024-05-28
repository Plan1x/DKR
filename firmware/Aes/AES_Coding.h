#pragma once
#include <iostream>
#include <osrng.h>
#include <aes.h> 
#include <modes.h> 
#include <filters.h> 
#include <hex.h> 
#include <string>
#include <sstream>
#include <fstream>
#define Key 0x01
#define Iv 0x01
using namespace std;
using namespace CryptoPP;
class Aes
{
public:

	string out;
	string cipher_text, decoded_text;
	byte key[CryptoPP::AES::DEFAULT_KEYLENGTH];
	byte iv[CryptoPP::AES::BLOCKSIZE];
	void aes_encrypt(const std::string& plaintext, std::string& ciphertext, const byte key[AES::DEFAULT_KEYLENGTH], const byte iv[AES::BLOCKSIZE]);
	void aes_decrypt(const std::string& ciphertext, std::string& decryptedtext, const byte key[AES::DEFAULT_KEYLENGTH], const byte iv[AES::BLOCKSIZE]);
	void AES_init();
	Aes();
	friend ofstream& operator<< (ofstream& out, const Aes& object);
private:
	ostringstream oss;



};
