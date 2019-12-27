#pragma once

#define MAX_ERRSTR_LENGTH 512
#define INFOSTRING_MAX_LENGTH 128

#define DLLEXPORT __declspec(dllexport)
#define STDCALL  __stdcall

typedef struct {
  DWORD   Version;
  BYTE    DeviceType;
  BYTE    DeviceTypeModifier;
  BOOLEAN RemovableMedia;
  BOOLEAN CommandQueueing;
  BYTE    BusType;  // STORAGE_BUS_TYPE enum scope is a byte
  DWORD   dwLastError;
  TCHAR   sLastError[MAX_ERRSTR_LENGTH];
  // indices where strings start in lpStringData
  int     iVendorIDPos;
  int     iProductIDPos;
  int     iProductRevisionPos;
  int     iSerialNumberPos;
  TCHAR   asInfo[5 * INFOSTRING_MAX_LENGTH];
} DEVINFO;

#define HDEVINFO  DEVINFO*

DLLEXPORT HDEVINFO  STDCALL DICreateDeviceInfo();
DLLEXPORT VOID      STDCALL DIDestroyDeviceInfo(HDEVINFO hDevInfo);
DLLEXPORT BOOL      STDCALL DIQueryDeviceInfo(HDEVINFO hDevInfo, PTCHAR psDrivePath);
DLLEXPORT DWORD     STDCALL DIGetVersion(HDEVINFO hDevInfo);
DLLEXPORT BYTE      STDCALL DIGetDeviceType(HDEVINFO hDevInfo);
DLLEXPORT BYTE      STDCALL DIGetDeviceTypeModifier(HDEVINFO hDevInfo);
DLLEXPORT BOOLEAN   STDCALL DIGetRemovableMedia(HDEVINFO hDevInfo);
DLLEXPORT BOOLEAN   STDCALL DIGetCommandQueueing(HDEVINFO hDevInfo);
DLLEXPORT BYTE      STDCALL DIGetBusType(HDEVINFO hDevInfo);
DLLEXPORT DWORD     STDCALL DIGetLastError(HDEVINFO hDevInfo);
DLLEXPORT DWORD     STDCALL DIGetLastErrorText(HDEVINFO hDevInfo, PTCHAR lpRetOutputBuf, WORD iOutputBufLen);
DLLEXPORT VOID      STDCALL DIGetVendorID(HDEVINFO hDevInfo, PTCHAR lpRetOutputBuf, WORD iOutputBufLen);
DLLEXPORT VOID      STDCALL DIGetProductID(HDEVINFO hDevInfo, PTCHAR lpRetOutputBuf, WORD iOutputBufLen);
DLLEXPORT VOID      STDCALL DIGetProductRevision(HDEVINFO hDevInfo, PTCHAR lpRetOutputBuf, WORD iOutputBufLen);
DLLEXPORT VOID      STDCALL DIGetSerialNumber(HDEVINFO hDevInfo, PTCHAR lpRetOutputBuf, WORD iOutputBufLen);