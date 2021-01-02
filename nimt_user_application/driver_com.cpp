#include "pch.h"
#include "driver_com.h"

/// <summary>
/// Function to send the read command to the driver
/// </summary>
/// <param name="device_handle">HANDLE</param>
/// <param name="process_id">uint32_t</param>
/// <param name="address">uintptr_t</param>
/// <param name="buffer">PVOID</param>
/// <param name="buffer_size">SIZE_T</param>
/// <returns>bool</returns>
bool Nimt::ReadMemory(_In_ HANDLE device_handle, _In_ uint32_t process_id, _In_ uintptr_t address, _In_  PVOID buffer, _In_  SIZE_T buffer_size) {
	/*Bellow we check if we have all the information needed to send the communication to the driver, if not, return*/
	if (!device_handle || !process_id || !address || !buffer) {
		return false;
	}

	/*Bellow we initialize the structure to be sended to the driver. Must the the same as the driver is expecting*/
	MemoryStruct memory_struct;

	/*Bellow we fill the structure with the values we need*/
	memory_struct.process_id = process_id;
	memory_struct.address = (PVOID)address;
	memory_struct.buffer = buffer;
	memory_struct.buffer_size = buffer_size;

	/*Bellow we finally send all that information to the driver
	* Params:
	* 1- device handle
	* 2- CTL CODE we defined, must be the same as the one in the driver
	* 3- input buffer
	* 4- input buffer size
	* 5- output buffer
	* 6- output buffer size
	* 7,8- we just ignore those.
	* https://docs.microsoft.com/en-us/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol */
	DeviceIoControl(device_handle, READ_MEMORY, &memory_struct, sizeof(memory_struct), &memory_struct, sizeof(memory_struct), nullptr, nullptr);

	/*Finally we return from this function*/
	return true;
}

bool Nimt::WriteMemory(_In_ HANDLE device_handle, _In_ uint32_t process_id, _In_ uintptr_t address, _In_  PVOID buffer, _In_  SIZE_T buffer_size) {
	/*Bellow we check if we have all the information needed to send the communication to the driver, if not, return*/
	if (!device_handle || !process_id || !address || !buffer) {
		return false;
	}

	/*Bellow we initialize the structure to be sended to the driver. Must the the same as the driver is expecting*/
	MemoryStruct memory_struct;

	/*Bellow we fill the structure with the values we need*/
	memory_struct.process_id = process_id;
	memory_struct.address = (PVOID)address;
	memory_struct.buffer = buffer;
	memory_struct.buffer_size = buffer_size;

	/*Bellow we finally send all that information to the driver
	* Params:
	* 1- device handle
	* 2- CTL CODE we defined, must be the same as the one in the driver
	* 3- input buffer
	* 4- input buffer size
	* 5- output buffer
	* 6- output buffer size
	* 7,8- we just ignore those.
	* https://docs.microsoft.com/en-us/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol */
	DeviceIoControl(device_handle, WRITE_MEMORY, &memory_struct, sizeof(memory_struct), &memory_struct, sizeof(memory_struct), nullptr, nullptr);

	/*Finally we return from this function*/
	return true;
}
