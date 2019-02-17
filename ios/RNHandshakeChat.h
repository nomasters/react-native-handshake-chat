
#if __has_include("RCTBridgeModule.h")
#import "RCTBridgeModule.h"
#else
#import <React/RCTBridgeModule.h>
#endif

#import "Handshake/Handshake.h"

@interface RNHandshakeChat : NSObject <RCTBridgeModule>

@end
  
