#import <Cocoa/Cocoa.h>

#ifdef SNOW_LEOPARD_64

@protocol MVSelectionOwner
- (id)selection;
- (void)selectMessages:(id)arg1;
- (id)currentDisplayedMessage;
- (id)messageStore;
- (BOOL)transferSelectionToMailbox:(id)arg1 deleteOriginals:(BOOL)arg2;
@end

@protocol MessageBrowserController <NSObject, MVSelectionOwner>
- (id)messageBrowserView;
- (BOOL)isSelectionVisible;
- (void)showSelectionAndCenter:(BOOL)arg1;
- (void)updateTextViewerToSelection;
- (id)messagesToTransfer;
- (void)transfer:(id)arg1 didCompleteWithError:(id)arg2;
- (id)messageToSelectIfEntireSelectionRemoved;
- (void)selectNextMessage:(BOOL)arg1;
- (void)selectPreviousMessage:(BOOL)arg1;
- (void)selectNextMessageMovingDownward:(BOOL)arg1;
- (void)selectNextMessageMovingUpward:(BOOL)arg1;
- (BOOL)includeDeleted;
- (void)setIncludeDeleted:(BOOL)arg1;
- (BOOL)shouldDeleteGivenCurrentState;
- (void)deleteSelectionAllowingMoveToTrash:(BOOL)arg1;
- (void)deleteMessages:(id)arg1 allowMoveToTrash:(BOOL)arg2 allowUndo:(BOOL)arg3;
- (void)undeleteMessagesAllowingUndo:(BOOL)arg1;
- (void)undeleteMessages:(id)arg1 allowUndo:(BOOL)arg2;
- (void)selectMessagesForMessageTransfer:(id)arg1;
- (void)selectMessagesForMessageTransferUndo:(id)arg1;
@end

@class ASExtendedTableView;
@class MessageMall;
@class Message;
@class VisibleStateObject;
@class MessageThread;
@class BytesFormatter;

@interface TableViewManager : NSObject <MessageBrowserController, NSTableViewDelegate, NSTableViewDataSource>
{
    ASExtendedTableView *_tableView;
    MessageMall *_messageMall;
    id _delegate;
    NSArray *_tableColumns;
    NSFont *_font;
    NSFont *_boldFont;
    NSFont *_noteFont;
    NSMutableArray *_selection;
    NSArray *_selectionExcludingThreads;
    BOOL _suspendChangesToScrollingAndSelection;
    Message *_currentDisplayedMessage;
    NSMapTable *_storeStateTable;
    NSMutableArray *_draggedMessages;
    NSMutableAttributedString *_truncatedString;
    NSMutableDictionary *_truncatedStringAttributes;
    NSMutableDictionary *_truncatedParagraphStyle;
    NSString *_availableStatusImageName;
    long long leftmostTextColumn;
    struct {
        unsigned int includeDeleted:1;
        unsigned int isFocused:1;
        unsigned int sortColumnOrderAscending:1;
        unsigned int isShowingSearchResults:1;
        unsigned int sortColumnOrder:8;
        unsigned int hasScrolledSinceMailboxChange:1;
        unsigned int userChangedSelectionSinceMailboxChange:1;
        unsigned int threadOpeningIsInProgress:1;
        unsigned int threadClosingIsInProgress:1;
        unsigned int doubleClickThreadOpeningIsInProgress:1;
        unsigned int animatingThreadOpening:1;
        unsigned int animatingThreadClosing:1;
        unsigned int animateInSlowMotion:1;
        unsigned int dontUpdateTrackingRects:1;
        unsigned int dontReadWriteStoreSpecificDefaultsToMailbox:1;
        unsigned int useBoldFontForUnreadMessages:1;
        unsigned int clearingSearch:1;
        unsigned int changingSelection:1;
        unsigned int selectionShouldNotChange:1;
        unsigned int searchSortColumnOrder:8;
        unsigned int searchSortColumnOrderAscending:1;
    } _flags;
    NSDictionary *_messageIDsToSelectWhenOpened;
    NSArray *_threadIDsToOpenWhenOpened;
    long long colorHighlightLeftEdge;
    long long colorHighlightWidth;
    long long _windowWidthBeforeSearch;
    VisibleStateObject *_visibleStateBeforeSearch;
    NSMutableSet *_messagesInSelectedThread;
    MessageThread *threadBeingClosed;
    MessageThread *threadBeingOpened;
    struct __CFDictionary *_rowDrawingCache;
    NSMutableSet *_mouseTrackers;
    struct CGPoint _lastMouseDownInUnreadColumnPoint;
    long long _lastMouseDownInUnreadColumnEventNumber;
    struct CGPoint _currentMouseLocationInWindow;
    double _amountToScrollDownAfterClosingThread;
    long long _numberOfSelectedRowsBeforeTogglingThread;
    long long _selectedRowBeforeTogglingThread;
    BytesFormatter *_bytesFormatter;
    NSString *_pasteboardURLString;
    BOOL _isDragging;
}

+ (void)initialize;
- (void)awakeFromNib;
- (id)tableViewGetDefaultMenu:(id)arg1;
- (id)_bytesFormatter;
- (void)_setBytesFormatter:(id)arg1;
- (void)tableViewScrolled:(id)arg1;
- (void)_setupColumnHeaderIcon:(id)arg1 inColumnWithIdentifier:(id)arg2 accessibilityTitle:(id)arg3 alignment:(unsigned long long)arg4;
- (void)_setupTableColumnWidths;
- (void)_configureColumnForEndTruncation:(id)arg1;
- (void)_configureColumnForImageCell:(id)arg1 alignment:(unsigned long long)arg2;
- (void)_configureColumnForRolloverCell:(id)arg1 alignment:(unsigned long long)arg2 action:(SEL)arg3;
- (void)showFollowupsToMessage:(id)arg1;
- (void)showFollowupsToMessageAtRow:(long long)arg1;
- (void)_setupColumnsForTableView;
- (void)dealloc;
- (void)windowWillClose:(id)arg1;
- (id)delegate;
- (void)setDelegate:(id)arg1;
- (void)setMessageMall:(id)arg1;
- (void)messageMarkedForOverwrite:(id)arg1;
- (void)messagesUpdated:(id)arg1;
- (void)setupColumnManagerFromDictionary:(id)arg1;
- (void)readDefaultsFromDictionary:(id)arg1;
- (void)writeDefaultsToDictionary:(id)arg1;
- (void)setDontReadWriteStoreSpecificDefaultsToMailbox:(BOOL)arg1;
- (void)writeStoreSpecificDefaultsToMailboxUid:(id)arg1;
- (void)readStoreSpecificDefaultsFromMailboxUid:(id)arg1;
- (void)readStoreSpecificDefaultsFromDictionary:(id)arg1;
- (BOOL)canSelectNextMessage;
- (BOOL)canSelectPreviousMessage;
- (void)rulePreferencesChanged:(id)arg1;
- (void)viewerPreferencesChanged:(id)arg1;
- (BOOL)threadHasSelectedMessages:(id)arg1;
- (void)presencePreferenceChanged:(id)arg1;
- (void)threadColorPreferenceChanged:(id)arg1;
- (void)presenceImageChanged:(id)arg1;
- (void)presenceChanged:(id)arg1;
- (void)_updateTableHeaderToMatchCurrentSort;
- (void)tableView:(id)arg1 didClickTableColumn:(id)arg2;
- (id)_columnWithIdentifierTag:(long long)arg1;
- (id)_unreadColumn;
- (BOOL)isColumnVisible:(int)arg1;
- (void)updateDefaultsForMailboxes;
- (void)setColumn:(int)arg1 toVisible:(BOOL)arg2;
- (void)_setColumn:(int)arg1 toVisible:(BOOL)arg2;
- (BOOL)tableView:(id)arg1 shouldReorderColumn:(long long)arg2 toColumn:(long long)arg3;
- (long long)tableViewNumberOfColumnsToPinToLefthandSide:(id)arg1;
- (void)selectAllMessagesAndMakeFirstResponder;
- (void)makeMessageListFirstResponder;
- (void)updateTableViewRowHeight;
@property(retain) NSFont *font; // @synthesize font=_font;
@property(retain) NSFont *noteFont; // @synthesize noteFont=_noteFont;
- (BOOL)isInThreadedMode;
- (void)toggleThreadedMode;
- (void)threadedModeDidChange:(id)arg1;
- (void)_invalidateSelectionExcludingThreads;
- (BOOL)openThreadAtIndex:(long long)arg1 andSelectMessage:(id)arg2 animate:(BOOL)arg3;
- (BOOL)closeThreadAtIndex:(long long)arg1 focusRow:(long long)arg2 animate:(BOOL)arg3;
- (void)openAllThreads;
- (void)closeAllThreads;
- (void)toggleThread:(id)arg1;
- (void)toggleThread:(id)arg1 ignoreModifierKeys:(BOOL)arg2;
- (long long)_indexOfMessageNearest:(long long)arg1 numberOfRows:(long long)arg2 threaded:(BOOL)arg3 downward:(BOOL)arg4;
- (BOOL)canSelectPreviousThreadedMessage;
- (BOOL)canSelectNextThreadedMessage;
- (BOOL)canSelectParentOfMessage;
- (BOOL)canSelectFirstReplyToMessage;
- (BOOL)canSelectNextReplyToParent;
- (BOOL)selectionIsExactlyOneOpenThread;
- (void)selectNextMessageMovingDownward:(BOOL)arg1;
- (void)selectNextMessageMovingUpward:(BOOL)arg1;
- (BOOL)stepIntoSelectedThread;
- (BOOL)stepOutOfSelectedThread;
- (BOOL)openSelectedThread;
- (void)selectNextMessage:(BOOL)arg1;
- (void)selectPreviousMessage:(BOOL)arg1;
- (void)selectParentOfMessage;
- (void)selectFirstReplyToMessage;
- (void)selectPeer:(BOOL)arg1;
- (void)selectNextReplyToParent;
- (void)selectPreviousReplyToParent;
- (void)showSelectionAndCenter:(BOOL)arg1;
- (BOOL)isSelectionVisible;
- (void)scrollRowToVisible:(long long)arg1 position:(int)arg2;
- (long long)tableView:(id)arg1 shouldScrollRowToVisible:(long long)arg2;
- (BOOL)_isMessageInSelectedThread:(id)arg1;
- (void)_setNeedsDisplayForMessagesInSet:(id)arg1 highlightOnly:(BOOL)arg2;
- (void)_setNeedsDisplayThreadColumnForMessagesInSet:(id)arg1;
- (void)_updateSelectedThreadList;
- (id)selectedThread;
- (void)_reallyUpdateTextViewerToSelection;
- (void)updateTextViewerToSelection;
- (void)selectionIsChanging:(id)arg1;
- (void)_selectOrDeselectMembersOfThread:(id)arg1 atIndex:(long long)arg2 select:(BOOL)arg3;
- (void)selectionChanged:(id)arg1;
- (void)datesNeedRedisplay;
- (long long)numberOfRowsInTableView:(id)arg1;
- (id)_attributesForTruncatedParagraphStyle;
- (id)_messageSelectionColor;
- (id)_colorForMessage:(id)arg1 inRow:(long long)arg2 withCell:(id)arg3;
- (id)_truncatedAttributedStringForString:(id)arg1 message:(id)arg2 row:(long long)arg3 shouldIndent:(BOOL)arg4;
- (id)_attributedUpdatedStringForRSSMessage:(id)arg1 row:(long long)arg2;
- (id)tableView:(id)arg1 typeSelectStringForTableColumn:(id)arg2 row:(long long)arg3;
- (BOOL)tableView:(id)arg1 shouldTypeSelectForEvent:(id)arg2 withCurrentSearchString:(id)arg3;
- (id)tableView:(id)arg1 objectValueForTableColumn:(id)arg2 row:(long long)arg3;
- (void)_updateColorHighlightEdges;
- (void)tableView:(id)arg1 didDragTableColumn:(id)arg2;
- (void)tableViewFrameChangedDuringLiveResize:(id)arg1;
- (void)tableViewWillStartLiveResize:(id)arg1;
- (void)tableViewDidEndLiveResize:(id)arg1;
- (void)tableViewColumnDidMove:(id)arg1;
- (void)tableViewColumnDidResize:(id)arg1;
- (void)tableView:(id)arg1 willDisplayCell:(id)arg2 forTableColumn:(id)arg3 row:(long long)arg4;
- (int)tableView:(id)arg1 highlightStyleForRow:(long long)arg2 inRect:(struct CGRect *)arg3 color:(id *)arg4;
- (void)doubleClickedMessage:(id)arg1;
- (void)deleteKeyPressed;
- (void)deleteSelectionAllowingMoveToTrash:(BOOL)arg1;
- (id)selectionIncludingThreads:(BOOL)arg1;
- (id)selection;
- (void)_selectMessages:(id)arg1 scrollIfNeeded:(BOOL)arg2;
- (void)selectMessages:(id)arg1;
- (id)currentDisplayedMessage;
- (void)setCurrentDisplayedMessage:(id)arg1;
- (id)messageStore;
- (id)orderOfFromSubjectDateColumns;
- (id)tableView;
- (BOOL)tableView:(id)arg1 doCommandBySelector:(SEL)arg2;
- (id)_undoActionNameForMessageCount:(unsigned long long)arg1;
- (void)_adjustScrollPositionForTransferedMessages:(id)arg1 isUndo:(BOOL)arg2;
- (void)selectMessagesForMessageTransfer:(id)arg1;
- (void)selectMessagesForMessageTransferUndo:(id)arg1;
- (void)_undeleteMessages:(id)arg1 allowUndo:(BOOL)arg2 unreadMessages:(id)arg3;
- (void)undeleteMessages:(id)arg1 allowUndo:(BOOL)arg2;
- (void)_redeleteMessages:(id)arg1 messagesToSelect:(id)arg2;
- (void)deleteMessages:(id)arg1 allowMoveToTrash:(BOOL)arg2 allowUndo:(BOOL)arg3;
- (void)undeleteMessagesAllowingUndo:(BOOL)arg1;
- (BOOL)shouldDeleteGivenCurrentState;
- (void)tableViewDraggedImage:(id)arg1 movedTo:(struct CGPoint)arg2;
- (id)messagesToTransfer;
- (void)transfer:(id)arg1 didCompleteWithError:(id)arg2;
- (BOOL)transferSelectionToMailbox:(id)arg1 deleteOriginals:(BOOL)arg2;
- (void)tableViewDragWillEnd:(id)arg1 operation:(unsigned long long)arg2;
- (void)tableView:(id)arg1 willMouseDown:(id)arg2;
- (void)tableView:(id)arg1 didMouseDown:(id)arg2;
- (BOOL)tableView:(id)arg1 writeRowsWithIndexes:(id)arg2 toPasteboard:(id)arg3;
- (void)pasteboard:(id)arg1 provideDataForType:(id)arg2;
- (void)pasteboardChangedOwner:(id)arg1;
- (id)tableView:(id)arg1 namesOfPromisedFilesDroppedAtDestination:(id)arg2 forDraggedRowsWithIndexes:(id)arg3;
- (id)_dragImageForRow:(long long)arg1 event:(id)arg2 dragImageOffset:(struct CGPoint *)arg3;
- (id)tableView:(id)arg1 dragImageForRowsWithIndexes:(id)arg2 event:(id)arg3 dragImageOffset:(struct CGPoint *)arg4;
- (void)tableView:(id)arg1 willDrawRowsInRange:(struct _NSRange)arg2;
- (void)tableView:(id)arg1 didDrawRowsInRange:(struct _NSRange)arg2;
- (struct CGRect)frameOfClickedCell;
- (struct CGPoint)mouseLocationInWindow;
- (void)callWillDisplayCellForClickedCell;
- (void)setButtonCellNeedsDisplay;
- (void)tableView:(id)arg1 gotEvent:(id)arg2;
- (BOOL)shouldTrackMouse:(id)arg1;
- (id)tableView:(id)arg1 rangesForBackgroundShadingInRange:(struct _NSRange)arg2 shadingColors:(id *)arg3 leftColumnColors:(id *)arg4;
- (id)messageMall;
- (long long)_indexOfFirstNonDeletedNonSelectedMessage:(long long)arg1 withinRowRange:(struct _NSRange)arg2 goUp:(BOOL)arg3;
- (BOOL)_goUpInsteadOfDown;
- (id)messageBrowserView;
- (id)messageToSelectIfEntireSelectionRemoved;
- (BOOL)includeDeleted;
- (void)setIncludeDeleted:(BOOL)arg1;
@property(retain) NSFont *boldFont; // @synthesize boldFont=_boldFont;
@property(retain) NSString *pasteboardURLString; // @synthesize pasteboardURLString=_pasteboardURLString;
@property(copy) NSArray *draggedMessages; // @synthesize draggedMessages=_draggedMessages;

@end

@interface TableViewManager (AppleScript)
+ (id)_getDarkerThreadBackgroundColorForThread:(id)arg1;
+ (id)_getThreadBackgroundColorForThread:(id)arg1;
- (int)_columnForAppleScriptColumn:(int)arg1;
- (int)appleScriptSortColumn;
- (void)setAppleScriptSortColumn:(int)arg1;
- (id)appleScriptVisibleColumns;
- (void)setAppleScriptVisibleColumns:(id)arg1;
@end

@interface TableViewManager (FilteredList_Management)
- (void)mallStructureWillChange:(id)arg1;
- (void)setMailboxUids:(id)arg1 isSettingUpUI:(BOOL)arg2;
- (void)storeStructureChanged:(id)arg1;
- (void)messagesCompacted:(id)arg1;
- (void)messageFlagsChanged:(id)arg1;
- (void)_scrollToHappyPlace;
- (void)_recordVisibleState:(id)arg1 deletedAreGoingAway:(BOOL)arg2 considerPinToEnd:(BOOL)arg3;
- (BOOL)_restoreVisibleState:(id)arg1 forceSelToVisible:(BOOL)arg2;
- (void)dumpVisibleState;
- (long long)indexOfTopmostVisibleMessageMustBeSelected:(BOOL)arg1 okayIfDeleted:(BOOL)arg2;
- (long long)indexOfLastReadMessage;
- (id)persistentVisibleStateCreateIfNecessary:(BOOL)arg1;
- (void)_saveScrollAndSelection:(BOOL)arg1;
- (void)saveScrollAndSelection;
- (BOOL)restoreScrollAndSelection;
- (void)_setScrollAndSelectionForThreadOpenedOrClosed:(id)arg1 flag:(BOOL)arg2 clickedRow:(long long)arg3 rowToSelectInOpeningThread:(long long)arg4;
- (id)selectedMessageIDs;
- (id)openThreadIDs;
- (void)setSelectedMessageIDs:(id)arg1 openThreadIDs:(id)arg2;
- (void)clearSearch;
- (BOOL)isShowingSearchResults;
- (BOOL)rankColumnIsVisible;
- (void)searchForString:(id)arg1 in:(int)arg2 withOptions:(int)arg3;
- (BOOL)isFocused;
- (void)setFocusedMessages:(id)arg1;
- (BOOL)isSortedByRank;
- (BOOL)isSortedByDateReceived;
- (BOOL)isSortedChronologically;
- (int)sortColumn;
- (int)searchSortColumn;
- (void)setSortColumn:(int)arg1 ascending:(BOOL)arg2;
- (BOOL)isSortedAscending;
- (void)setIsSortedAscending:(BOOL)arg1;
- (BOOL)isSearchSortedAscending;
- (long long)state;
- (id)filteredMessages;
- (void)clearTrackingRects;
- (void)updateTrackingRects;
- (long long)_indexOfMemberToSelectWhenOpeningThread:(id)arg1;
- (double)_getAnimationDuration:(long long)arg1;
- (id)_createHiliteImage;
- (id)_createBackgroundImage;
- (id)_createSnapshotOfRect:(struct CGRect)arg1 styleMask:(unsigned long long)arg2 backing:(unsigned long long)arg3 defer:(BOOL)arg4;
- (id)_createSnapshotOfRow:(long long)arg1 styleMask:(unsigned long long)arg2 backing:(unsigned long long)arg3 defer:(BOOL)arg4;
- (BOOL)_isRowVisible:(long long)arg1;
- (struct CGSize)_calculateTruncationAmountUsingRowHeight:(double)arg1 collapseOrExpandAmount:(double)arg2 invisibleThreadAmountAbove:(double)arg3 invisibleThreadAmountBelow:(double)arg4;
- (void)_animateThreadCollapsing:(long long)arg1 threadRow:(long long)arg2 clickedRow:(long long)arg3;
- (double)_animateThreadOpening:(id)arg1 threadMessageCount:(long long)arg2 threadRow:(long long)arg3 rowToBeSelected:(long long)arg4;
- (void)searchFinished:(id)arg1;
- (void)tableView:(id)arg1 willMoveToWindow:(id)arg2;
- (void)tableViewDidMoveToWindow:(id)arg1;
- (BOOL)selectMessageWithIDIfExists:(id)arg1;
@end

#elif defined(SNOW_LEOPARD)

@class ASExtendedTableView;
@class MessageMall;
@class Message;
@class VisibleStateObject;
@class MessageThread;
@class BytesFormatter;

@protocol MVSelectionOwner
- (id)selection;
- (void)selectMessages:(id)arg1;
- (id)currentDisplayedMessage;
- (id)messageStore;
- (BOOL)transferSelectionToMailbox:(id)arg1 deleteOriginals:(BOOL)arg2;
@end

@protocol MessageBrowserController <NSObject, MVSelectionOwner>
- (id)messageBrowserView;
- (BOOL)isSelectionVisible;
- (void)showSelectionAndCenter:(BOOL)arg1;
- (void)updateTextViewerToSelection;
- (id)messagesToTransfer;
- (void)transfer:(id)arg1 didCompleteWithError:(id)arg2;
- (id)messageToSelectIfEntireSelectionRemoved;
- (void)selectNextMessage:(BOOL)arg1;
- (void)selectPreviousMessage:(BOOL)arg1;
- (void)selectNextMessageMovingDownward:(BOOL)arg1;
- (void)selectNextMessageMovingUpward:(BOOL)arg1;
- (BOOL)includeDeleted;
- (void)setIncludeDeleted:(BOOL)arg1;
- (BOOL)shouldDeleteGivenCurrentState;
- (void)deleteSelectionAllowingMoveToTrash:(BOOL)arg1;
- (void)deleteMessages:(id)arg1 allowMoveToTrash:(BOOL)arg2 allowUndo:(BOOL)arg3;
- (void)undeleteMessagesAllowingUndo:(BOOL)arg1;
- (void)undeleteMessages:(id)arg1 allowUndo:(BOOL)arg2;
- (void)selectMessagesForMessageTransfer:(id)arg1;
- (void)selectMessagesForMessageTransferUndo:(id)arg1;
@end

@interface TableViewManager : NSObject <MessageBrowserController, NSTableViewDelegate, NSTableViewDataSource>
{
    ASExtendedTableView *_tableView;
    MessageMall *_messageMall;
    id _delegate;
    NSArray *_tableColumns;
    NSFont *_font;
    NSFont *_boldFont;
    NSFont *_noteFont;
    NSMutableArray *_selection;
    NSArray *_selectionExcludingThreads;
    BOOL _suspendChangesToScrollingAndSelection;
    Message *_currentDisplayedMessage;
    NSMapTable *_storeStateTable;
    NSMutableArray *_draggedMessages;
    NSMutableAttributedString *_truncatedString;
    NSMutableDictionary *_truncatedStringAttributes;
    NSMutableDictionary *_truncatedParagraphStyle;
    NSString *_availableStatusImageName;
    int leftmostTextColumn;
    struct {
        unsigned int includeDeleted:1;
        unsigned int isFocused:1;
        unsigned int sortColumnOrderAscending:1;
        unsigned int isShowingSearchResults:1;
        unsigned int sortColumnOrder:8;
        unsigned int hasScrolledSinceMailboxChange:1;
        unsigned int userChangedSelectionSinceMailboxChange:1;
        unsigned int threadOpeningIsInProgress:1;
        unsigned int threadClosingIsInProgress:1;
        unsigned int doubleClickThreadOpeningIsInProgress:1;
        unsigned int animatingThreadOpening:1;
        unsigned int animatingThreadClosing:1;
        unsigned int animateInSlowMotion:1;
        unsigned int dontUpdateTrackingRects:1;
        unsigned int dontReadWriteStoreSpecificDefaultsToMailbox:1;
        unsigned int useBoldFontForUnreadMessages:1;
        unsigned int clearingSearch:1;
        unsigned int changingSelection:1;
        unsigned int selectionShouldNotChange:1;
        unsigned int searchSortColumnOrder:8;
        unsigned int searchSortColumnOrderAscending:1;
    } _flags;
    NSDictionary *_messageIDsToSelectWhenOpened;
    NSArray *_threadIDsToOpenWhenOpened;
    int colorHighlightLeftEdge;
    int colorHighlightWidth;
    int _windowWidthBeforeSearch;
    VisibleStateObject *_visibleStateBeforeSearch;
    NSMutableSet *_messagesInSelectedThread;
    MessageThread *threadBeingClosed;
    MessageThread *threadBeingOpened;
    struct __CFDictionary *_rowDrawingCache;
    NSMutableSet *_mouseTrackers;
    struct CGPoint _lastMouseDownInUnreadColumnPoint;
    int _lastMouseDownInUnreadColumnEventNumber;
    struct CGPoint _currentMouseLocationInWindow;
    float _amountToScrollDownAfterClosingThread;
    int _numberOfSelectedRowsBeforeTogglingThread;
    int _selectedRowBeforeTogglingThread;
    BytesFormatter *_bytesFormatter;
    NSString *_pasteboardURLString;
    BOOL _isDragging;
}

+ (void)initialize;
- (void)awakeFromNib;
- (id)tableViewGetDefaultMenu:(id)arg1;
- (id)_bytesFormatter;
- (void)_setBytesFormatter:(id)arg1;
- (void)tableViewScrolled:(id)arg1;
- (void)_setupColumnHeaderIcon:(id)arg1 inColumnWithIdentifier:(id)arg2 accessibilityTitle:(id)arg3 alignment:(unsigned long)arg4;
- (void)_setupTableColumnWidths;
- (void)_configureColumnForEndTruncation:(id)arg1;
- (void)_configureColumnForImageCell:(id)arg1 alignment:(unsigned long)arg2;
- (void)_configureColumnForRolloverCell:(id)arg1 alignment:(unsigned long)arg2 action:(SEL)arg3;
- (void)showFollowupsToMessage:(id)arg1;
- (void)showFollowupsToMessageAtRow:(long)arg1;
- (void)_setupColumnsForTableView;
- (void)dealloc;
- (void)windowWillClose:(id)arg1;
- (id)delegate;
- (void)setDelegate:(id)arg1;
- (void)setMessageMall:(id)arg1;
- (void)messageMarkedForOverwrite:(id)arg1;
- (void)messagesUpdated:(id)arg1;
- (void)setupColumnManagerFromDictionary:(id)arg1;
- (void)readDefaultsFromDictionary:(id)arg1;
- (void)writeDefaultsToDictionary:(id)arg1;
- (void)setDontReadWriteStoreSpecificDefaultsToMailbox:(BOOL)arg1;
- (void)writeStoreSpecificDefaultsToMailboxUid:(id)arg1;
- (void)readStoreSpecificDefaultsFromMailboxUid:(id)arg1;
- (void)readStoreSpecificDefaultsFromDictionary:(id)arg1;
- (BOOL)canSelectNextMessage;
- (BOOL)canSelectPreviousMessage;
- (void)rulePreferencesChanged:(id)arg1;
- (void)viewerPreferencesChanged:(id)arg1;
- (BOOL)threadHasSelectedMessages:(id)arg1;
- (void)presencePreferenceChanged:(id)arg1;
- (void)threadColorPreferenceChanged:(id)arg1;
- (void)presenceImageChanged:(id)arg1;
- (void)presenceChanged:(id)arg1;
- (void)_updateTableHeaderToMatchCurrentSort;
- (void)tableView:(id)arg1 didClickTableColumn:(id)arg2;
- (id)_columnWithIdentifierTag:(long)arg1;
- (id)_unreadColumn;
- (BOOL)isColumnVisible:(int)arg1;
- (void)updateDefaultsForMailboxes;
- (void)setColumn:(int)arg1 toVisible:(BOOL)arg2;
- (void)_setColumn:(int)arg1 toVisible:(BOOL)arg2;
- (BOOL)tableView:(id)arg1 shouldReorderColumn:(long)arg2 toColumn:(long)arg3;
- (long)tableViewNumberOfColumnsToPinToLefthandSide:(id)arg1;
- (void)selectAllMessagesAndMakeFirstResponder;
- (void)makeMessageListFirstResponder;
- (void)updateTableViewRowHeight;
- (void)setFont:(id)arg1;
- (void)setNoteFont:(id)arg1;
- (BOOL)isInThreadedMode;
- (void)toggleThreadedMode;
- (void)threadedModeDidChange:(id)arg1;
- (void)_invalidateSelectionExcludingThreads;
- (BOOL)openThreadAtIndex:(long)arg1 andSelectMessage:(id)arg2 animate:(BOOL)arg3;
- (BOOL)closeThreadAtIndex:(long)arg1 focusRow:(long)arg2 animate:(BOOL)arg3;
- (void)openAllThreads;
- (void)closeAllThreads;
- (void)toggleThread:(id)arg1;
- (void)toggleThread:(id)arg1 ignoreModifierKeys:(BOOL)arg2;
- (long)_indexOfMessageNearest:(long)arg1 numberOfRows:(long)arg2 threaded:(BOOL)arg3 downward:(BOOL)arg4;
- (BOOL)canSelectPreviousThreadedMessage;
- (BOOL)canSelectNextThreadedMessage;
- (BOOL)canSelectParentOfMessage;
- (BOOL)canSelectFirstReplyToMessage;
- (BOOL)canSelectNextReplyToParent;
- (BOOL)selectionIsExactlyOneOpenThread;
- (void)selectNextMessageMovingDownward:(BOOL)arg1;
- (void)selectNextMessageMovingUpward:(BOOL)arg1;
- (BOOL)stepIntoSelectedThread;
- (BOOL)stepOutOfSelectedThread;
- (BOOL)openSelectedThread;
- (void)selectNextMessage:(BOOL)arg1;
- (void)selectPreviousMessage:(BOOL)arg1;
- (void)selectParentOfMessage;
- (void)selectFirstReplyToMessage;
- (void)selectPeer:(BOOL)arg1;
- (void)selectNextReplyToParent;
- (void)selectPreviousReplyToParent;
- (void)showSelectionAndCenter:(BOOL)arg1;
- (BOOL)isSelectionVisible;
- (void)scrollRowToVisible:(long)arg1 position:(int)arg2;
- (long)tableView:(id)arg1 shouldScrollRowToVisible:(long)arg2;
- (BOOL)_isMessageInSelectedThread:(id)arg1;
- (void)_setNeedsDisplayForMessagesInSet:(id)arg1 highlightOnly:(BOOL)arg2;
- (void)_setNeedsDisplayThreadColumnForMessagesInSet:(id)arg1;
- (void)_updateSelectedThreadList;
- (id)selectedThread;
- (void)_reallyUpdateTextViewerToSelection;
- (void)updateTextViewerToSelection;
- (void)selectionIsChanging:(id)arg1;
- (void)_selectOrDeselectMembersOfThread:(id)arg1 atIndex:(long)arg2 select:(BOOL)arg3;
- (void)selectionChanged:(id)arg1;
- (void)datesNeedRedisplay;
- (long)numberOfRowsInTableView:(id)arg1;
- (id)_attributesForTruncatedParagraphStyle;
- (id)_messageSelectionColor;
- (id)_colorForMessage:(id)arg1 inRow:(long)arg2 withCell:(id)arg3;
- (id)_truncatedAttributedStringForString:(id)arg1 message:(id)arg2 row:(long)arg3 shouldIndent:(BOOL)arg4;
- (id)_attributedUpdatedStringForRSSMessage:(id)arg1 row:(long)arg2;
- (id)tableView:(id)arg1 typeSelectStringForTableColumn:(id)arg2 row:(long)arg3;
- (BOOL)tableView:(id)arg1 shouldTypeSelectForEvent:(id)arg2 withCurrentSearchString:(id)arg3;
- (id)tableView:(id)arg1 objectValueForTableColumn:(id)arg2 row:(long)arg3;
- (void)_updateColorHighlightEdges;
- (void)tableView:(id)arg1 didDragTableColumn:(id)arg2;
- (void)tableViewFrameChangedDuringLiveResize:(id)arg1;
- (void)tableViewWillStartLiveResize:(id)arg1;
- (void)tableViewDidEndLiveResize:(id)arg1;
- (void)tableViewColumnDidMove:(id)arg1;
- (void)tableViewColumnDidResize:(id)arg1;
- (void)tableView:(id)arg1 willDisplayCell:(id)arg2 forTableColumn:(id)arg3 row:(long)arg4;
- (int)tableView:(id)arg1 highlightStyleForRow:(long)arg2 inRect:(struct CGRect *)arg3 color:(id *)arg4;
- (void)doubleClickedMessage:(id)arg1;
- (void)deleteKeyPressed;
- (void)deleteSelectionAllowingMoveToTrash:(BOOL)arg1;
- (id)selectionIncludingThreads:(BOOL)arg1;
- (id)selection;
- (void)_selectMessages:(id)arg1 scrollIfNeeded:(BOOL)arg2;
- (void)selectMessages:(id)arg1;
- (id)currentDisplayedMessage;
- (void)setCurrentDisplayedMessage:(id)arg1;
- (id)messageStore;
- (id)orderOfFromSubjectDateColumns;
- (id)tableView;
- (BOOL)tableView:(id)arg1 doCommandBySelector:(SEL)arg2;
- (id)_undoActionNameForMessageCount:(unsigned long)arg1;
- (void)_adjustScrollPositionForTransferedMessages:(id)arg1 isUndo:(BOOL)arg2;
- (void)selectMessagesForMessageTransfer:(id)arg1;
- (void)selectMessagesForMessageTransferUndo:(id)arg1;
- (void)_undeleteMessages:(id)arg1 allowUndo:(BOOL)arg2 unreadMessages:(id)arg3;
- (void)undeleteMessages:(id)arg1 allowUndo:(BOOL)arg2;
- (void)_redeleteMessages:(id)arg1 messagesToSelect:(id)arg2;
- (void)deleteMessages:(id)arg1 allowMoveToTrash:(BOOL)arg2 allowUndo:(BOOL)arg3;
- (void)undeleteMessagesAllowingUndo:(BOOL)arg1;
- (BOOL)shouldDeleteGivenCurrentState;
- (void)tableViewDraggedImage:(id)arg1 movedTo:(struct CGPoint)arg2;
- (id)messagesToTransfer;
- (void)transfer:(id)arg1 didCompleteWithError:(id)arg2;
- (BOOL)transferSelectionToMailbox:(id)arg1 deleteOriginals:(BOOL)arg2;
- (void)tableViewDragWillEnd:(id)arg1 operation:(unsigned long)arg2;
- (void)tableView:(id)arg1 willMouseDown:(id)arg2;
- (void)tableView:(id)arg1 didMouseDown:(id)arg2;
- (BOOL)tableView:(id)arg1 writeRowsWithIndexes:(id)arg2 toPasteboard:(id)arg3;
- (void)pasteboard:(id)arg1 provideDataForType:(id)arg2;
- (void)pasteboardChangedOwner:(id)arg1;
- (id)tableView:(id)arg1 namesOfPromisedFilesDroppedAtDestination:(id)arg2 forDraggedRowsWithIndexes:(id)arg3;
- (id)_dragImageForRow:(long)arg1 event:(id)arg2 dragImageOffset:(struct CGPoint *)arg3;
- (id)tableView:(id)arg1 dragImageForRowsWithIndexes:(id)arg2 event:(id)arg3 dragImageOffset:(struct CGPoint *)arg4;
- (void)tableView:(id)arg1 willDrawRowsInRange:(struct _NSRange)arg2;
- (void)tableView:(id)arg1 didDrawRowsInRange:(struct _NSRange)arg2;
- (struct CGRect)frameOfClickedCell;
- (struct CGPoint)mouseLocationInWindow;
- (void)callWillDisplayCellForClickedCell;
- (void)setButtonCellNeedsDisplay;
- (void)tableView:(id)arg1 gotEvent:(id)arg2;
- (BOOL)shouldTrackMouse:(id)arg1;
- (id)tableView:(id)arg1 rangesForBackgroundShadingInRange:(struct _NSRange)arg2 shadingColors:(id *)arg3 leftColumnColors:(id *)arg4;
- (id)messageMall;
- (long)_indexOfFirstNonDeletedNonSelectedMessage:(long)arg1 withinRowRange:(struct _NSRange)arg2 goUp:(BOOL)arg3;
- (BOOL)_goUpInsteadOfDown;
- (id)messageBrowserView;
- (id)messageToSelectIfEntireSelectionRemoved;
- (BOOL)includeDeleted;
- (void)setIncludeDeleted:(BOOL)arg1;
- (id)noteFont;
- (id)boldFont;
- (void)setBoldFont:(id)arg1;
- (id)font;
- (id)pasteboardURLString;
- (void)setPasteboardURLString:(id)arg1;
- (id)draggedMessages;
- (void)setDraggedMessages:(id)arg1;

@end

@interface TableViewManager (AppleScript)
+ (id)_getDarkerThreadBackgroundColorForThread:(id)arg1;
+ (id)_getThreadBackgroundColorForThread:(id)arg1;
- (int)_columnForAppleScriptColumn:(int)arg1;
- (int)appleScriptSortColumn;
- (void)setAppleScriptSortColumn:(int)arg1;
- (id)appleScriptVisibleColumns;
- (void)setAppleScriptVisibleColumns:(id)arg1;
@end

@interface TableViewManager (FilteredList_Management)
- (void)mallStructureWillChange:(id)arg1;
- (void)setMailboxUids:(id)arg1 isSettingUpUI:(BOOL)arg2;
- (void)storeStructureChanged:(id)arg1;
- (void)messagesCompacted:(id)arg1;
- (void)messageFlagsChanged:(id)arg1;
- (void)_scrollToHappyPlace;
- (void)_recordVisibleState:(id)arg1 deletedAreGoingAway:(BOOL)arg2 considerPinToEnd:(BOOL)arg3;
- (BOOL)_restoreVisibleState:(id)arg1 forceSelToVisible:(BOOL)arg2;
- (void)dumpVisibleState;
- (long)indexOfTopmostVisibleMessageMustBeSelected:(BOOL)arg1 okayIfDeleted:(BOOL)arg2;
- (long)indexOfLastReadMessage;
- (id)persistentVisibleStateCreateIfNecessary:(BOOL)arg1;
- (void)_saveScrollAndSelection:(BOOL)arg1;
- (void)saveScrollAndSelection;
- (BOOL)restoreScrollAndSelection;
- (void)_setScrollAndSelectionForThreadOpenedOrClosed:(id)arg1 flag:(BOOL)arg2 clickedRow:(long)arg3 rowToSelectInOpeningThread:(long)arg4;
- (id)selectedMessageIDs;
- (id)openThreadIDs;
- (void)setSelectedMessageIDs:(id)arg1 openThreadIDs:(id)arg2;
- (void)clearSearch;
- (BOOL)isShowingSearchResults;
- (BOOL)rankColumnIsVisible;
- (void)searchForString:(id)arg1 in:(int)arg2 withOptions:(int)arg3;
- (BOOL)isFocused;
- (void)setFocusedMessages:(id)arg1;
- (BOOL)isSortedByRank;
- (BOOL)isSortedByDateReceived;
- (BOOL)isSortedChronologically;
- (int)sortColumn;
- (int)searchSortColumn;
- (void)setSortColumn:(int)arg1 ascending:(BOOL)arg2;
- (BOOL)isSortedAscending;
- (void)setIsSortedAscending:(BOOL)arg1;
- (BOOL)isSearchSortedAscending;
- (long)state;
- (id)filteredMessages;
- (void)clearTrackingRects;
- (void)updateTrackingRects;
- (long)_indexOfMemberToSelectWhenOpeningThread:(id)arg1;
- (double)_getAnimationDuration:(long)arg1;
- (id)_createHiliteImage;
- (id)_createBackgroundImage;
- (id)_createSnapshotOfRect:(struct CGRect)arg1 styleMask:(unsigned long)arg2 backing:(unsigned long)arg3 defer:(BOOL)arg4;
- (id)_createSnapshotOfRow:(long)arg1 styleMask:(unsigned long)arg2 backing:(unsigned long)arg3 defer:(BOOL)arg4;
- (BOOL)_isRowVisible:(long)arg1;
- (struct CGSize)_calculateTruncationAmountUsingRowHeight:(float)arg1 collapseOrExpandAmount:(float)arg2 invisibleThreadAmountAbove:(float)arg3 invisibleThreadAmountBelow:(float)arg4;
- (void)_animateThreadCollapsing:(long)arg1 threadRow:(long)arg2 clickedRow:(long)arg3;
- (float)_animateThreadOpening:(id)arg1 threadMessageCount:(long)arg2 threadRow:(long)arg3 rowToBeSelected:(long)arg4;
- (void)searchFinished:(id)arg1;
- (void)tableView:(id)arg1 willMoveToWindow:(id)arg2;
- (void)tableViewDidMoveToWindow:(id)arg1;
- (BOOL)selectMessageWithIDIfExists:(id)arg1;
@end


#endif
