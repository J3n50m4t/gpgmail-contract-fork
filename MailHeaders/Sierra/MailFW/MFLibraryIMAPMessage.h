//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Mail/MFLibraryMessage.h>

@class MCMessageHeaders, MFIMAPAccount;

@interface MFLibraryIMAPMessage : MFLibraryMessage
{
    MCMessageHeaders *_headers;	// 88 = 0x58
}

- (void).cxx_destruct;	// IMP=0x000000000014588d
@property(readonly, nonatomic) MFIMAPAccount *account;
- (void)setDataSource:(id)arg1;	// IMP=0x0000000000145714
- (id)dataSource;	// IMP=0x00000000001456e7
- (void)setHeaders:(id)arg1;	// IMP=0x000000000014566d
- (id)headers;	// IMP=0x0000000000145592

@end

