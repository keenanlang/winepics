/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_NAPERROR
#define _INC_NAPERROR

#if (_WIN32_WINNT >= 0x0600)

#define NAP_E_INVALID_PACKET            _HRESULT_TYPEDEF_(0x80270001L)
#define NAP_E_MISSING_SOH               _HRESULT_TYPEDEF_(0x80270002L)
#define NAP_E_CONFLICTING_ID            _HRESULT_TYPEDEF_(0x80270003L)
#define NAP_E_NO_CACHED_SOH             _HRESULT_TYPEDEF_(0x80270004L)
#define NAP_E_STILL_BOUND               _HRESULT_TYPEDEF_(0x80270005L)
#define NAP_E_NOT_REGISTERED            _HRESULT_TYPEDEF_(0x80270006L)
#define NAP_E_NOT_INITIALIZED           _HRESULT_TYPEDEF_(0x80270007L)
#define NAP_E_MISMATCHED_ID             _HRESULT_TYPEDEF_(0x80270008L)
#define NAP_E_NOT_PENDING               _HRESULT_TYPEDEF_(0x80270009L)
#define NAP_E_ID_NOT_FOUND              _HRESULT_TYPEDEF_(0x8027000AL)
#define NAP_E_MAXSIZE_TOO_SMALL         _HRESULT_TYPEDEF_(0x8027000BL)
#define NAP_E_SERVICE_NOT_RUNNING       _HRESULT_TYPEDEF_(0x8027000CL)
#define NAP_S_CERT_ALREADY_PRESENT      _HRESULT_TYPEDEF_(0x0027000DL)
#define NAP_E_ENTITY_DISABLED           _HRESULT_TYPEDEF_(0x8027000EL)
#define NAP_E_NETSH_GROUPPOLICY_ERROR   _HRESULT_TYPEDEF_(0x8027000FL)
#define NAP_E_TOO_MANY_CALLS            _HRESULT_TYPEDEF_(0x80270010L)

#if (_WIN32_WINNT >= 0x0601)

#define NAP_E_SHV_CONFIG_EXISTED        _HRESULT_TYPEDEF_(0x80270011L)
#define NAP_E_SHV_CONFIG_NOT_FOUND      _HRESULT_TYPEDEF_(0x80270012L)
#define NAP_E_SHV_TIMEOUT               _HRESULT_TYPEDEF_(0x80270013L)

#endif /*(_WIN32_WINNT >= 0x0601)*/

#endif /*(_WIN32_WINNT >= 0x0600)*/

#endif /* _INC_NAPERROR */

