//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MFAccount.h"
//
//#import "MCActivityTarget.h"
//#import "MCMailAccount.h"
//#import "MFMessageDelivererDelegate.h"
//#import "NSFileManagerDelegate.h"

@class MCAuthScheme, MCTaskManager, MFDeliveryAccount, MFMailbox, NSArray, NSError, NSNumber, NSOperationQueue, NSString, NSTimer, NSURL;

@interface MFMailAccount : MFAccount /*<MCActivityTarget, MCMailAccount, MFMessageDelivererDelegate, NSFileManagerDelegate>*/
{
    id _mailAccountLock;	// 8 = 0x8
    id _mailboxLock;	// 16 = 0x10
    MFMailbox *_inboxMailbox;	// 24 = 0x18
    MFMailbox *_rootMailbox;	// 32 = 0x20
    MFMailbox *_draftsMailbox;	// 40 = 0x28
    MFMailbox *_sentMessagesMailbox;	// 48 = 0x30
    MFMailbox *_trashMailbox;	// 56 = 0x38
    MFMailbox *_junkMailbox;	// 64 = 0x40
    MFMailbox *_notesMailbox;	// 72 = 0x48
    MFMailbox *_todosMailbox;	// 80 = 0x50
    MFMailbox *_outboxMailbox;	// 88 = 0x58
    MFMailbox *_archiveMailbox;	// 96 = 0x60
    NSError *_connectionError;	// 104 = 0x68
    id _cacheChangeLock;	// 112 = 0x70
    NSTimer *_cacheWriteTimer;	// 120 = 0x78
    id _backgroundActivityFlagsLock;	// 128 = 0x80
    BOOL _cacheHasBeenRead;	// 136 = 0x88
    BOOL _mailboxListInitializationInProgress;	// 137 = 0x89
    BOOL _needsChecking;	// 138 = 0x8a
    MCTaskManager *_taskManager;	// 144 = 0x90
    NSOperationQueue *_backgroundWorkQueue;	// 152 = 0x98
    NSURL *_accountDirectory;	// 160 = 0xa0
}

+ (id)keyPathsForValuesAffectingURLPersistenceHostname;	// IMP=0x00000000001a4f01
+ (id)_mailboxNameForPathComponent:(id)arg1;	// IMP=0x000000000019f4fa
+ (id)_pathComponentForMailboxName:(id)arg1;	// IMP=0x000000000019f4e5
+ (void)_postMailAccountsHaveChanged;	// IMP=0x000000000019f346
+ (id)_accountWithFileSystemPath:(id)arg1 relativePath:(id *)arg2;	// IMP=0x000000000019e85f
+ (void)_enableMailboxListingNotifications:(BOOL)arg1;	// IMP=0x000000000019e697
+ (void)_disableMailboxListingNotifications;	// IMP=0x000000000019e609
+ (BOOL)_mailboxListingNotificationAreEnabled;	// IMP=0x000000000019e57a
+ (BOOL)_mailAccountsAreInitialized;	// IMP=0x000000000019e56a
+ (void)_normalizePathComponentsInMailboxesDictionary:(id)arg1 accountClass:(Class)arg2;	// IMP=0x000000000019e3a7
+ (void)normalizeMailboxPathComponentsInAllAccounts;	// IMP=0x000000000019dd87
+ (void)resetCachedAccountPaths;	// IMP=0x000000000019d85b
+ (id)mailboxForURL:(id)arg1 forceCreation:(BOOL)arg2 syncableURL:(BOOL)arg3;	// IMP=0x000000000019d2a6
+ (id)accountWithURLString:(id)arg1 includeInactiveAccounts:(BOOL)arg2;	// IMP=0x000000000019d206
+ (id)accountWithURLString:(id)arg1;	// IMP=0x000000000019d1f2
+ (id)URLForInfo:(id)arg1;	// IMP=0x000000000019d022
+ (id)infoForURL:(id)arg1;	// IMP=0x000000000019cf74
+ (id)_accountForURL:(id)arg1;	// IMP=0x000000000019cf60
+ (id)accountWithSyncableURLString:(id)arg1 includeInactiveAccounts:(BOOL)arg2;	// IMP=0x000000000019cd56
+ (id)_accountForURL:(id)arg1 includeInactiveAccounts:(BOOL)arg2;	// IMP=0x000000000019c7bd
+ (void)_inferMissingCanonicalEmailAddressesForAccounts:(id)arg1 usingEmailAddresses:(id)arg2;	// IMP=0x000000000019a687
+ (void)inferMissingCanonicalEmailAddresses;	// IMP=0x000000000019a2e8
+ (id)mailboxForFileSystemPath:(id)arg1 create:(BOOL)arg2;	// IMP=0x000000000019713c
+ (void)resetAllSpecialMailboxes;	// IMP=0x0000000000196fae
+ (void)synchronouslyEmptyMailboxType:(int)arg1 inAccounts:(id)arg2;	// IMP=0x00000000001965c2
+ (BOOL)allAccountsDeleteInPlace;	// IMP=0x00000000001962b3
+ (long long)numberOfDaysToKeepLocalTrash;	// IMP=0x0000000000195dc6
+ (id)accountsInitializingMailboxList;	// IMP=0x0000000000194fab
+ (void)connectAllAccounts;	// IMP=0x000000000019462f
+ (void)disconnectAllAccounts;	// IMP=0x000000000019461b
+ (void)_setOnlineStateOfAllAccountsTo:(BOOL)arg1;	// IMP=0x000000000019442b
+ (BOOL)isAnyAccountOnline;	// IMP=0x0000000000194281
+ (BOOL)isAnyAccountOffline;	// IMP=0x00000000001940d7
+ (void)refreshAllEmailAliases;	// IMP=0x0000000000193179
+ (id)defaultDeliveryAccount;	// IMP=0x0000000000190163
+ (id)accountDirectoryForSystemAccount:(id)arg1;	// IMP=0x000000000018fe0d
+ (id)newAccountWithSystemAccount:(id)arg1;	// IMP=0x000000000018f3ac
+ (id)accountWithPath:(id)arg1;	// IMP=0x000000000018f2d7
+ (id)allMailboxes;	// IMP=0x000000000018efda
+ (id)archiveMailboxes;	// IMP=0x000000000018ef6d
+ (id)junkMailboxes;	// IMP=0x000000000018ef3a
+ (id)draftMailboxes;	// IMP=0x000000000018ef07
+ (id)sentMessagesMailboxes;	// IMP=0x000000000018eed4
+ (id)outboxMailboxes;	// IMP=0x000000000018eea1
+ (id)trashMailboxes;	// IMP=0x000000000018ee6e
+ (id)inboxMailboxes;	// IMP=0x000000000018ee3d
+ (id)_specialMailboxesUsingBlock:(CDUnknownBlockType)arg1;	// IMP=0x000000000018ec26
+ (void)setOrderedActiveMailAccounts:(id)arg1;	// IMP=0x000000000018eb7e
+ (id)orderedActiveMailAccounts;	// IMP=0x000000000018e751
+ (id)specialMailboxes;	// IMP=0x000000000018e4ad
+ (id)outboxMessageStore:(BOOL)arg1;	// IMP=0x000000000018e423
+ (id)accountThatReceivedMessage:(id)arg1 matchingEmailAddress:(id *)arg2 fullUserName:(id *)arg3;	// IMP=0x000000000018dcfb
+ (id)preferredEmailAddressToReplyToMessage:(id)arg1;	// IMP=0x000000000018dac8
+ (id)addressesThatReceivedMessage:(id)arg1;	// IMP=0x000000000018d70a
+ (id)accountThatMessageIsFrom:(id)arg1;	// IMP=0x000000000018d67e
+ (id)accountUsingHeadersFromMessage:(id)arg1;	// IMP=0x000000000018d5d9
+ (id)accountForHeaders:(id)arg1 message:(id)arg2;	// IMP=0x000000000018d4ce
+ (id)accountContainingEmailAddress:(id)arg1;	// IMP=0x000000000018d4b7
+ (id)_accountContainingEmailAddress:(id)arg1 matchingAddress:(id *)arg2 fullUserName:(id *)arg3;	// IMP=0x000000000018ccb6
+ (BOOL)isEmailAddressInAnyAccount:(id)arg1;	// IMP=0x000000000018c742
+ (id)allEmailAddressesIncludingDisplayName:(BOOL)arg1;	// IMP=0x000000000018c089
+ (id)accountWithParentIdentifier:(id)arg1;	// IMP=0x000000000018be75
+ (id)_accountFromArray:(id)arg1 withIdentifier:(id)arg2;	// IMP=0x000000000018bc41
+ (id)accountWithIdentifier:(id)arg1;	// IMP=0x000000000018baaf
+ (void)migrateUnreadCountInMailboxCache;	// IMP=0x000000000018b237
+ (void)saveAccountInfoToDefaults;	// IMP=0x000000000018b166
+ (id)remoteAccounts;	// IMP=0x000000000018b07c
+ (BOOL)onlyGmailAccountsUsingAllMailAsArchiveAreActive;	// IMP=0x000000000018adfe
+ (id)activeAccounts;	// IMP=0x000000000018ad9f
+ (id)_activeAccountsFromArray:(id)arg1;	// IMP=0x000000000018ac59
+ (void)_removeAccountFromSortedPaths:(id)arg1;	// IMP=0x000000000018aa60
+ (void)_setMailAccounts:(id)arg1 reloadingFromStorage:(BOOL)arg2;	// IMP=0x000000000018a0c8
+ (void)setMailAccounts:(id)arg1;	// IMP=0x000000000018a0b4
+ (id)mailAccounts;	// IMP=0x000000000018a020
+ (id)_systemAccountsWithTypeIdentifiers:(id)arg1 accountStore:(id)arg2;	// IMP=0x0000000000189d2d
+ (id)_newAccountsAndExistingAccounts:(id *)arg1 forAccountTypeIdentifiers:(id)arg2;	// IMP=0x00000000001899d9
+ (void)reloadMailAccounts;	// IMP=0x000000000018969d
+ (BOOL)discoverSettingsForIncompleteAccounts;	// IMP=0x00000000001893c7
+ (void)_setupSortedPathsForAccounts:(id)arg1;	// IMP=0x0000000000189244
+ (void)_addAccountToSortedPaths:(id)arg1;	// IMP=0x0000000000188f01
+ (void)completeDeferredAccountInitialization;	// IMP=0x0000000000188d49
+ (BOOL)haveAccountsBeenConfigured;	// IMP=0x0000000000188a12
+ (BOOL)accountsHaveBeenInitialized;	// IMP=0x00000000001889fe
+ (void)initialize;	// IMP=0x0000000000188921
+ (id)accountFetchLog;	// IMP=0x00000000001888c2
@property(readonly, nonatomic) NSURL *accountDirectory; // @synthesize accountDirectory=_accountDirectory;
@property(readonly, nonatomic) NSOperationQueue *backgroundWorkQueue; // @synthesize backgroundWorkQueue=_backgroundWorkQueue;
@property(readonly, nonatomic) MCTaskManager *taskManager; // @synthesize taskManager=_taskManager;
//- (void).cxx_destruct;	// IMP=0x00000000001a54ab
- (id)rootMailboxEvenIfInactive:(BOOL)arg1;	// IMP=0x00000000001a5360
- (id)_mailboxPathPrefix:(BOOL)arg1;	// IMP=0x00000000001a5341
- (id)_URLForInfo:(id)arg1;	// IMP=0x00000000001a4f33
@property(readonly, copy) NSString *URLPersistenceHostname;
@property(readonly, copy, nonatomic) NSString *URLPersistenceScheme;
- (id)_infoForMatchingURL:(id)arg1;	// IMP=0x00000000001a4d90
@property(readonly, nonatomic) BOOL shouldLogDeleteActivity;
- (BOOL)_canEmptyMessagesFromMailbox:(id)arg1;	// IMP=0x00000000001a4cfb
- (id)_specialMailboxWithType:(int)arg1 create:(BOOL)arg2;	// IMP=0x00000000001a4aa8
- (id)_mailDataclassPropertyForSpecialMailboxType:(int)arg1;	// IMP=0x00000000001a4a24
- (void)_setSpecialMailboxRelativePath:(id)arg1 forType:(int)arg2;	// IMP=0x00000000001a48f3
- (id)_specialMailboxRelativePathForType:(int)arg1;	// IMP=0x00000000001a4835
- (void)_setSpecialMailbox:(id)arg1 forType:(int)arg2;	// IMP=0x00000000001a4770
- (BOOL)_assignSpecialMailboxToAppropriateIvar:(id)arg1 forType:(int)arg2;	// IMP=0x00000000001a40f8
- (id)_defaultSpecialMailboxRelativePathForType:(int)arg1;	// IMP=0x00000000001a3fec
- (void)_clearAllPathBasedCachesAndDelete:(BOOL)arg1;	// IMP=0x00000000001a3dba
- (void)_emptySpecialMailboxesIfNeededForQuit:(BOOL)arg1;	// IMP=0x00000000001a39f8
- (void)_emptySpecialMailboxesIfNeeded;	// IMP=0x00000000001a39e4
- (BOOL)_deleteMailbox:(id)arg1 reflectToServer:(BOOL)arg2;	// IMP=0x00000000001a394a
- (BOOL)_setChildren:(id)arg1 addedChild:(id)arg2 forMailbox:(id)arg3;	// IMP=0x00000000001a36cd
- (BOOL)_setChildren:(id)arg1 forMailbox:(id)arg2;	// IMP=0x00000000001a367e
- (id)_insertMailbox:(id)arg1 intoParent:(id)arg2 withDisplayName:(id)arg3;	// IMP=0x00000000001a2a0d
- (void)_writeMailboxCache;	// IMP=0x00000000001a2694
- (id)_dictionaryForMailbox:(id)arg1;	// IMP=0x00000000001a2125
- (void)_loadEntriesFromFileSystemPath:(id)arg1 parent:(id)arg2;	// IMP=0x00000000001a11f5
- (void)_synchronizeMailboxListWithFileSystemBeforeImport;	// IMP=0x00000000001a11de
- (void)_synchronizeMailboxListWithFileSystem;	// IMP=0x00000000001a11ca
- (void)_synchronizeMailboxListWithFileSystemBeforeImport:(BOOL)arg1;	// IMP=0x00000000001a0d4b
- (BOOL)_readMailboxCache;	// IMP=0x00000000001a09bd
@property(readonly, nonatomic) BOOL usesMailboxCache;
- (void)_mailboxesWereRemovedFromTree:(id)arg1 withFileSystemPaths:(id)arg2;	// IMP=0x00000000001a093d
- (void)_loadMailboxListingIntoCache:(id)arg1 parent:(id)arg2 addedMailboxes:(id)arg3 removedMailboxes:(id)arg4 hasAllMailMailbox:(char *)arg5;	// IMP=0x000000000019f78f
- (void)_synchronouslyLoadListingForParent:(id)arg1;	// IMP=0x000000000019f789
- (id)_copyMailboxWithParent:(id)arg1 name:(id)arg2 pathComponent:(id)arg3 attributes:(unsigned long long)arg4 existingMailbox:(id)arg5;	// IMP=0x000000000019f5f4
- (void)_writeCustomInfoToMailboxCache:(id)arg1;	// IMP=0x000000000019f578
- (void)_readCustomInfoFromMailboxCache:(id)arg1;	// IMP=0x000000000019f50f
- (void)_postMailAccountsHaveChangedIfNeeded;	// IMP=0x000000000019f2ca
- (void)setIsActive:(BOOL)arg1;	// IMP=0x000000000019f068
- (void)_configureMailboxCacheEvenIfInactive:(BOOL)arg1;	// IMP=0x000000000019ef0e
- (void)messageDeliveryDidFinish:(id)arg1;	// IMP=0x000000000019d8dc
- (BOOL)discoverSettings;	// IMP=0x000000000019d853
@property(readonly) BOOL needsToDiscoverSettings;
- (void)respondToHostBecomingReachable;	// IMP=0x000000000019d7f6
@property(readonly, nonatomic) BOOL storesUnseenCount;
@property(readonly, nonatomic) BOOL supportsAppleScript;
@property(readonly, nonatomic) BOOL hasTrashMailbox;
@property(readonly, nonatomic) BOOL isGmailAccount;
@property(readonly, nonatomic) BOOL isRemoteAccount;
@property(readonly, nonatomic) BOOL isZeroConfiguration;
@property(readonly, nonatomic) BOOL providesAccountInformation;
@property(readonly, nonatomic) BOOL canParticipateInRules;
@property(readonly, nonatomic) BOOL isEditableByUser;
@property(readonly, nonatomic) BOOL synchronizesDataWithServer;
@property(readonly, copy, nonatomic) NSString *syncableURLString;
@property(readonly, copy, nonatomic) NSString *URLString;
- (id)objectSpecifier;	// IMP=0x000000000019c6fe
- (id)objectSpecifierForMailbox:(id)arg1;	// IMP=0x000000000019c563
- (id)objectSpecifierForMessageStore:(id)arg1;	// IMP=0x000000000019c501
- (id)valueInMailboxesWithName:(id)arg1;	// IMP=0x000000000019c20f
- (id)mailboxForRelativePath:(id)arg1 isFilesystemPath:(BOOL)arg2 create:(BOOL)arg3;	// IMP=0x000000000019b918
- (id)storeForMailbox:(id)arg1 createIfNeeded:(BOOL)arg2;	// IMP=0x000000000019b50f
- (id)storeForMailbox:(id)arg1;	// IMP=0x000000000019b481
@property(retain) NSError *connectionError;
- (void)accountInfoDidChange;	// IMP=0x0000000000199ecc
@property long long portNumber;
@property(copy) NSString *hostname;
@property(copy) NSString *username;
- (void)_resetAllMailboxURLs;	// IMP=0x0000000000199853
- (void)invalidateChildrenOfMailbox:(id)arg1;	// IMP=0x0000000000199839
- (void)_deleteMailboxIfEmpty:(id)arg1;	// IMP=0x0000000000199568
- (BOOL)deleteMailbox:(id)arg1 reflectToServer:(BOOL)arg2;	// IMP=0x0000000000198a2b
- (BOOL)renameMailbox:(id)arg1 newDisplayName:(id)arg2 parent:(id)arg3;	// IMP=0x0000000000197bb2
- (id)createMailboxWithParent:(id)arg1 displayName:(id)arg2 localizedDisplayName:(id)arg3;	// IMP=0x0000000000197b44
- (id)createMailboxWithParent:(id)arg1 name:(id)arg2;	// IMP=0x0000000000197ae9
@property(readonly, nonatomic) BOOL supportsNormalContainerOnlyMailboxes;
- (BOOL)canMailboxBeDeleted:(id)arg1;	// IMP=0x0000000000197a4d
- (BOOL)canMailboxBeRenamed:(id)arg1;	// IMP=0x0000000000197986
- (id)validNameForMailbox:(id)arg1 fromDisplayName:(id)arg2 error:(id *)arg3;	// IMP=0x000000000019758a
@property(readonly, nonatomic) BOOL supportsSlashesInMailboxName;
@property(readonly, nonatomic) BOOL canMoveMailboxes;
@property(readonly, nonatomic) BOOL canCreateNewMailboxes;
@property(readonly, copy, nonatomic) NSString *mailboxPathExtension;
- (BOOL)resetSpecialMailboxes;	// IMP=0x00000000001969df
@property(readonly, nonatomic) BOOL containsMailboxes;
- (id)displayNameForMailbox:(id)arg1;	// IMP=0x000000000019691a
@property(readonly, copy, nonatomic) NSString *displayName;
- (void)emptySpecialMailboxesThatNeedToBeEmptiedAtQuit;	// IMP=0x00000000001964f8
@property(readonly, nonatomic) BOOL canMoveDeletedMessagesToTrash;
@property BOOL shouldMoveDeletedMessagesToTrash;
@property(nonatomic) long long emptyTrashFrequency;
@property(nonatomic) long long emptyJunkFrequency;
- (void)setEmptySentMessagesFrequency:(long long)arg1;	// IMP=0x0000000000195d87
- (long long)emptySentMessagesFrequency;	// IMP=0x0000000000195d7a
- (void)_setEmptyFrequency:(long long)arg1 forMailDataclassProperty:(id)arg2;	// IMP=0x0000000000195c5b
- (long long)_emptyFrequencyForMailDataclassProperty:(id)arg1 defaultValue:(long long)arg2;	// IMP=0x0000000000195b7e
- (void)deleteMessagesFromMailbox:(id)arg1 olderThanNumberOfDays:(long long)arg2;	// IMP=0x0000000000195910
- (void)setToDosMailbox:(id)arg1;	// IMP=0x00000000001958f9
- (void)setArchiveMailbox:(id)arg1;	// IMP=0x00000000001958e2
@property(retain, nonatomic) MFMailbox *notesMailbox;
- (void)setSentMessagesMailbox:(id)arg1;	// IMP=0x00000000001958b4
- (void)setJunkMailbox:(id)arg1;	// IMP=0x000000000019589d
- (void)setTrashMailbox:(id)arg1;	// IMP=0x0000000000195886
- (void)setDraftsMailbox:(id)arg1;	// IMP=0x000000000019586f
- (id)allMailboxesEvenIfInactive:(BOOL)arg1;	// IMP=0x000000000019568b
@property(readonly, copy, nonatomic) NSArray *allMailboxes;
- (id)_outboxMailboxCreateIfNeeded:(BOOL)arg1;	// IMP=0x000000000019565c
- (id)archiveMailboxCreateIfNeeded:(BOOL)arg1;	// IMP=0x0000000000195641
- (id)trashMailboxCreateIfNeeded:(BOOL)arg1;	// IMP=0x00000000001955f4
- (id)sentMessagesMailboxCreateIfNeeded:(BOOL)arg1;	// IMP=0x00000000001955d9
- (id)junkMailboxCreateIfNeeded:(BOOL)arg1;	// IMP=0x00000000001955be
- (id)draftsMailboxCreateIfNeeded:(BOOL)arg1;	// IMP=0x00000000001955a3
- (id)inboxMailboxCreateIfNeeded:(BOOL)arg1;	// IMP=0x00000000001954f6
@property(readonly, nonatomic) BOOL rootChildrenCanBePromoted;
@property(readonly) BOOL rootMailboxExists;
- (BOOL)mailboxIsRootMailbox:(id)arg1;	// IMP=0x0000000000195454
@property(readonly, copy) MFMailbox *rootMailbox;
@property(readonly) MFMailbox *primaryMailbox;
@property(readonly, nonatomic) BOOL hasSyncActivity;
@property(readonly, nonatomic) BOOL isFetching;
- (void)fetchAsynchronouslyIsAuto:(BOOL)arg1;	// IMP=0x00000000001953c4
- (BOOL)shouldFetchIsAuto:(BOOL)arg1;	// IMP=0x0000000000195353
@property BOOL needsChecking;
- (void)didInitializeMailboxList;	// IMP=0x0000000000195228
- (void)willInitializeMailboxList;	// IMP=0x00000000001951de
@property(readonly) BOOL isInitializingMailboxList;
- (BOOL)_supportsMailboxListInitialization;	// IMP=0x000000000019518a
@property(readonly, nonatomic) BOOL canBeSynchronized;
@property(readonly, nonatomic) BOOL canAppendMessages;
- (void)synchronizeWithFilesystem;	// IMP=0x0000000000194eb6
@property(readonly, nonatomic) NSOperationQueue *remoteFetchQueue;
@property(readonly, nonatomic) NSOperationQueue *remoteTaskQueue;
@property(readonly, nonatomic) BOOL canFetch;
- (void)setIsWillingToGoOnline:(BOOL)arg1;	// IMP=0x0000000000194e31
- (void)setIsOffline:(BOOL)arg1;	// IMP=0x0000000000194cca
- (void)invalidateAllStores;	// IMP=0x0000000000194b00
- (void)setCacheIsDirty:(BOOL)arg1;	// IMP=0x0000000000194a0d
- (void)doRoutineCleanup;	// IMP=0x0000000000194975
- (void)saveCache;	// IMP=0x000000000019492e
- (void)_saveCacheInBackground:(id)arg1;	// IMP=0x00000000001947fc
- (void)_setCacheWriteTimer:(id)arg1;	// IMP=0x0000000000194646
- (void)deleteAccount;	// IMP=0x0000000000193e78
- (void)_synchronouslyInvalidateAndDelete:(BOOL)arg1;	// IMP=0x00000000001939ef
- (BOOL)fileManager:(id)arg1 shouldProceedAfterError:(id)arg2 removingItemAtURL:(id)arg3;	// IMP=0x00000000001939a0
- (BOOL)fileManager:(id)arg1 shouldProceedAfterError:(id)arg2 removingItemAtPath:(id)arg3;	// IMP=0x0000000000193951
- (void)promptUserForDeletionInWindow:(id)arg1 completion:(CDUnknownBlockType)arg2;	// IMP=0x00000000001938c9
- (void)setShouldAutoFetch:(BOOL)arg1;	// IMP=0x00000000001938c3
- (BOOL)shouldAutoFetch;	// IMP=0x00000000001938b8
- (void)setParentAccountDefaultAlias:(id)arg1;	// IMP=0x0000000000192861
- (BOOL)getDefaultEmailAliasDisplayName:(id *)arg1 emailAddress:(id *)arg2;	// IMP=0x00000000001921dd
@property(readonly) NSURL *emailAliasesEditingURL;
@property(readonly) BOOL emailAliasesOriginateFromParentAccount;
@property(copy) NSArray *emailAliases;
- (void)setApplescriptEmailAddresses:(id)arg1;	// IMP=0x00000000001913ed
- (id)applescriptEmailAddresses;	// IMP=0x00000000001913a4
@property(copy) NSArray *emailAddresses;
@property(readonly, copy) NSArray *rawEmailAddresses;
@property(readonly, copy) NSString *firstEmailAddress;
@property BOOL deliveryAccountIsLocked;
- (void)_mailboxUserInfoDidChange:(id)arg1;	// IMP=0x00000000001908a9
@property(retain, nonatomic) NSNumber *useMailDrop;
- (void)_deliveryAccountWillBeRemoved:(id)arg1;	// IMP=0x0000000000190726
@property(readonly, nonatomic) MFDeliveryAccount *dynamicDeliveryAccount;
@property(retain, nonatomic) MFDeliveryAccount *deliveryAccount;
@property(copy) NSString *smtpIdentifier;
@property(copy) NSString *fullUserName;
- (void)setApplescriptFullUserName:(id)arg1;	// IMP=0x000000000018ff4b
- (id)applescriptFullUserName;	// IMP=0x000000000018feff
@property(readonly, copy) NSString *tildeAbbreviatedPath;
- (BOOL)_performBlock:(CDUnknownBlockType)arg1 forMessagesFetchedWithBlock:(CDUnknownBlockType)arg2 withBatchSize:(unsigned long long)arg3;	// IMP=0x000000000018f8f0
- (void)completeDeferredInitialization;	// IMP=0x000000000018f8ea
- (void)dealloc;	// IMP=0x000000000018f85f
- (id)initWithSystemAccount:(id)arg1;	// IMP=0x000000000018f5d9
- (id)_newTaskManager;	// IMP=0x000000000018f3a4
@property(readonly) MFMailbox *allMailMailbox;
@property(readonly, nonatomic) MFMailbox *todosMailbox;
- (BOOL)mailboxIsEmpty:(id)arg1;	// IMP=0x000000000018e27b
- (BOOL)hasEmailAddress:(id)arg1;	// IMP=0x000000000018c8d6
@property(readonly, copy) NSString *backupID;
- (void)setEmptyJunkOnQuit:(BOOL)arg1;	// IMP=0x000000000018889c
- (BOOL)emptyJunkOnQuit;	// IMP=0x0000000000188880
- (void)setEmptySentMessagesOnQuit:(BOOL)arg1;	// IMP=0x000000000018887a
- (BOOL)emptySentMessagesOnQuit;	// IMP=0x0000000000188872
- (void)setEmptyTrashOnQuit:(BOOL)arg1;	// IMP=0x000000000018884c
- (BOOL)emptyTrashOnQuit;	// IMP=0x0000000000188830
- (void)insertInMailboxes:(id)arg1;	// IMP=0x000000000018881c
- (void)insertInMailboxes:(id)arg1 atIndex:(unsigned long long)arg2;	// IMP=0x0000000000188777
- (void)replaceInMailboxes:(id)arg1 atIndex:(unsigned long long)arg2;	// IMP=0x00000000001884ef
@property(readonly, copy, nonatomic) NSArray *mailboxes;
- (id)indicesOfObjectsByEvaluatingObjectSpecifier:(id)arg1;	// IMP=0x00000000001881a8

// Remaining properties
@property(readonly, copy) NSString *accountTypeString;
@property BOOL allowInsecureAuthentication;
@property(readonly, copy) NSString *appleAuthenticationToken;
@property(readonly, copy) NSString *applePersonID;
@property(copy) NSString *authenticationScheme;
@property(copy) NSString *canonicalEmailAddress;
@property BOOL configureDynamically;
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(copy) NSString *externalHostname;
@property(readonly) unsigned long long hash;
@property(readonly, copy) NSString *identifier;
@property(readonly, nonatomic) BOOL isSmartMailbox;
@property(readonly, copy) NSString *oauthToken;
@property(copy) NSString *password;
@property(retain) MCAuthScheme *preferredAuthScheme;
@property(readonly, nonatomic) BOOL requiresAuthentication;
@property(readonly, copy, nonatomic) NSString *saslProfileName;
@property long long securityLayerType;
@property BOOL shouldUseAuthentication;
@property(readonly, copy, nonatomic) NSArray *standardPorts;
@property(readonly, copy, nonatomic) NSArray *standardSSLPorts;
@property(readonly) Class superclass;
@property BOOL usesSSL;

@end

