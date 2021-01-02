#include "pch.h"
#include "driver_com.h"

int main() {
	/*Bellow we initialize the device handle to communicate with the driver*/
	HANDLE device_handle = CreateFile(L"\\\\.\\nimt", GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

	/*Bellow we check to see if we actualy have a valid handle to communicate, and if not we return becouse we cant do anything else*/
	if (device_handle == INVALID_HANDLE_VALUE) {
		return -1;
	}

	/*Bellow we pass the process id of the proccess you choose. You can check that in task manager of the windows*/
	uint32_t process_id = 0;

	/*Bellow is a test case of a read value from the address you choose using the template created for reading.
	* Params:
	* 1 - device handle that we just set a few lines above
	* 2 - process id we targetting
	* 3 - the address we want to read
	* 
	* Read<type of data we want to read>(parameters inside)*/
	int readed_value = Nimt::Read<int>(device_handle, process_id, 0x28E3B6C1B0);

	/*Bellow we print it in the console*/
	std::cout << readed_value << std::endl;

	/*Bellow is a test case of a write value from the address you choose using the template created for writting.
	* Params:
	* 1 - device handle that we just set a few lines above
	* 2 - process id we targetting
	* 3 - the address we want to read
	* 4 - the value we want to write
	* 
	* Write<type of data we want to write>(parameters inside)*/
	bool didwewrite = Nimt::Write<int>(device_handle, process_id, 0x28E3B6C1B0, 1000);

	/*Bellow we print to the console if we write with success or failure*/
	std::cout << didwewrite << std::endl;

	/*Bellow we prevent the console from closing*/
	std::getchar();

	return 0;
}