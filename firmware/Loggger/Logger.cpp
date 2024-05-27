#include "Logger.h"
Logger:: Logger()
{

}
void Logger::open(const string& filename)
{
	file.open(filename, ios::app);
}
void Logger::close()
{
	file.close();
}
void Logger::write(const Console& console)
{
	a.AES_init(console);
	a.aes_encrypt(a.out, a.cipher_text, a.key, a.iv);
	file << "Encrypted text:" << endl;
	file << a.cipher_text << endl;
	file << endl;
	file << "Key: ";
	for (int i = 0; i < 16; i++)
	{
		file << a.key[i];
	}
	file << endl;
	file << "iv: ";
	for (int i = 0; i < 16; i++)
	{
		file << a.iv[i];
	}
	file << endl;
	file << "Decrypted text:" << endl;
	a.aes_decrypt(a.cipher_text, a.decoded_text, a.key, a.iv);
	file << a.decoded_text << endl;
	
}