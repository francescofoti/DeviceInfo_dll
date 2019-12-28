# The deviceinfo Windows dynamic link library (DLL) project

Windows provides information about different sorts of attached devices, like hard disks, CDROMs, printers and others. These devices can be attached to the computer via different interfaces like USB, SCSI, serial or parallel ports, etc.

The deviceinfo DLL project is a mutation of my [deviceinfo console executable](https://github.com/francescofoti/deviceinfo).

It is a 32 **and 64** bits DLL, while the console project is just 32bits. They share the same code module that does query for device information thru the DeviceIoControl Win32 API function (see DevInfo.c). In the DLL version of the code, the "DIxxx" set of functions in Devinfo.c are just additionally decorated with appropriate export keywords, and are also listed in the export section of the module definition file (DeviceInfo.DEF) in order to be exported with the correct (unmangled) names.

This DLL can be used in Visual Basic (VB and VBA) as I explain and demo in [this article on my personal blog](https://francescofoti.com/2019/12/how-to-get-useful-windows-device-information-in-vba/).

This is a Visual Studio 2017, UNICODE, project, with 32bits and 64bits targets. The produced DLLs need the presence of the corresponding [Visual C 2017 runtime](https://support.microsoft.com/fr-ch/help/2977003/the-latest-supported-visual-c-downloads) (x86) installed on the target computer to function properly.

## DLL API

You can look into DeviceInfo.h for the signatures of the exported functions.

## Downloadables

* binaries
  * [deviceinfo.dll](https://devinfo.net/downloads/deviceinfodll/deviceinfo.dll) (32bits version, MD5 sum: fb86ea314cdc4b2fd42f01b3876230d3)
  * [deviceinfo64.dll](https://devinfo.net/downloads/deviceinfodll/deviceinfo64.dll) (64bits version, MD5 sum: c27ce08c1c7d982bc475181d6f1cc613)
* Access Demo database
  * [deviceinfo_dll.accdb](https://devinfo.net/downloads/deviceinfodll/deviceinfo_dll.accdb) (contains the MDeviceInfo.bas module with the necessary declares, and additional wrapping to easily use the DLL with one function call and a supporting Type definition).
