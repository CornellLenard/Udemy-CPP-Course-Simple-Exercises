#include "database.h"
#include "expedia.h"


int main()
{
	Database db;
	db.TestInit();
	Expedia exp(&db);
	exp.Run();
	return 0;
}


