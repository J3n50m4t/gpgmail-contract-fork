//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

//#import "NSObject.h"

#import "MFMessageConsumer.h"

@class MCInvocationQueue, MFLibraryStore, NSString;

@interface MFLibraryStoreMessageConsumer : NSObject <MFMessageConsumer>
{
    BOOL _shouldCancel;	// 8 = 0x8
    long long _collectorID;	// 16 = 0x10
    MFLibraryStore *_libraryStore;	// 24 = 0x18
    MCInvocationQueue *_callbackQueue;	// 32 = 0x20
}

@property(readonly, nonatomic) MCInvocationQueue *callbackQueue; // @synthesize callbackQueue=_callbackQueue;
@property(nonatomic) __weak MFLibraryStore *libraryStore; // @synthesize libraryStore=_libraryStore;
@property BOOL shouldCancel; // @synthesize shouldCancel=_shouldCancel;
@property long long collectorID; // @synthesize collectorID=_collectorID;
- (void).cxx_destruct;	// IMP=0x000000000015f074
- (void)finishedSendingMessages;	// IMP=0x000000000015eeda
- (void)searchPhaseComplete;	// IMP=0x000000000015ee8e
- (void)newMessagesAvailable:(id)arg1 secondaryMessages:(id)arg2 options:(id)arg3;	// IMP=0x000000000015ed7d
- (void)clearLibraryStoreWeakReference;	// IMP=0x000000000015ed69
- (id)init;	// IMP=0x000000000015ec9a
- (id)initWithLibraryStore:(id)arg1;	// IMP=0x000000000015ebef

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

