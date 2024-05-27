#include "AES_Coding.h"
Aes::Aes()
{

}
void Aes :: AES_init(const Console& console)
{

	AutoSeededRandomPool prng;

	//byte key[CryptoPP::AES::DEFAULT_KEYLENGTH];
	//byte iv[CryptoPP::AES::BLOCKSIZE];

	prng.GenerateBlock(key, sizeof(key));//Generating random key
	prng.GenerateBlock(iv, sizeof(iv));//Generating random iv

	
	

	oss << console;//using operator << overloading 
	out = oss.str(); // transforming all data output to string
	
}
void Aes :: aes_decrypt(const string& ciphertext, string& decryptedtext, const byte key[AES::DEFAULT_KEYLENGTH], const byte iv[AES::BLOCKSIZE]) {
	try 
	{
		
		CBC_Mode<AES>::Decryption decryption(key, AES::DEFAULT_KEYLENGTH, iv);

		
		StringSource(ciphertext, true, new StreamTransformationFilter(decryption, new StringSink(decryptedtext)));
		this -> decoded_text = decryptedtext;
	}
	catch (const Exception& e) 
	{
		
		cerr << e.what() << endl;
		exit(1);
	}
	
}
void Aes :: aes_encrypt(const string& plaintext, string& ciphertext, const byte key[AES::DEFAULT_KEYLENGTH], const byte iv[AES::BLOCKSIZE]) {
	try 
	{
		
		CBC_Mode<AES>::Encryption encryption(key, AES::DEFAULT_KEYLENGTH, iv);

		
		StringSource(plaintext, true, new StreamTransformationFilter(encryption, new StringSink(ciphertext)));
		this -> cipher_text = ciphertext;
	 }
	catch (const Exception& e) 
	{
		
		cerr << e.what() << endl;
		exit(1);
	}
	
}