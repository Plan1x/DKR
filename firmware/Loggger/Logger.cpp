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
void Logger:: write(const Console& console)
{
	file << console;

}