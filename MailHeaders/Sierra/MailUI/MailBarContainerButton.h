//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSButton.h"

@interface MailBarContainerButton : NSButton
{
    BOOL _isPerformingSearchScope;	// 172 = 0xac
}

- (BOOL)shouldSetFontSmoothingBackgroundColor;	// IMP=0x00000001000346d9
@property(nonatomic) BOOL isPerformingSearchScope;
- (void)_mailBarContainerButtonCommonInit;	// IMP=0x00000001001cc538
- (id)initWithCoder:(id)arg1;	// IMP=0x00000001001cc4f3
- (id)initWithFrame:(struct CGRect)arg1;	// IMP=0x0000000100011fc9

@end

