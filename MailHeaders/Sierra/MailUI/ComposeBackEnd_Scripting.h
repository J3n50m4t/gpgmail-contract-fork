//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "ComposeBackEnd.h"

@class NSTextStorage;

@interface ComposeBackEnd_Scripting : ComposeBackEnd
{
    NSTextStorage *_textStorage;	// 8 = 0x8
}

@property(retain, nonatomic) NSTextStorage *textStorage; // @synthesize textStorage=_textStorage;
- (void).cxx_destruct;	// IMP=0x00000001001042c9
- (BOOL)isAppleScriptMessage;	// IMP=0x0000000100104281
- (void)_coalescedConvertTextStorage;	// IMP=0x000000010010421c
- (void)_convertTextStorage;	// IMP=0x00000001001041c1
- (void)_pushTextStorage;	// IMP=0x0000000100104162
- (void)setContent:(id)arg1;	// IMP=0x00000001001040d5
- (id)content;	// IMP=0x0000000100104023

@end

