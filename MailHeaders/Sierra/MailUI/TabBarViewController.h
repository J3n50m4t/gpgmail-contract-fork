//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSTitlebarAccessoryViewController.h"

@class ComposeWindowController, NSLayoutConstraint, NSView, NewTabButton, TabBarView;

@interface TabBarViewController : NSTitlebarAccessoryViewController
{
    TabBarView *_contentView;	// 176 = 0xb0
    NewTabButton *_createTabButton;	// 184 = 0xb8
    ComposeWindowController *_windowController;	// 192 = 0xc0
    NSView *_containerView;	// 200 = 0xc8
    NSLayoutConstraint *_containerViewTrailingLayoutConstraint;	// 208 = 0xd0
}

@property(readonly, nonatomic) NSLayoutConstraint *containerViewTrailingLayoutConstraint; // @synthesize containerViewTrailingLayoutConstraint=_containerViewTrailingLayoutConstraint;
@property(retain, nonatomic) NSView *containerView; // @synthesize containerView=_containerView;
@property(nonatomic) __weak ComposeWindowController *windowController; // @synthesize windowController=_windowController;
@property(retain, nonatomic) NewTabButton *createTabButton; // @synthesize createTabButton=_createTabButton;
- (void).cxx_destruct;	// IMP=0x00000001002ec7cb
- (void)hideNewTabButton;	// IMP=0x00000001002ec6ac
- (void)showNewTabButton;	// IMP=0x00000001002ec3f8
@property(retain, nonatomic) TabBarView *contentView;
- (void)_updateKeyViewLoop;	// IMP=0x00000001002ec212
- (void)_setUpContentView;	// IMP=0x00000001002ebf3d
- (void)viewDidLoad;	// IMP=0x00000001002ebcb9
- (void)loadView;	// IMP=0x00000001002ebbe8

@end

