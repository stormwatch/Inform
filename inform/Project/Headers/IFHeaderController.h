//
//  IFHeaderController.h
//  Inform
//
//  Created by Andrew Hunter on 19/12/2007.
//  Copyright 2007 Andrew Hunter. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#import "IFHeader.h"

@class IFHeaderController;
@class IFSyntaxTypes;
@class IFIntelFile;

///
/// Protocol that anything that can be a header view should implement
///
@interface NSObject(IFHeaderView)

- (void) refreshHeaders: (IFHeaderController*) controller;			// Request to refresh all of the headers being managed by a view
- (void) setSelectedHeader: (IFHeader*) selectedHeader				// Request to update the currently selected header
				controller: (IFHeaderController*) controller;

@end

///
/// Controller class used to manage the header view(s)
///
@interface IFHeaderController : NSObject

// Managing the list of headers

- (void) updateFromIntelligence: (IFIntelFile*) intel;				// Updates the headers being managed by this controller from the specified intelligence object
@property (atomic, readonly, strong) IFHeader *rootHeader;			// The root header for this controller (ie, the header that the view should display at the top level)
@property (atomic, readonly, strong) IFHeader *selectedHeader;		// The currently selected header for this controller (or nil)
@property (atomic, readonly, strong) IFIntelFile *intelFile;		// The intel file that is in use by this controller

// Managing the views being controlled

- (void) addHeaderView: (NSView*) newHeaderView;					// Adds a new header view to the list being managed by this object
- (void) removeHeaderView: (NSView*) oldHeaderView;                 // Removes a header view from the list of headings being managed by this object

@end
