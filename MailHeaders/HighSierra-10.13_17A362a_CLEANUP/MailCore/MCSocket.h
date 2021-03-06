//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

//#import "NSObject.h"

//#import "NSStreamDelegate-Protocol.h"

@class NSArray, NSData, NSInputStream, NSOutputStream, NSPort, NSString;

@interface MCSocket : NSObject <NSStreamDelegate>
{
    NSArray *_clientCertificates;
    BOOL _useSSL;
    BOOL _disableEphemeralDiffieHellmanCiphers;
    BOOL _scheduledForBytesToArrive;
    unsigned long long _identifier;
    long long _activityType;
    double _connectTimeout;
    double _readWriteTimeout;
    NSArray *_trustedCertificates;
    NSPort *_wakeupPort;
    NSInputStream *_inputStream;
    NSOutputStream *_outputStream;
//    CDUnknownBlockType _bytesAvailableHandler;
}

+ (id)log;
@property BOOL scheduledForBytesToArrive; // @synthesize scheduledForBytesToArrive=_scheduledForBytesToArrive;
//@property(copy) CDUnknownBlockType bytesAvailableHandler; // @synthesize bytesAvailableHandler=_bytesAvailableHandler;
@property(retain) NSOutputStream *outputStream; // @synthesize outputStream=_outputStream;
@property(retain) NSInputStream *inputStream; // @synthesize inputStream=_inputStream;
@property(readonly, nonatomic) NSPort *wakeupPort; // @synthesize wakeupPort=_wakeupPort;
@property BOOL disableEphemeralDiffieHellmanCiphers; // @synthesize disableEphemeralDiffieHellmanCiphers=_disableEphemeralDiffieHellmanCiphers;
@property(copy) NSArray *trustedCertificates; // @synthesize trustedCertificates=_trustedCertificates;
@property(nonatomic) double readWriteTimeout; // @synthesize readWriteTimeout=_readWriteTimeout;
@property(nonatomic) double connectTimeout; // @synthesize connectTimeout=_connectTimeout;
@property long long activityType; // @synthesize activityType=_activityType;
@property(readonly) unsigned long long identifier; // @synthesize identifier=_identifier;
//- (void).cxx_destruct;
- (void)stream:(id)arg1 handleEvent:(unsigned long long)arg2;
@property(readonly, nonatomic) BOOL isExpensive;
- (void)_cancelLookupForHost:(struct __CFHost *)arg1 infoType:(int)arg2;
@property(readonly, copy, nonatomic) NSString *sourceHostname;
@property(readonly, copy, nonatomic) NSData *sourceIPAddress;
@property(readonly, nonatomic) long long remotePortNumber;
@property(readonly, copy, nonatomic) NSString *remoteHostname;
@property(readonly, nonatomic) BOOL isValid;
@property(readonly, nonatomic) BOOL isWritable;
@property(readonly, nonatomic) BOOL isReadable;
@property(readonly, nonatomic) unsigned int cipherKeyLength;
- (struct __SecTrust *)serverTrust;
@property(readonly, copy, nonatomic) NSString *securityLevel;
- (void)_unscheduleInputStreamFromMainRunLoopIfNecessary;
- (void)_scheduleInputStreamInMainRunLoopIfNecessary;
- (void)unregisterForBytesToArrive;
//- (void)registerForBytesToArriveWithHandler:(CDUnknownBlockType)arg1;
- (void)close;
- (BOOL)_handleReadWriteErrorOnStream:(id)arg1 timedOut:(BOOL)arg2 logDetails:(id)arg3 error:(id *)arg4;
- (long long)writeBytes:(const void *)arg1 maxLength:(unsigned long long)arg2 error:(id *)arg3;
- (long long)readBytes:(void *)arg1 maxLength:(unsigned long long)arg2 error:(id *)arg3;
- (id)_waitForSecurityLayerNegotiationStreamsAreScheduled:(BOOL)arg1;
- (BOOL)_setSSLStreamProperties:(BOOL)arg1;
- (BOOL)_setupStreamsWithHostname:(id)arg1 port:(long long)arg2 needToEstablishInternetConnection:(char *)arg3 useSSL:(char *)arg4 isBackground:(BOOL)arg5 error:(id *)arg6;
- (BOOL)connectToHost:(id)arg1 withPort:(long long)arg2 isBackground:(BOOL)arg3;
- (void)setClientIdentity:(struct OpaqueSecIdentityRef *)arg1;
- (BOOL)setUsesSSL:(BOOL)arg1;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

