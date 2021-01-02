#pragma once

namespace Nimt {
	/*Bellow we create a structure with the type of information we need to be passing for the comunication
	Since this is a showcase for READ and WRITE only one struct is enough*/
	struct MemoryStruct {
		INT process_id = 0;		// the process id aka PID of the preocess we gona mess with
		PVOID address;			// the address to be read/write
		PVOID buffer;			// the buffer
		SIZE_T buffer_size;		// the size of the buffer
		SIZE_T size_copied;		// the size of bytes copied
	};


	bool ReadMemory(_In_ HANDLE device_handle,_In_ uint32_t process_id, _In_ uintptr_t address, _In_  PVOID buffer, _In_  SIZE_T buffer_size);
	template <class T>
	T Read(_In_ HANDLE device_handle, _In_  uint32_t process_id, _In_  uintptr_t address)
	{
		T buffer{};
		ReadMemory(device_handle, process_id, address, &buffer, sizeof(T));
		return buffer;
	}
	bool WriteMemory(_In_ HANDLE device_handle, _In_ uint32_t process_id, _In_ uintptr_t address, _In_  PVOID buffer, _In_  SIZE_T buffer_size);
	template <class T>
	T Write(_In_ HANDLE device_handle, _In_  uint32_t process_id, _In_  uintptr_t address, _In_  T buffer)
	{
		return  WriteMemory(device_handle, process_id, address, (PVOID)(&buffer), sizeof(T));
	}
}