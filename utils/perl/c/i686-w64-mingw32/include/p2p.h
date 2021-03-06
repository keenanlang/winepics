/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_P2P
#define _INC_P2P
#if (_WIN32_WINNT >= 0x0600)

#ifdef __cplusplus
extern "C" {
#endif

typedef enum _PEER_APPLICATION_REGISTRATION_TYPE {
  PEER_APPLICATION_CURRENT_USER,
  PEER_APPLICATION_ALL_USERS 
} PEER_APPLICATION_REGISTRATION_TYPE, PEER_APPLICATION_REGISTRATION_FLAGS;

typedef enum _PEER_CHANGE_TYPE {
  PEER_CHANGE_ADDED,
  PEER_CHANGE_DELETED,
  PEER_CHANGE_UPDATED 
} PEER_CHANGE_TYPE;

typedef enum _PEER_COLLAB_EVENT_TYPE {
  PEER_EVENT_WATCHLIST_CHANGED,
  PEER_EVENT_ENDPOINT_CHANGED,
  PEER_EVENT_ENDPOINT_PRESENCE_CHANGED,
  PEER_EVENT_ENDPOINT_APPLICATION_CHANGED,
  PEER_EVENT_ENDPOINT_OBJECT_CHANGED,
  PEER_EVENT_MY_ENDPOINT_CHANGED,
  PEER_EVENT_MY_PRESENCE_CHANGED,
  PEER_EVENT_MY_APPLICATION_CHANGED,
  PEER_EVENT_MY_OBJECT_CHANGED,
  PEER_EVENT_PEOPLE_NEAR_ME_CHANGED,
  PEER_EVENT_REQUEST_STATUS_CHANGED 
} PEER_COLLAB_EVENT_TYPE;

typedef enum _PEER_GROUP_AUTHENTICATION_SCHEME {
  PEER_GROUP_GMC_AUTHENTICATION        = 0x00000001,
  PEER_GROUP_PASSWORD_AUTHENTICATION   = 0x00000002 
} PEER_GROUP_AUTHENTICATION_SCHEME;

typedef enum _PEER_GROUP_ISSUE_CREDENTIAL_FLAGS {
  PEER_GROUP_STORE_CREDENTIALS   = 0x0001 
} PEER_GROUP_ISSUE_CREDENTIAL_FLAGS;

typedef enum _PEER_INVITATION_RESPONSE_TYPE {
  PEER_INVITATION_RESPONSE_DECLINED,
  PEER_INVITATION_RESPONSE_ACCEPTED,
  PEER_INVITATION_RESPONSE_EXPIRED,
  PEER_INVITATION_RESPONSE_ERROR 
} PEER_INVITATION_RESPONSE_TYPE;

typedef enum _PEER_PRESENCE_STATUS {
  PEER_PRESENCE_OFFLINE,
  PEER_PRESENCE_OUT_TO_LUNCH,
  PEER_PRESENCE_AWAY,
  PEER_PRESENCE_BE_RIGHT_BACK,
  PEER_PRESENCE_IDLE,
  PEER_PRESENCE_BUSY,
  PEER_PRESENCE_ON_THE_PHONE,
  PEER_PRESENCE_ONLINE 
} PEER_PRESENCE_STATUS;

typedef enum _PEER_PUBLICATION_SCOPE {
  PEER_PUBLICATION_SCOPE_NONE,
  PEER_PUBLICATION_SCOPE_NEAR_ME,
  PEER_PUBLICATION_SCOPE_INTERNET,
  PEER_PUBLICATION_SCOPE_ALL 
} PEER_PUBLICATION_SCOPE;

typedef enum _PEER_SIGNIN_FLAGS {
  PEER_SIGNIN_NONE,
  PEER_SIGNIN_NEAR_ME,
  PEER_SIGNIN_INTERNET,
  PEER_SIGNIN_ALL 
} PEER_SIGNIN_FLAGS;

typedef enum _PEER_WATCH_PERMISSION {
  PEER_WATCH_BLOCKED,
  PEER_WATCH_ALLOWED 
} PEER_WATCH_PERMISSION;

typedef struct _PEER_CONTACT *PPEER_CONTACT;
typedef struct _PEER_ENDPOINT *PPEER_ENDPOINT;
typedef struct _PEER_INVITATION *PPEER_INVITATION;
typedef struct _PEER_OBJECT *PPEER_OBJECT;
typedef struct _PEER_PEOPLE_NEAR_ME *PPEER_PEOPLE_NEAR_ME;
typedef struct _PEER_PRESENCE_INFO *PPEER_PRESENCE_INFO;
typedef LPVOID HPEERENUM;
typedef LPVOID HPEEREVENT;

typedef struct peer_address_tag {
  DWORD        dwSize;
  SOCKADDR_IN6 sin6;
} PEER_ADDRESS, *PPEER_ADDRESS;

typedef struct _PEER_APP_LAUNCH_INFO {
  PPEER_CONTACT    pContact;
  PPEER_ENDPOINT   pEndpoint;
  PPEER_INVITATION pInvitation;
} PEER_APP_LAUNCH_INFO, *PPEER_APP_LAUNCH_INFO;
typedef const PEER_APP_LAUNCH_INFO *PCPEER_APP_LAUNCH_INFO;

typedef struct peer_data_tag {
  ULONG cbData;
  PBYTE pbData;
} PEER_DATA, *PPEER_DATA;

typedef struct _PEER_APPLICATION {
  GUID      id;
  PEER_DATA data;
  PWSTR     pwzDescription;
} PEER_APPLICATION, *PPEER_APPLICATION;
typedef const PEER_APPLICATION *PCPEER_APPLICATION;

typedef struct _PEER_APPLICATION_REGISTRATION_INFO {
  PEER_APPLICATION application;
  PWSTR            pwzApplicationToLaunch;
  PWSTR            pwzApplicationArguments;
  DWORD            dwPublicationScope;
} PEER_APPLICATION_REGISTRATION_INFO, *PPEER_APPLICATION_REGISTRATION_INFO;
typedef const PEER_APPLICATION_REGISTRATION_INFO *PCPEER_APPLICATION_REGISTRATION_INFO;

typedef struct _PEER_EVENT_APPLICATION_CHANGED_DATA {
  PPEER_CONTACT     pContact;
  PPEER_ENDPOINT    pEndpoint;
  PEER_CHANGE_TYPE  changeType;
  PPEER_APPLICATION pApplication;
} PEER_EVENT_APPLICATION_CHANGED_DATA, *PPEER_EVENT_APPLICATION_CHANGED_DATA;

typedef struct _PEER_EVENT_ENDPOINT_CHANGED_DATA {
  PPEER_CONTACT  pContact;
  PPEER_ENDPOINT pEndpoint;
} PEER_EVENT_ENDPOINT_CHANGED_DATA, *PPEER_EVENT_ENDPOINT_CHANGED_DATA;

typedef struct _PEER_EVENT_OBJECT_CHANGED_DATA {
  PPEER_CONTACT    pContact;
  PPEER_ENDPOINT   pEndpoint;
  PEER_CHANGE_TYPE changeType;
  PPEER_OBJECT     pObject;
} PEER_EVENT_OBJECT_CHANGED_DATA, *PPEER_EVENT_OBJECT_CHANGED_DATA;

typedef struct _PEER_EVENT_PEOPLE_NEAR_ME_CHANGED_DATA {
  PEER_CHANGE_TYPE     changeType;
  PPEER_PEOPLE_NEAR_ME pPeopleNearMe;
} PEER_EVENT_PEOPLE_NEAR_ME_CHANGED_DATA, *PPEER_EVENT_PEOPLE_NEAR_ME_CHANGED_DATA;

typedef struct _PEER_EVENT_PRESENCE_CHANGED_DATA {
  PPEER_CONTACT       pContact;
  PPEER_ENDPOINT      pEndpoint;
  PEER_CHANGE_TYPE    changeType;
  PPEER_PRESENCE_INFO pPresenceInfo;
} PEER_EVENT_PRESENCE_CHANGED_DATA, *PPEER_EVENT_PRESENCE_CHANGED_DATA;

typedef struct _PEER_EVENT_REQUEST_STATUS_CHANGED_DATA {
  PPEER_ENDPOINT pEndpoint;
  HRESULT        hrChange;
} PEER_EVENT_REQUEST_STATUS_CHANGED_DATA, *PPEER_EVENT_REQUEST_STATUS_CHANGED_DATA;

typedef struct _PEER_EVENT_WATCHLIST_CHANGED_DATA {
  PPEER_CONTACT    pContact;
  PEER_CHANGE_TYPE changeType;
} PEER_EVENT_WATCHLIST_CHANGED_DATA, *PPEER_EVENT_WATCHLIST_CHANGED_DATA;

typedef struct _PEER_INVITATION {
  GUID      applicationId;
  PEER_DATA applicationData;
  PWSTR     pwzMessage;
} PEER_INVITATION, *PPEER_INVITATION;
typedef const PEER_INVITATION *PCPEER_INVITATION;

typedef union _PEER_COLLAB_EVENT_DATA {
  PEER_COLLAB_EVENT_TYPE eventType;
  __C89_NAMELESS union {
    PEER_EVENT_WATCHLIST_CHANGED_DATA watchlistChangedData;
    PEER_EVENT_PRESENCE_CHANGED_DATA presenceChangedData;
    PEER_EVENT_APPLICATION_CHANGED_DATA applicationChangedData;
    PEER_EVENT_OBJECT_CHANGED_DATA objectChangedData;
    PEER_EVENT_ENDPOINT_CHANGED_DATA endpointChangedData;
    PEER_EVENT_PEOPLE_NEAR_ME_CHANGED_DATA peopleNearMeChangedData;
    PEER_EVENT_REQUEST_STATUS_CHANGED_DATA requestStatusChangedData;
  } DUMMYUNIONNAME;
} PEER_COLLAB_EVENT_DATA, *PPEER_COLLAB_EVENT_DATA;

typedef struct _PEER_COLLAB_EVENT_REGISTRATION{
  PEER_COLLAB_EVENT_TYPE eventType;
  GUID *                 pInstance;
} PEER_COLLAB_EVENT_REGISTRATION, *PPEER_COLLAB_EVENT_REGISTRATION;
typedef const PEER_COLLAB_EVENT_REGISTRATION *PCPEER_COLLAB_EVENT_REGISTRATION;

typedef struct {
  PEER_INVITATION_RESPONSE_TYPE action;
  PWSTR                         pwzMessage;
  HRESULT                       hrExtendedInfo;
} PEER_INVITATION_RESPONSE, *PPEER_INVITATION_RESPONSE;
typedef const PEER_INVITATION_RESPONSE *PCPEER_INVITATION_RESPONSE;

typedef struct _PEER_CONTACT {
  PWSTR                 pwzPeerName;
  PWSTR                 pwzNickName;
  PWSTR                 pwzDisplayName;
  PWSTR                 pwzEmailAddress;
  WINBOOL              fWatch;
  PEER_WATCH_PERMISSION WatcherPermissions;
  PEER_DATA             credentials;
} PEER_CONTACT, *PPEER_CONTACT;
typedef const PEER_CONTACT *PCPEER_CONTACT;

typedef struct _PEER_ENDPOINT {
  PEER_ADDRESS address;
  PWSTR        pwzEndpointName;
} PEER_ENDPOINT, *PPEER_ENDPOINT;
typedef const PEER_ENDPOINT *PCPEER_ENDPOINT;

typedef struct _PEER_OBJECT {
  GUID      id;
  PEER_DATA data;
  DWORD     dwPublicationScope;
} PEER_OBJECT, *PPEER_OBJECT;
typedef const PEER_OBJECT *PCPEER_OBJECT;

typedef struct _PEER_PEOPLE_NEAR_ME {
  PWSTR         pwzNickName;
  PEER_ENDPOINT endpoint;
  GUID          id;
} PEER_PEOPLE_NEAR_ME, *PPEER_PEOPLE_NEAR_ME, *PCPEER_PEOPLE_NEAR_ME, **PPPEER_PEOPLE_NEAR_ME;

typedef struct _PEER_PRESENCE_INFO {
  PEER_PRESENCE_STATUS status;
  PWSTR                pwzDescriptiveText;
} PEER_PRESENCE_INFO, *PPEER_PRESENCE_INFO;
typedef const PEER_PRESENCE_INFO *PCPEER_PRESENCE_INFO;

HRESULT WINAPI PeerCollabAddContact(
  PCWSTR pwzContactData,
  PPEER_CONTACT *ppContact
);

HRESULT WINAPI PeerCollabAsyncInviteContact(
  PCPEER_CONTACT pcContact,
  PPEER_ENDPOINT pcEndpoint,
  PCPEER_INVITATION pcInvitation,
  HANDLE hEvent,
  HANDLE *phInvitation
);

HRESULT WINAPI PeerCollabAsyncInviteEndpoint(
  PPEER_ENDPOINT pcEndpoint,
  PCPEER_INVITATION pcInvitation,
  HANDLE hEvent,
  HANDLE *phInvitation
);

HRESULT WINAPI PeerCollabCancelInvitation(
  HANDLE hInvitation
);

HRESULT WINAPI PeerCollabCloseHandle(
  HANDLE handle
);

HRESULT WINAPI PeerCollabDeleteContact(
  PCWSTR pwzPeerName
);

HRESULT WINAPI PeerCollabDeleteEndpointData(
  PCPEER_ENDPOINT pcEndpoint
);

HRESULT WINAPI PeerCollabDeleteObject(
  const GUID *pObjectId
);

HRESULT WINAPI PeerCollabEnumApplicationRegistrationInfo(
  PEER_APPLICATION_REGISTRATION_TYPE registrationType,
  HPEERENUM *phPeerEnum
);

HRESULT WINAPI PeerCollabEnumApplications(
  PCPEER_ENDPOINT pcEndpoint,
  const GUID *pApplicationId,
  HPEERENUM *phPeerEnum
);

HRESULT WINAPI PeerCollabEnumContacts(
  HPEERENUM *phPeerEnum
);

HRESULT WINAPI PeerCollabEnumEndpoints(
  PCPEER_CONTACT pcContact,
  HPEERENUM *phPeerEnum
);

HRESULT  WINAPI PeerCollabEnumObjects(
  PCPEER_ENDPOINT pcEndpoint,
  const GUID *pObjectId,
  HPEERENUM *phPeerEnum
);

HRESULT WINAPI PeerCollabEnumPeopleNearMe(
  HPEERENUM *phPeerEnum
);

HRESULT WINAPI PeerCollabExportContact(
  PWSTR pwzPeerName,
  PWSTR *ppwzContactData
);

HRESULT  WINAPI PeerCollabGetAppLaunchInfo(
  PPEER_APP_LAUNCH_INFO *ppLaunchInfo
);

HRESULT WINAPI PeerCollabGetApplicationRegistrationInfo(
  const GUID *pApplicationId,
  PEER_APPLICATION_REGISTRATION_TYPE registrationType,
  PPEER_APPLICATION_REGISTRATION_INFO *ppRegInfo
);

HRESULT WINAPI PeerCollabGetContact(
  PWSTR pwzPeerName,
  PCPEER_CONTACT *ppContact
);

HRESULT WINAPI PeerCollabGetEndpointName(
  PWSTR *ppwzEndpointName
);

HRESULT WINAPI PeerCollabGetEventData(
  HPEEREVENT hPeerEvent,
  PPEER_COLLAB_EVENT_DATA *ppEventData
);

HRESULT  WINAPI PeerCollabGetInvitationResponse(
  HANDLE hInvitation,
  PPEER_INVITATION_RESPONSE *ppInvitationResponse
);

HRESULT WINAPI PeerCollabGetPresenceInfo(
  PCPEER_ENDPOINT pEndpoint,
  PPEER_PRESENCE_INFO *ppPresenceInfo
);

HRESULT  WINAPI PeerCollabGetSigninOptions(
  DWORD *dwSigninOptions
);

HRESULT WINAPI PeerCollabInviteContact(
  PCPEER_CONTACT pcContact,
  PCPEER_ENDPOINT pcEndpoint,
  const PCPEER_INVITATION pcInvitation,
  PPEER_INVITATION_RESPONSE *ppResponse
);

HRESULT  WINAPI PeerCollabInviteEndpoint(
  PCPEER_ENDPOINT pcEndpoint,
  PCPEER_INVITATION pcInvitation,
  PPEER_INVITATION_RESPONSE *ppResponse
);

HRESULT WINAPI PeerCollabParseContact(
  PWSTR pwzContactData,
  PCPEER_CONTACT *ppContact
);

HRESULT WINAPI PeerCollabQueryContactData(
  PCPEER_ENDPOINT pcEndpoint,
  PWSTR *ppwzContactData
);

HRESULT WINAPI PeerCollabRefreshEndpointData(
  PCPEER_ENDPOINT pcEndpoint
);

HRESULT  WINAPI PeerCollabRegisterApplication(
  PCPEER_APPLICATION_REGISTRATION_INFO pcApplication,
  PEER_APPLICATION_REGISTRATION_FLAGS registrationType
);

HRESULT  WINAPI PeerCollabRegisterEvent(
  HANDLE hEvent,
  DWORD cEventRegistration,
  PPEER_COLLAB_EVENT_REGISTRATION pEventRegistrations,
  HPEEREVENT *phPeerEvent
);

HRESULT WINAPI PeerCollabSetEndpointName(
  PCWSTR pwzEndpointName
);

HRESULT  WINAPI PeerCollabSetObject(
  PCPEER_OBJECT pcObject
);

HRESULT WINAPI PeerCollabSetPresenceInfo(
  PCPEER_PRESENCE_INFO pcPresenceInfo
);

HRESULT WINAPI PeerCollabShutdown(void);

HRESULT  WINAPI PeerCollabSignin(
  HWND hwndParent,
  DWORD dwSigninOptions
);

HRESULT  WINAPI PeerCollabSignout(
  DWORD dwSignoutOptions
);

HRESULT  WINAPI PeerCollabStartup(
  WORD wVersionRequested
);

HRESULT WINAPI PeerCollabSubscribeEndpointData(
  PCPEER_ENDPOINT pcEndpoint
);

HRESULT  WINAPI PeerCollabUnregisterApplication(
  const GUID *pApplicationID,
  PEER_APPLICATION_REGISTRATION_FLAGS registrationType
);

HRESULT  WINAPI PeerCollabUnregisterEvent(
  HPEEREVENT hPeerEvent
);

HRESULT WINAPI PeerCollabUnsubscribeEndpointData(
  PCPEER_ENDPOINT pcEndpoint
);

HRESULT  WINAPI PeerCollabUpdateContact(
  PCPEER_CONTACT pContact
);

#ifdef __cplusplus
}
#endif
#endif /* (_WIN32_WINNT >= 0x0600) */
#endif /*_INC_P2P*/
