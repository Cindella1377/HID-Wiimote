/*

Copyright (C) 2016 Julian L�hr
All rights reserved.

Filename:
	WiimoteDeviceInterface.h

Abstract:
	Public managed class that represents a HID Wiimote Device Interface

*/
#pragma once

#include "Status.h"
#include "State.h"

namespace HIDWiimote
{
	namespace UserModeLib
	{
		public ref class WiimoteDeviceInterface
		{
		public:
			WiimoteDeviceInterface(System::String^ DeviceInterfacePath);

			property System::String^ DeviceInterfacePath;

			event System::EventHandler^ DeviceRemoved;
			event System::EventHandler<Status^>^ StatusUpdate;

			//Starts Status Update Reader and returns InitialState
			State^ Initialize();

		private:
			HANDLE DeviceInterfaceHandle;

			bool OpenDevice();
			bool DeviceIsGood();
			void CloseDevice();

			State^ GetState();

			bool SendBufferdIOCTL(DWORD IoControlCode, LPVOID Buffer, DWORD BufferSize, LPOVERLAPPED Overlapped);

		};
	}
}
