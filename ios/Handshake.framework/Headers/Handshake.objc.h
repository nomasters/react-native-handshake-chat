// Objective-C API for talking to github.com/nomasters/handshake Go package.
//   gobind -lang=objc github.com/nomasters/handshake
//
// File is generated by gobind. Do not edit.

#ifndef __Handshake_H__
#define __Handshake_H__

@import Foundation;
#include "Universe.objc.h"

@class HandshakeProfile;
@class HandshakeSecretBoxCipher;
@class HandshakeSession;
@class HandshakeSessionOptions;
@class HandshakeStorageOptions;

/**
 * Profile represents a profile that has been accessed
this would contain successfully decrypted profile data
 */
@interface HandshakeProfile : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (NSString*)id_;
- (void)setID:(NSString*)v;
- (NSData*)key;
- (void)setKey:(NSData*)v;
// skipped field Profile.Settings with unsupported type: github.com/nomasters/handshake.profileSettings

/**
 * IDBytes converts the ID string in base64 to decoded bytes
 */
- (NSData*)idBytes:(NSError**)error;
/**
 * KeyBase64 returns a base64 encoded string of the key
 */
- (NSString*)keyBase64;
/**
 * KeyHex returns a hex encoded string of the key
 */
- (NSString*)keyHex;
@end

/**
 * SecretBoxCipher is a struct and method set that conforms to the Cipher interface. This is the primary cipher used
for all blob encryption and decryption for handshake
 */
@interface HandshakeSecretBoxCipher : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
// skipped field SecretBoxCipher.Nonce with unsupported type: github.com/nomasters/handshake.NonceType

- (long)chunkSize;
- (void)setChunkSize:(long)v;
/**
 * Decrypt takes byte slices for data and key and returns the clear text output for secretbox
 */
- (NSData*)decrypt:(NSData*)data key:(NSData*)key error:(NSError**)error;
/**
 * Encrypt takes byte slices for data and a key and returns the ciphertext output for secretbox
 */
- (NSData*)encrypt:(NSData*)data key:(NSData*)key error:(NSError**)error;
@end

/**
 * Session is the primary struct for a logged in  user. It holds the profile data
as well as settings information
 */
@interface HandshakeSession : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
// skipped constructor Session.NewSession with unsupported parameter or return types

/**
 * AddPeerToHandshake takes a json encoded peerConfig, attempts to unmarshal it and add it as a peer.
It returns a bool and an error. The bool indicates if handshake.AllPeersReceived == true, in which case
the handshake can safely be conversted int a chat.
 */
- (BOOL)addPeerToHandshake:(NSData*)body ret0_:(BOOL*)ret0_ error:(NSError**)error;
/**
 * Close gracefully closes the session
 */
- (BOOL)close:(NSError**)error;
// skipped method Session.GetChatlog with unsupported parameter or return types

/**
 * GetHandshakePeerConfig returns the json bytes encoded peerConfig based on peerID or and an error
 */
- (NSData*)getHandshakePeerConfig:(long)sortNumber error:(NSError**)error;
/**
 * GetHandshakePeerTotal returns an int count of the number of peers to expect for a handshake
 */
- (long)getHandshakePeerTotal;
/**
 * GetMyPeerID returns a string of the profile user's peerID for a specific chat, returns the peerID and an error
 */
- (NSString*)getMyPeerID:(NSString*)chatID error:(NSError**)error;
// skipped method Session.GetProfile with unsupported parameter or return types

/**
 * ListChats returns a json encoded list of chatIDs and an error
 */
- (NSData*)listChats:(NSError**)error;
/**
 * NewChat creates a new chat from the activeHandshake and returns a chat ID string and error.
If the chat is successfully created, it deletes the contents of the activeHandshake
 */
- (NSString*)newChat:(NSError**)error;
/**
 * NewInitiatorWithDefaults provides a simple method with no arguments to create a default handshake
for an initiator. Adds this handshake pointer to the ActiveHandshake in the session.
 */
- (void)newInitiatorWithDefaults;
/**
 * NewPeerWithDefaults provides a simple method with no arguments to create a default handshake
for an peer. Adds this handshake pointer to the ActiveHandshake in the session.
 */
- (void)newPeerWithDefaults;
/**
 * RetrieveMessages takes a chatID and initiates the retrieval process for all peers
it returns a json encoded chatLogList and error
 */
- (NSData*)retrieveMessages:(NSString*)chatID error:(NSError**)error;
/**
 * SendMessage takes a chatID and message bytes and submits the message to the message
storage and rendezvous point. It returns a json encoded chatLogList and error
 */
- (NSData*)sendMessage:(NSString*)chatID b:(NSData*)b error:(NSError**)error;
/**
 * ShareHandshakePosition returns the values from negotiator.Share() from the ActiveHandshake
 */
- (NSData*)shareHandshakePosition:(NSError**)error;
@end

/**
 * SessionOptions holds session options for initialization
 */
@interface HandshakeSessionOptions : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
// skipped field SessionOptions.StorageEngine with unsupported type: github.com/nomasters/handshake.StorageEngine

- (NSString*)storageFilePath;
- (void)setStorageFilePath:(NSString*)v;
@end

/**
 * StorageOptions are used to pass in initialization settings
 */
@interface HandshakeStorageOptions : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
// skipped field StorageOptions.Engine with unsupported type: github.com/nomasters/handshake.StorageEngine

- (NSString*)filePath;
- (void)setFilePath:(NSString*)v;
// skipped field StorageOptions.Signatures with unsupported type: []github.com/nomasters/handshake.signatureAlgorithm

// skipped field StorageOptions.ReadNodes with unsupported type: []github.com/nomasters/handshake.node

// skipped field StorageOptions.WriteNodes with unsupported type: []github.com/nomasters/handshake.node

// skipped field StorageOptions.ReadRule with unsupported type: github.com/nomasters/handshake.consensusRule

// skipped field StorageOptions.WriteRule with unsupported type: github.com/nomasters/handshake.consensusRule

@end

// skipped const BoltEngine with unsupported type: github.com/nomasters/handshake.StorageEngine

/**
 * DefaultMaxLoginAttempts is the number of times failed login attempts are allowed
 */
FOUNDATION_EXPORT const int64_t HandshakeDefaultMaxLoginAttempts;
/**
 * DefaultSessionTTL is the default TTL before a Session closes
 */
FOUNDATION_EXPORT const int64_t HandshakeDefaultSessionTTL;
// skipped const HashmapEngine with unsupported type: github.com/nomasters/handshake.StorageEngine

// skipped const IPFSEngine with unsupported type: github.com/nomasters/handshake.StorageEngine

// skipped const RandomNonce with unsupported type: github.com/nomasters/handshake.NonceType

// skipped const SecretBox with unsupported type: github.com/nomasters/handshake.CipherType

// skipped const TimeSeriesNonce with unsupported type: github.com/nomasters/handshake.NonceType

/**
 * Version is the hard coded version of handshake-core running
 */
FOUNDATION_EXPORT NSString* const HandshakeVersion;

/**
 * NewDefaultSession is a wrapper around NewSession and applies simple defaults. This is intended to be used
by the reference apps.
 */
FOUNDATION_EXPORT HandshakeSession* HandshakeNewDefaultSession(NSString* password, NSError** error);

/**
 * NewGenesisProfile takes password and
 */
FOUNDATION_EXPORT BOOL HandshakeNewGenesisProfile(NSString* password, NSError** error);

// skipped function NewSession with unsupported parameter or return types


/**
 * ProfilesExist configures a storage engine and checks `profilesExist`. It returns a bool and error.
This is used on app startup to check to see if this is the first time running the tool. If this function
returns `false` and no errors, the next step would be to prompt the user to setup a new profile using
`NewGenesisProfile()`.
 */
FOUNDATION_EXPORT BOOL HandshakeProfilesExist(BOOL* ret0_, NSError** error);

#endif