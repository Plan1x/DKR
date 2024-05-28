#include "Logger.h"
Logger::Logger()
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
void Logger::write(const string& out)
{
	file << out;
}
void Logger::write_encrypt_data(const Aes& data)
{

	file << data;
	file << endl;


}
void Logger::read_data(const string& filename)
{

	infile.open(filename, std::ios::in);



	while (getline(infile, test))
	{
		cout << test << endl;
	}

	infile.close();

}