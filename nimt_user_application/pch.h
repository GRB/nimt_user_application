#pragma once

/*Bellow we set the driver name. the string should have the format "\\\\.\\device name"*/
#define drivername LPCWSTR(L"\\\\.\\nimt")

/*Bellow we set the CTL_CODES to be used on the communication with the driver
* Params:
* 1- DeviceType. Microsoft state that 3rd party should start with 0x8000
* 2- Function. A incremental number, never to be repeated on same driver. Microsoft state that 3rd party should start on 0x800
* 3- Method. This is where we set the kind of cumunication we want with the driver.
* 4- Access. Type of access.
* https://docs.microsoft.com/en-us/windows-hardware/drivers/kernel/defining-i-o-control-codes
*/
#define READ_MEMORY CTL_CODE(0x8069, 0x869, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define WRITE_MEMORY CTL_CODE(0x8069, 0x870, METHOD_BUFFERED, FILE_ANY_ACCESS)


/*Bellow we set the includes needed for the project*/
#include <Windows.h>
#include <iostream>